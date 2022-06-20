// fractional Knapsack (greedy approach)

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    int weg[n];
    int val[n];
    float pRw[n];

    for(int i = 0 ; i < n ; i++)
        cin >> weg[i];

    for(int i = 0 ; i < n ; i++)
        cin >> val[i];

    // value/weg max - pick those.

    for(int i = 0 ; i < n ; i++)
    {
        pRw[i] = (float) val[i] / weg[i];
    }
 
    int W;
    cout<< "Enter the Capicaity = ";
    cin>>W;

    priority_queue<pair<float, pair<int , int>>>maxheap;

    for(int i = 0 ; i < n ; i++)
    {
        maxheap.push({pRw[i] , {weg[i] , val[i]}});
    }

    float maxProfit = 0.0;

    while(!maxheap.empty())
    {
        float pw = maxheap.top().first;
        int w = maxheap.top().second.first;
        int p = maxheap.top().second.second;

        maxheap.pop();

        cout<< w << " ";
        cout << W <<endl;

        if(W > 0 && w <= W)
        {
            W -= w;
            maxProfit +=p; 
        }
        else if(W > 0)
        {
            maxProfit +=  (float) W * pw;
            cout<<"The Maximum value is - " << maxProfit;
            return 0;
        }
    }
    cout<<"The Maximum value is - " << maxProfit;
    return 0;
}