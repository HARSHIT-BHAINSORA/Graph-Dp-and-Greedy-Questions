// Activity selection
// sort on the basis of final time

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; 
    cin >> n;
    int sTime[n];
    int fTime[n];

    for(int i = 0 ; i < n ; i++)
        cin>>sTime[i];

    for(int i = 0 ; i < n ; i++)
        cin>>fTime[i];

    vector<pair<int , pair<int , int>>>act;

    for(int i = 0 ; i < n ; i++)
    {
        act.push_back({fTime[i] , {sTime[i] , i+1}});
    }    

    sort(act.begin() , act.end());

    int count = 0;
    vector<int>ans;

    for(auto it : act)
    {
        int f = it.first;
        int s = it.second.first;
        int act = it.second.second;

        int prevF;

        if(count == 0)
        {
            ans.push_back(act);
            prevF = f;
            count++;
        }
        else if(prevF < s)
        {
            ans.push_back(act);
            prevF = f;
            count++;
        }
    }

    cout << " No. of Non-Confliciting act - " << count << endl ;
    for(auto it : ans)
    {
        cout << it << " , ";
    }
    return 0;
}
