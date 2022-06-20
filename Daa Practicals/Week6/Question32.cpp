// detect cycle in directed graph using bfs 

#include<bits/stdc++.h>
using namespace std;
 vector<int>ans;
bool checkCycle(vector<int>graph[] , int V)
{
    queue<int> q;
    vector<int>indegree(V , 0);
    int vCount = 0;
   
    // indgree store
    for(int i = 0 ; i < V ; i++)
    {
        for(auto it : graph[i])
        {
            indegree[it]++;
        }
    }

    // push zero indegree ones
    for(int i = 0 ; i <V ; i++)
    {
        if(indegree[i] == 0)
            q.push(i);
    }

    while(!q.empty())
    {
        int node = q.front();
        vCount++;
        q.pop();

        for(auto it :graph[node])
        {
            indegree[it]--;
            if(indegree[it] == 0)
                q.push(it);
        }
    }
    return vCount == V ? false : true;
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