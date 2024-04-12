#include <bits/stdc++.h>
using namespace std;
using ll=long long;
//int MOD=1000000007;// will give tle;
const int MOD = (int)1e9 + 7;
long long solve(int n,vector<int> &arr) {
    vector<vector<ll>> dp(n+2,vector<ll>(n+2));
    for(int c=1;c<=n;c++) {
        int s=1,e=c;
        while(e<=n) {
            if(e==s) dp[s][e]=arr[s];
            else {
                ll a=arr[s],b=arr[e];
                a+=min(dp[s+2][e],dp[s+1][e-1]);
                b+=min(dp[s+1][e-1],dp[s][e-2]);
                dp[s][e]=max(a,b);
            }
            s++;
            e++;
        }
    }
    // for(int i=0;i<=n+1;i++) {
    //     for(int j=0;j<=n+1;j++) {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return dp[1][n];
}
int main() {
    ios_base::sync_with_stdio(0);
	cin.tie(0);  // see Fast Input & Output
    int n;
    cin>>n;
    vector<int> arr(n+1);
    for(int i=1;i<=n;i++) cin>>arr[i];
    cout<<solve(n,arr)<<endl;
}
