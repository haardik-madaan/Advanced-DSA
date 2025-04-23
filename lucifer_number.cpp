#include<bits/stdc++.h>
using namespace std;

int dp[11][2][100][100];

bool isprime(int n){
    if(n == 0 || n == 1) return false;

    for (int i = 2;i<=n/2;i++){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}

int solve(string str, int idx, bool tight, int even,int odd){


    if(idx == 0){
        if(isprime(abs(even-odd))){
            return 1;
        }
        else{
            return 0;
        }
    }

    if(dp[idx][tight][even][odd]!=-1){
        return dp[idx][tight][even][odd];
    }

    int limit = (tight == 1 ? str[idx]-'0':9);
    int ans = 0;

    for (int i = 0;i<=limit;i++){
        ans+=solve(str, idx - 1, tight && (i == (str[idx] - '0')), even + (((idx) % 2 == 0) ? i : 0), odd + (((idx) % 2 == 1) ? i : 0));

    }

    return dp[idx][tight][even][odd] = ans;
}

int main(){
    int l,r;
    cin>>l>>r;
    string left = to_string(l-1);
    string right = to_string(r);

    memset(dp,-1,sizeof(dp));

    

    int leftans = solve(left,left.size()-1,1,0,0);

    memset(dp,-1,sizeof(dp));

    

    int rightans = solve(right,right.size()-1,1,0,0);

    cout<<rightans-leftans;
}