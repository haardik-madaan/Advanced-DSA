#include<bits/stdc++.h>
using namespace std;


void solve(vector<int> creams, vector<vector<int>>& ans,int k){
    vector<int> jj(k,0);
    int power = 0;

    for (int i = creams.size()-1;i>=0;i--){
        power = max(power,creams[i]);

        if(power>0){
            jj[i] = 1;
            power--;
        }
    }
    ans.push_back(jj);
  
}

int main(){
    int n;
    cin>>n;

    vector<vector<int>> ans;
    
    for (int i = 0;i<n;i++){
        int k;
        cin>>k;

        vector<int> creams;
        for(int j = 0;j<k;j++){
            int m;
            cin>>m;
            creams.push_back(m);
        }

        solve(creams, ans,k);

    }

    for(int i = 0;i<ans.size();i++){
        for (int j = 0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }

        cout<<endl;
    }
}