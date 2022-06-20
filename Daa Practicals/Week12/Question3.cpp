// All Possible permutation.
#include<bits/stdc++.h>
using namespace std;

map<char , int>mp;
set<vector<char>>seet;

void permutation(string s , vector<char>&ans)
{
    if(mp.size() == s.length())
    {
        seet.insert(ans); //store
        return ;
    }

    for(int i = 0 ; i < s.size() ; i++)
    {
        if(!mp[s[i]]){
            
            //pick
            ans.push_back(s[i]);
            mp[s[i]] = 1;

            permutation(s , ans); //call

            // Backtracking
            mp.erase(s[i]);
            ans.pop_back();            
        }
    }
}


int main(){
    string s;
    cout<< "Enter any String = ";
    cin>>s;

    vector<char>ans;
 
    permutation(s , ans);

    for(auto it : seet)
    {
        for(auto i : it){
            cout<< i <<" "; 
        }
        cout<<endl;
    }

    return 0;
}