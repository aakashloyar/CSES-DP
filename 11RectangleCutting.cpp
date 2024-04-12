#include <bits/stdc++.h>
using namespace std;
//int MOD=1000000007;// will give tle;
const int MOD = (int)1e9 + 7;
long long solve(int n,int m) {
    vector<vector<long>> dp(n+1,vector<long>(m+1));
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(i!=j) {
                long ans=LONG_MAX;
                int rem=1;
                while(i-rem>=rem) {
                    ans=min(ans,1+dp[i-rem][j]+dp[rem][j]);
                    rem++;
                }
                rem=1;
                while(j-rem>=rem) {
                    ans=min(ans,1+dp[i][j-rem]+dp[i][rem]);
                    rem++;
                }
                dp[i][j]=ans;
            }
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
    int n,m;
    cin>>n>>m;
    cout<<solve(n,m)<<endl;
}
