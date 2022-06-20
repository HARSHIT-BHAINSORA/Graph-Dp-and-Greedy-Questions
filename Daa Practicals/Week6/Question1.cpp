// Is Path Exists

#include<bits/stdc++.h>
using namespace std;


bool isPath(vector<int>adjList[] , vector<bool>&visited , int src , int dest)
{
    visited[src] = true;

    if(src == dest)
        return true;

    for(auto neig : adjList[src])
    {
        if(!visited[neig])
        {
            if(isPath(adjList , visited , neig , dest))
                return true;
        }
    } 

    return false;       
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
        adjList[src].push_back(dest);
        adjList[dest].push_back(src);
    }

    int source , destination;
    cout<<"Enter the source And destination - ";
    cin>>source >> destination;

    vector<bool>visited(V , false);

    bool flag = isPath(adjList , visited, source , destination);

    flag == true ? cout<< "Yes , Path Exists..." : cout<<"No, Such Path Exists..."; 
    
    return 0;
}