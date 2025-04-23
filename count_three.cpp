//problem statement ---> you have to count the number of 3's occuring from a number l to number r.


#include<bits/stdc++.h>
using namespace std;
int dp[10][2][10];

int solve(string str, int idx, int tight,int cnt){
    if(idx == str.size()){
        return cnt;
    }

    if(dp[idx][tight][cnt] != -1){
        return dp[idx][tight][cnt];
    }

    int limit = (tight == 1 ? str[idx] - '0': 9);
    int ans = 0;

    
    for (int i = 0;i<=limit;i++){
        ans += solve(str, idx + 1, tight && (i == str[idx] - '0'), cnt + (i == 3 ? 1:0));
    }
    return dp[idx][tight][cnt] = ans;
}

int main(){
    int l;
    int r;
    cin>>l>>r;
    string left = to_string(l-1);
    string right = to_string(r);

    memset(dp,-1,sizeof(dp));
    int leftans = solve(left, 0, 1 , 0);
    memset(dp,-1,sizeof(dp));
    int rightans = solve(right,0,1,0);

    cout<<rightans - leftans;
}