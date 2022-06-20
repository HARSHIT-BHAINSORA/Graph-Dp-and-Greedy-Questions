// Longest Common Subsequence

#include<bits/stdc++.h>
using namespace std;

int lcs(string X , string Y , int n , int m)
{
    int dp[n+1][m+1];

    for(int i = 0 ; i < n+1 ; i++)
    {
        for(int j = 0 ; j < m+1 ; j++)
        {
            if(i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }

    for(int i = 1 ; i < n+1 ; i++)
    {
        for(int j = 1 ; j < m+1 ; j++)
        {
            if(X[i-1] == Y[j-1])
            {
                dp[i][j] = 1+dp[i-1][j-1]; 
            }
            else {
                dp[i][j] = max(dp[i][j-1] , dp[i-1][j]);
            }
        }
    }

    return dp[n][m];
}

int main(){

    string X = "";
    string Y = "";

    cout<<"Enter the first String = ";
    cin>>X;

    cout<<"Enter the Second String = ";
    cin>>Y;

    int n = X.length();
    int m = Y.length();

    if(n == 0 || m == 0)
    {
        cout<<"No lcs Present....";
        return 0;
    }

    int len = lcs(X , Y , n , m);     
    len == 0 ? cout<<"No lcs Present" : cout << "lcs Present of length = "<<len;
    return 0;
}