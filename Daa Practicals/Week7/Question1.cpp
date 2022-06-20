// Dijkstar's Algo. -> (shortest Path nikal na hota hai tho ).

#include<bits/stdc++.h>
using namespace std;

void dijkstarAlgo(vector<pair<int,int>>graph[] , int V , int src)
{
    vector<int>dis(V , INT_MAX);
    priority_queue<pair<int , int > , vector<pair <int , int>> , greater<pair<int , int>>> pq;
    
    pq.push({0 , src});
    dis[src] = 0;

    while(!pq.empty())
    {
        int mdis = pq.top().first;
        int pnode = pq.top().second;

        pq.pop();


        for(auto it : graph[pnode])
        {
            int nnode = it.first;
            int ndis = it.second;

            if(dis[nnode] > dis[pnode] + ndis)
            {
                dis[nnode] = dis[pnode] + ndis;
                pq.push({dis[nnode] , nnode});
            }
        }

    }

    for(int i = 0 ; i < V ; i++)
    {
        cout << src << " to " << i << "   - "<<  dis[i] <<endl;   
    }

}

int main(){
    int E , V ;
    cout<<"Enter the number of Vertices = ";
    cin >> V;

    cout<<"Enter the number of Edges = ";
    cin >> E;

    vector<pair<int , int>>graph[V];
    int src , dest, weg ;
     
    for(int  e = 0 ; e < E ; e++)
    {
        cin >> src >> dest >> weg ;
        graph[src].push_back({dest , weg});
        graph[dest].push_back({src , weg});
    }

    int source;
    cout<< "Enter the Source - ";
    cin>>source;
    dijkstarAlgo(graph , V , source);
    return 0;
}    