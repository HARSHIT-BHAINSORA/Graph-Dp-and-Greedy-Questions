// detect Cycle in the directed graph
#include<bits/stdc++.h>
using namespace std;

bool detectCycle(vector<int>graph[] , vector<int>&vis , vector<int>&dfs , int node)
{
    vis[node] = true;
    dfs[node] = true;

    for(auto neig : graph[node])
    {
        if(!vis[neig])
        {
            return detectCycle(graph , vis , dfs , neig);
        }
        else if(dfs[neig])
            return true;
    }
    dfs[node] = false;
    return false;
}




bool checkCycle(vector<int>graph[] , int V)
{
    vector<int>vis(V , false);
    vector<int>dfs(V , false);

    for(int i = 0 ; i < V ; i++)
    {
        if(!vis[i])
        {
            if(detectCycle(graph , vis , dfs , i))
                return true;
        }
    }

    return false;
}


int main(){

    int E , V ;
    cout<<"Enter the number of Vertices = ";
    cin >> V;

    cout<<"Enter the number of Edges = ";
    cin >> E;

    vector<int>graph[V];
    int src , dest ;
     
    for(int  e = 0 ; e < E ; e++)
    {
        cin >> src >> dest ;
        graph[src].push_back(dest);
    }

    bool flag = checkCycle(graph , V);

    flag == true ? cout<<"Cycle in present ... " : cout<<"Cycle is Not Present...";
    return 0;
}