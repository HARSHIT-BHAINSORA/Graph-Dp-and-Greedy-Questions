// floyd Warshall algo 

#include<bits/stdc++.h>
using namespace std;

# define n 5 // size;
# define INF 99999


void printFun(int dp[n][n])
{
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            if(dp[i][j] == INF)
                cout<<"INF" << "  ";
            else
                cout<<dp[i][j] << "  ";
        }
        cout<< endl;
    }
}

void floydWarshall(int graph[][n])
{
    int dp[n][n];
    int i , j , k;

    for(i = 0 ; i < n ; i++)
    {
        for(j = 0 ; j < n ; j++)
        {
            dp[i][j] = graph[i][j];
        }
    }

    for(k = 0 ; k < n ; k++)
    {
        for(i = 0 ; i < n ;i++)
        {
            for(j = 0 ; j < n ;j++)
            {
                if(dp[i][j] > (dp[i][k] + dp[k][j]) && (dp[i][k] != INF) && (dp[k][j] != INF))
                    dp[i][j] = dp[i][k] + dp[k][j];
            }
        }
    }

    printFun(dp);
}

int main(){

    int graph[5][5]={{0 , 10 , 5 , 5, INF},
    {INF , 0 , 5, 5, 5},
    {INF , INF , 0 , INF , 10},
    {INF , INF, INF , 0 , 20},
    {INF , INF ,INF , 5 ,0}};

    floydWarshall(graph);
    return 0;
}