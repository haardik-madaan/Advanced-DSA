//code forces.. problem statement ---> find total number of numbers between l and r which have not more than 3 non zero digits.


#include<bits/stdc++.h>
using namespace std;
long long dp[20][2][4];

long long solve(string str, int idx, int tight, int cnt){
    
    if(cnt>3) return 0;

    if(idx == str.size()) return 1;

    if(dp[idx][tight][cnt] != -1){
        return dp[idx][tight][cnt];
    }

    long long limit = (tight == 1 ? str[idx] - '0': 9);
    long long ans = 0;

    for(int i = 0;i<=limit;i++){
        ans += solve(str,idx+1,tight && (i==str[idx]-'0'), cnt + (i != 0 ? 1:0));
    }

    return dp[idx][tight][cnt] = ans;


}
int main(){

    int k;
    cin>>k;
    vector<long long> vec;

    for (int i = 0;i<k;i++){
        long long l;
        long long r;
        cin>>l>>r;
    
        string left = to_string(l-1);
        string right = to_string(r);
    
        memset(dp,-1,sizeof(dp));
       
    
        long long leftans = solve(left,0,1,0);
    
        memset(dp,-1,sizeof(dp));
    
        long long rightans = solve(right,0,1,0);

        vec.push_back(rightans - leftans);
    }


    for (int i = 0;i<k;i++){
        cout<<vec[i]<<endl;
    }


}