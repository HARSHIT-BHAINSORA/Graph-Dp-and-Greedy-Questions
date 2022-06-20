#include<bits/stdc++.h>
using namespace std;

# define n 4
# define INF 99999

int kPath(int graph[n][n] , int k, int src , int dest)
{
   if (k == 0 && src == dest)             return 0;
   if (k == 1 && graph[src][dest] != INF) return graph[src][dest];
   if (k <= 0)                       return INF;

    int res = INF;

    for(int i = 0 ; i < n ; i++)
    {
        if(graph[src][i] != INF && src != i && dest != i){
            int rresult = kPath(graph , k-1 , i , dest);

            if(rresult != INF)
                res = min(res , graph[src][i] + rresult);
        }
         
    }

    return res;
    
}

int main(){
    int graph[n][n] = {{0, 5 , 4 , 4},
    {INF , 0 , INF , 2},
    {INF , INF , 0 , 5},
    {INF , INF , INF, 0}};

    int k ,src ,dest;
    cout<<"Enter  the value of k - ";
    cin>>k;

    cout<< "Enter the source -";
    cin>>src;

    cout<<"Enter the destination - ";
    cin>>dest;

    cout << "Result is-  " << kPath(graph , k ,src ,dest);
}
