


#include<bits/stdc++.h>
using namespace std;
int dp[11][2][11];

int solve(string str, int idx, bool tight, bool cnt){

   if(idx==str.size()){
    return cnt;
   }

    if(dp[idx][tight][cnt] != -1) return dp[idx][tight][cnt];


    int limit = (tight == 1 ? str[idx] - '0': 9);
    int ans = 0;

    for (int i = 0;i<=limit;i++){   
        ans+=solve(str,idx+1, tight & (i == str[idx]-'0'),cnt || (i==3));
    }

    return dp[idx][tight][cnt] = ans;

}

int main(){

    int num;
    cin>>num;

    for (int i = 0;i<num;i++){
        int n;
    cin>>n;

    string q = to_string(n);

    memset(dp,-1,sizeof(dp));

    int a = solve(q,0,1,0);

    cout<<n-a;
    }
    

}