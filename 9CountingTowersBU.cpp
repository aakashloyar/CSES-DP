#include <bits/stdc++.h>
using namespace std;
long mod=1000000007;
void fill(vector<vector<long long>>& dp) {
    dp[0][0]=1;
    dp[0][1]=1;
    for(int i=1;i<1000001;i++) {
        dp[i][0]=(dp[i-1][1]+dp[i-1][0]*2)%mod;
        dp[i][1]=(dp[i-1][0]+dp[i-1][1]*4)%mod;
    }
}
int main() {
    int t;
    cin>>t;
    vector<vector<long long>> dp(1000001,vector<long long>(2,0));
    fill(dp);
    while(t-->0) {
        int n;
        cin>>n;
        cout<<(dp[n-1][0]+dp[n-1][1])%mod<<endl;
    }
}
