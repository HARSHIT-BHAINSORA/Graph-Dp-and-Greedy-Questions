#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    
    int profit[n]; 
    for(int i = 0 ; i < n ;i++)
        cin>>profit[i];

    int dline[n];
    for(int i = 0 ; i < n ;i++)
        cin>>dline[i];

    int m = 0;
    for(int i = 0 ; i < n ; i++)
    {
        m = max(m , dline[i]);
    }

    vector<int>ans(m , -1);

    priority_queue<pair<int , pair<int , int>>>pq;

    for(int i = 0 ; i < n ; i++)
    {
        pq.push({profit[i] , {dline[i] , i+1}});
    }

    int count = 0;
    while(!pq.empty())
    {
        int j = pq.top().second.second;
        int p = pq.top().first;
        int dline = pq.top().second.first;
        pq.pop();

        for(int i = dline-1 ; i >=0 ; i--)
        {
            if(ans[i] == -1){
                ans[i] = j;
                count++;
                break;
            }
        }
    }    
    
    cout<< "No. of jobs done -" << count<<endl;
    cout << "JOB are - ";
    for(auto it :ans)
        cout<< it <<" ";

}   