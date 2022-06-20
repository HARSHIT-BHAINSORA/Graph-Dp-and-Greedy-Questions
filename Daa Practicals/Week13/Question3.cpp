#include<bits/stdc++.h>
using namespace std;

void sameProduct(int arr[] , int n)
{

    bool flag = false;
    unordered_map<int , pair<int ,int>>mp;

    for(int i = 0 ; i < n-1 ; i++)
    {
        for(int j = i+1 ; j < n ; j++)
        {
            int prod = arr[i] * arr[j];

            if(mp.find(prod) == mp.end())
            {
                mp.insert({prod , {i , j}});
            }
            else{
                auto p = mp[prod];
                cout<< arr[p.first] << " " << arr[p.second] << " and ";
                cout<< arr[i] << " " << arr[j] << endl;
                flag = true;
            }
        }
    }

    if(flag == false)
        cout<< " No Pair Found ...";
}

int main(){
    int n;
    cin >> n;
    int arr[n];

    for(int i = 0 ; i < n ; i++)
        cin>>arr[i];

    sameProduct(arr , n);    
}