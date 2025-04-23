#include<bits/stdc++.h>
using namespace std;
int dp[100][4];
string target = "QAQ";

int solve(string str, int idx, int matched){

    if(matched == 3){
        return 1;
    }

    if(idx == str.size()){
        return 0;
    }

    if(dp[idx][matched] != -1) return dp[idx][matched];
  

    int a = solve(str, idx + 1, matched);
    int b;

    if(str[idx] == target[matched]){
         b = solve(str, idx + 1, matched + 1);
    }
return dp[idx][matched] = a + b;

}

int main(){
    string str;
    cin>>str;

    memset(dp,-1,sizeof(dp));
    int ans = solve(str,0,0);

    cout<<ans;
}