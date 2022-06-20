#include<bits/stdc++.h>
using namespace std;

bool Window(int arr[] , int n , int k)
{
    int st=0 , end = 0;
    unordered_map<int , int >mp;

    while(end < n)
    {
        if(mp.find(arr[end]) != mp.end())
            return true;
        mp[arr[end]]++;

        if(end-st+1 < k )
            end++;
        else if(end-st+1 == k)
        {
            mp[arr[st]]--;
            if(mp[arr[st]] == 0)
                mp.erase(arr[st]);

            end++;
            st++;    
        }        
    }

    return false;
}


int main(){
    int n , k;
    cin>>n;

    int arr[n];
    for(int i = 0 ; i < n ; i++)
        cin>>arr[i];

    cout<< "Enter the value of K - ";
    cin>>k;

    bool flag = Window(arr , n , k);

    flag == true ? cout<<"Duplicate present in Window "<< k : cout<<"Duplicate Not present in Window "<<k;
    return 0;     
}
