// Maixmum spanning tree (Prims)

#include<bits/stdc++.h>
using namespace std;

void printMst(vector<pair<int , int>> graph[] , vector<int>parent , int V)
{
    int mstCost = 0;
    for(int i = 1 ; i < V ; i++)
    {
        for(auto it : graph[i])
        {
            if(it.first == parent[i])
                mstCost += it.second;
        }
    }

    cout << "The Maximum cost is - " << mstCost <<endl;

    cout << "The edges are - "<<endl;
    for(int i = 1 ; i < V ; i++)
    {
        cout << i << " - " << parent[i] << endl;
    }
}


void primsAlgo(vector<pair<int , int>>graph[] , int V)
{
    vector<int>parent(V , -1);
    vector<bool>mst(V, false);
    vector<int>key(V,INT_MIN);

    parent[0] = 0;
    key[0] = 0;

    priority_queue<pair<int , int>>pq;
    pq.push({0 , 0});

    for(int i = 0 ; i < V- 1 ; i++)
    {
        int u = pq.top().second;
        pq.pop();

        mst[u] = true;

        for(auto it : graph[u])
        {
            int v = it.first;
            int w = it.second;
            
            if(mst[v] == false && w > key[v])
            {
                key[v] = w;
                parent[v] = u;
                pq.push({key[v] , v});
            }
        }
    }

    printMst(graph , parent , V);

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

    primsAlgo(graph , V);
}
