// 0 1 Knapsack

#include<bits/stdc++.h>
using namespace std;

int knapsack(int weg[] , int value[] , int n , int W)
{
    int dp[n+1][W+1];

    for(int i = 0 ; i < n+1 ; i++)
    {
        for(int j = 0 ; j < W+1 ; j++)
        {
            if(i == 0 || j == 0)
                dp[i][j] = 0;
        }
    } 

    for(int i = 1 ; i < n+1 ; i++)
    {
        for(int j = 1 ; j < W+1 ; j++)
        {
            if(weg[i-1] <= j)
            {
                dp[i][j] = max( value[i-1]+dp[i-1][j-weg[i-1]] , dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][W];
}

int main(){
    int n ;
    cin>> n;

    int weg[n];
    int value[n];

    for(int i = 0 ; i < n ; i++)
        cin>>weg[i];

    for(int j = 0 ; j < n ; j++)
        cin>>value[j];

    int W;
    cout<<"Enter the Capacity of Knapsack";
    cin>>W;    

    int maxWeg = knapsack(weg , value , n , W);
    cout<<"Value is - " << maxWeg;
    return 0;
}