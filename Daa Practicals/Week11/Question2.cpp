// Coin Change Problem (No. of Ways)

#include<bits/stdc++.h>
using namespace std;

int coinChange(int coin[] , int n , int N)
{
    int dp[n+1][N+1];

    for(int i = 0 ; i < n+1 ; i++)
    {
        for(int j = 0 ; j < N+1 ; j++)
        {
            if(i == 0)
                dp[i][j] = 0;
            else if(j == 0)
                dp[i][j] = 1;    
        }
    }

    for(int i = 1 ; i < n+1 ; i++)
    {
        for(int j = 1 ; j < N+1 ; j++)
        {
            if(coin[i-1] <= j)
            {
                dp[i][j] = dp[i][j-coin[i-1]] + dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][N];
}


int main()
{
    int n ;
    cin >> n;

    int coin[n];

    for(int i = 0 ; i < n ; i++)
        cin>>coin[i];

    int N;
    cout<<"Enter the Sum - ";
    cin >> N; 

    int ways = coinChange(coin , n , N);   
    cout<<"The Number of Ways = "<<ways;
}

