#include<bits/stdc++.h>
using namespace std;

int dp[10][2][90];

bool isprime(int n){
    if(n == 0 || n == 1){
        return 0;
    }

    for (int i = 2;i<=n/2;i++){
        if(n%i == 0) return 0;
    }
    return 1;
}

int solve(string str,int idx, bool tight, int count){
    if(idx == str.size()){
        if(isprime(count)){
            return 1;
        }
        else{
            return 0;
        }
}

if(dp[idx][tight][count] != -1){
    return dp[idx][tight][count];
}

int limit = (tight == 1? str[idx] - '0':9);
int ans = 0;
for (int i = 0;i<=limit;i++){
    ans += solve(str,idx+1,tight & (i==str[idx] - '0'), count + i);
}
return dp[idx][tight][count] = ans;
}
int main(){

    int n; 
    cin>>n;

    vector<int> vec;

    for(int i = 0;i<n;i++){
        int l,r;
    cin>>l>>r;
    
    string left = to_string(l-1);
    string right = to_string(r);

    memset(dp,-1,sizeof(dp));

    int leftans = solve(left,0,1,0);

    memset(dp,-1,sizeof(dp));

    int rightans = solve(right,0,1,0);
    vec.push_back(rightans - leftans);
    }
    

    for (int i = 0;i<n;i++){
        cout<<vec[i]<<endl;
    }
}