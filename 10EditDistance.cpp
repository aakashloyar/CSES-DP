#include <bits/stdc++.h>
using namespace std;
//int MOD=1000000007;// will give tle;
const int MOD = (int)1e9 + 7;
long long solve(int n,int m,string & s,string & t) {
    vector<vector<long long>> dp(n+1,vector<long long>(m+1));
    for(int i=1;i<=n;i++) {
        dp[i][0]=i;
    }
    for(int i=1;i<=m;i++) {
        dp[0][i]=i;
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            long del=1+dp[i-1][j];
            long add=1+dp[i][j-1];
            long rep=dp[i-1][j-1]+((s[i-1]!=t[j-1])?1:0);
            long ans=min({del,add,rep});
            dp[i][j]=ans;
        }
    }
    // for(int i=0;i<=n;i++) {
    //     for(int j=0;j<=m;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return dp[n][m];
}
int main() {
    ios_base::sync_with_stdio(0);
	cin.tie(0);  // see Fast Input & Output
    string s;
    string t;
    cin>>s;
    cin>>t;
    int n=s.length();
    int m=t.length();
    cout<<solve(n,m,s,t)<<endl;
}
