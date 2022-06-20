// Prims Algo. (mSpanning tree)

#include<bits/stdc++.h>
using namespace std;


void PrimsAlgo(vector<pair<int,int>>graph[] , int V)
{
    vector<int>parent(V , -1);
    vector<bool>mst(V, false);
    vector<int>key(V, INT_MAX);

    parent[0] = 0;
    key[0] = 0;

    priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>>pq;
    pq.push({0 , 0});

    for(int i = 0 ; i < V-1 ; i++)
    {
        int u = pq.top().second;
        pq.pop();
        
        mst[u] = true;

        for(auto neig : graph[u])
        {
            int v = neig.first;
            int w = neig.second;

            if(mst[v] == false && key[v] > w ){
                parent[v] = u;
                key[v] = w;
                pq.push({key[v] , v});
            }
        }
    }
    
    for(int i = 0 ; i < V ; i++)
        cout << i << " parent is - " << parent[i]<<endl;
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

    PrimsAlgo(graph , V );
    return 0;
} 

