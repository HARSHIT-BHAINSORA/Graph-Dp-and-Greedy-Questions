// majority Element

#include<bits/stdc++.h>
using namespace std;


int main(){
    
    int n;
    cin>>n;

    int arr[n];

    for(int i = 0 ; i < n ; i++)
    {
        cin >> arr[i];
    }
    
    int candidate ;
    int count = 0;
    int cnt = 0;
    
    for(int i = 0 ; i < 5 ; i++)
    {
        if(count == 0){
            candidate = arr[i];
            count++;
        }    
        else if(candidate != arr[i])
            count--;
        else 
            count++;
    }
    
    for(int i = 0 ; i < n ; i++)
    {
        if(candidate == arr[i])
            cnt++;
    }
    
    if(cnt > n /2)
        cout<< "Yes " << candidate;
    else
        cout<<"No";
}