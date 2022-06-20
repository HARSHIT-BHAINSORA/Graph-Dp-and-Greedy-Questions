#include<bits/stdc++.h>
using namespace std;

int main(){

    string s;
    cout<<"Enter an String = ";
    cin>>s;

    map<char , int>mp;

    for(int i = 0 ; i < s.length() ; i++)
    {
        mp[s[i]]++;
    } 

    for(auto it : mp)
    {
        cout<<it.first << " - " << it.second<<endl;
    }
}