// Bipartite graph or not with bfs.

#include<bits/stdc++.h>
using namespace std;

void addEdges(vector<int>adjList[] , int src , int dest)
{
    adjList[src].push_back(dest);
    adjList[dest].push_back(src);
}

void printGraph(vector<int>adjList[] , int V){
    for(int v = 0 ; v < V ; v++)
    {
        cout<<"The node is = " << v<<endl;
        cout<<"The neighbours are = ";  
        for(auto neig : adjList[v])
        {
            cout<< neig << " ";
        }
        cout<<endl;
    }
}

bool bipartitebfs(vector<int>adjList[] , vector<int>&color , int node , int V)
{
    queue<int>q;
    q.push(node);
    color[node] = 1;

    while(!q.empty())
    {
        int srcnode = q.front();
        q.pop();

        for(auto neig : adjList[srcnode])
        {
            if(color[neig] == -1)
            {
                color[neig] = 1 - color[srcnode];
                q.push(neig);
            }
            else if(color[neig] == color[srcnode])
            {
                return false;
            }
        }
    }

    for(int i = 0 ; i < V ; i++)
    {
        cout<< color[i]<< " ";
    }

    return true;
}


bool checkBipartite(vector<int> adjList[] , int V){

    vector<int>color(V , -1);

    for(int i = 0 ; i < V ; i++)
    {
        if(color[i] == -1)
        {
            if(!bipartitebfs(adjList , color , i , V))
                return false;
        }
    }

    return true;

}

int main(){
    int V , E;

    cout<< "Enter the number of Vertices = ";
    cin >> V;

    cout<<"Enter the number of Edges  = ";
    cin >> E;

    int src , dest ;

    vector<int>adjList[V];

    for(int e = 0 ; e < E ; e++)
    {
        cin>>src;
        cin>>dest;

        addEdges(adjList , src , dest);
    }

    printGraph(adjList , V);

    if(checkBipartite(adjList , V))
        cout<< "Is a Bipartite Graph";
    else
        cout<<"Not a Bipartite Graph";    
    return 0;
}