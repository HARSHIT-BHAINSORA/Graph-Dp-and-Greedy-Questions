// Find the Mother Node 

#include<bits/stdc++.h>
using namespace std;


void printGraph(vector<int>graph[] , int V)
{
    for(int ver = 0 ; ver < V ; ver++)
    {
        cout<<"The Node is = " << ver << endl;
        cout<< "The Neighbours are - " ;
        for(auto neig : graph[ver])
        {
            cout<< neig << " " ;
        }
        cout<<endl;
    }
}


void dfs(vector<int>graph[] , int node , vector<int>&vis)
{
    vis[node] = 1;

    for(auto neig : graph[node])
    {
        if(vis[neig] == 0)
        {
            dfs(graph , neig , vis);
        }
    }
}

int findMother(vector<int>graph[] , int V)
{
    vector<int>vis(V , 0);

    int mom;
    for(int i = 0 ; i < V ; i++)
    {
        if(vis[i] == 0){
            mom = i;
            dfs(graph , i , vis);
        }
    }

    fill(vis.begin() , vis.end() , 0);
    dfs(graph , mom , vis);

    for(int i = 0 ; i < V ; i++)
    {
        if(vis[i] == 0)
            return -1;
    }
    return mom;
}

int main(){

    int V , E;

    cout<<"Enter the number of Vertices = ";
    cin >> V;

    cout<<"Enter the number of edges = ";
    cin>>E;

    vector<int>graph[V];
    int src , dest;

    for(int e = 0 ; e < E ; e++)
    {
        cin >> src >> dest;
        graph[src].push_back(dest);
    }

    printGraph(graph , V);

    int mom = findMother(graph , V);

    mom == -1 ? cout<< "Mother is Not Present" : cout<< "Mother node is = " << mom;
    return 0;
}