// detect cycle in Undirected graph

#include<bits/stdc++.h>
using namespace std;

bool detectCycle(vector<int>graph[] , vector<bool> &vis , int node , int pnode)
{
    // queue<pair<int , int>>q;
    // q.push({node , -1});
    // vis[node] = true;

    // while(!q.empty())
    // {
    //     int node = q.front().first;
    //     int pnode = q.front().second;
    //     q.pop();

    //     for(auto neig : graph[node])
    //     {
    //         if(!vis[neig])
    //         {
    //             vis[neig] = true;
    //             q.push({neig , node});
    //         }
    //         else if(neig != pnode)
    //             return true;
    //     }
    // }


    vis[node] = true;

    for(auto neig : graph[node])
    {
        if(!vis[neig])
        {
            return detectCycle(graph , vis , neig , node);
        }
        else if(neig != pnode)
            return true;
    }


    return false;
}

bool chechCycle(vector<int> graph[] , int V)
{
    vector<bool>vis(V , false);

    for(int i = 0 ; i < V ; i++)
    {
        if(!vis[i])
        {
            return detectCycle(graph , vis , i , -1);
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
        graph[dest].push_back(src);
    }

    bool flag = chechCycle(graph , V);
    flag == true ? cout<<"Cycle is Present ..." : cout<<"Cycle is Not Present ...";
    return 0;

}    