// Equal sum Problem

#include<bits/stdc++.h>
using namespace std;


bool knapsack(int arr[] , int n , int W)
{
    bool dp[n+1][W+1];

    for(int i = 0 ; i < n+1 ; i++)
    {
        for(int j = 0 ; j < W+1 ; j++)
        {
            if(i == 0)
                dp[i][j] = false;
            if(j == 0)
                dp[i][j] = true;    
        }
    }


    for(int i = 1 ; i < n+1 ; i++)
    {
        for(int j = 1 ; j < W+1 ; j++)
        {
            if(arr[i-1] <= j)
            {
                dp[i][j] = (dp[i-1][j-arr[i-1]] || dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][W];
}


int main(){

    int n;
    cin>>n;

    int arr[n];
    for(int i = 0 ; i < n ;i++)
        cin>>arr[i];

    int sum = 0;

    for(int i = 0 ; i < n ; i++)
    {
        sum += arr[i];
    }

    cout<< sum << endl;

    if(sum % 2 != 0)
        cout<<"no";    

    else if(sum % 2 == 0)
    {
        bool flag = knapsack(arr , n , sum/2);
        flag == true ? cout<<"yes" : cout<<"no";
    }
    return 0;
}
 