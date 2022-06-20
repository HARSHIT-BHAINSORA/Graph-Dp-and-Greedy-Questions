// Kruskal's Algo

#include<bits/stdc++.h>
using namespace std;


int findPar(int node , vector<int> &parent)
{
    if(node == parent[node])
        return node;
    return findPar(parent[node] , parent);    
}

void unionn(int x , int y , vector<int>&parent , vector<int>&rank)
{
    x = findPar(x , parent);
    y = findPar(y , parent);

    if(x == y)
        return ;

    if(rank[x] > rank[y])
        parent[y] = x;
    else if(rank[y] > rank[x])
        parent[x] = y;
    else{
        parent[x]= y;
        rank[y]++;
    }            
}

int main(){
    int E , V ;
    cout<<"Enter the number of Vertices = ";
    cin >> V;

    cout<<"Enter the number of Edges = ";
    cin >> E;

    vector<pair<int , pair<int  , int >>>edges;
    int src , dest, weg ;
     
    for(int  e = 0 ; e < E ; e++)
    {
        cin>>weg;
        cin>>src;
        cin>>dest;
       
        edges.push_back({weg , {src , dest}});
    }
    sort(edges.begin() , edges.end());


    vector<int>parent(V);
    vector<int>rank(V,0);

    for(int i = 0 ; i < V ; i++)
        parent[i] = i;

    
    vector<pair<int , int >>mst;
    int cost = 0;

    for(auto it : edges)
    {
        if(findPar(it.second.first , parent) != findPar(it.second.second , parent))
        {
            cost += it.first;
            mst.push_back({it.second.first , it.second.second});
            unionn(it.second.first , it.second.second , parent , rank);
        }
    }

    cout<< "The minimum cost is - " <<cost << endl;

    cout<<"The mst edges are - "; 
    for(auto it : mst)
    {
        cout<< it.first << "-" << it.second <<endl;
    }

    return 0;
}