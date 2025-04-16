//problem statement ---> You are give a number 'n', you have to count the number of 1's occuring from 0 to n. 


#include<bits/stdc++.h>
using namespace std;
int dp[10][2][10];

int solve(string str, int idx, bool tight, int cnt){
    if(idx == str.size()){
        return cnt;
    }

    if(dp[idx][tight][cnt]!=-1) return dp[idx][tight][cnt];

    int limit = (tight == 1 ? str[idx]-'0' : 9);
    int ans = 0;

    for (int i = 0;i<=limit;i++){
        ans += solve(str,idx+1,tight && (i == str[idx]-'0'),cnt + (i == 1 ? 1 : 0));
    }

    return dp[idx][tight][cnt] = ans;

}

int main(){
    int n;
    cin>>n;
    string num = to_string(n);
    memset(dp,-1,sizeof(dp));
    int ans = solve(num,0,1,0);
    cout<<ans;
}