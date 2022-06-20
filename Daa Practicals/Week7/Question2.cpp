#include<bits/stdc++.h>
using namespace std;


void bellmanFord(vector<pair<int ,pair<int ,int>>>edges , int V , int src){

    int inf = 1000000;
    vector<int>dis(V , inf);

    dis[src] = 0;

    for(int i = 0 ; i < V-1 ;  i++)
    {
        for(auto it : edges)
        {
            if(dis[it.second.first] > dis[it.first] + it.second.second)
            {
                dis[it.second.first] = dis[it.first] + it.second.second;
            }
        }
    } 

    int flag = 0 ;
    
    for(auto it : edges)
    {
        if(dis[it.second.first] > dis[it.first] + it.second.second)
        {
            cout<<"Negative edges found ....";
            flag = 1;
            break;       
        }
    }

    if(!flag)
    {
        for(int i = 0 ; i < V ; i++)
        {
            cout << src << " to " << i << "   - "<<  dis[i] <<endl;  
        }
    }
}

int main(){
    int E , V ;
    cout<<"Enter the number of Vertices = ";
    cin >> V;

    cout<<"Enter the number of Edges = ";
    cin >> E;

    vector<pair<int ,pair<int , int>>>edges;
    int src , dest, weg ;
     
    for(int  e = 0 ; e < E ; e++)
    {
        cin >> src >> dest >> weg ;
        edges.push_back({src , {dest , weg}});
    }

    int source;
    cout<< "Enter the Source - ";
    cin>>source;
    bellmanFord(edges , V , source);
    return 0;
}    