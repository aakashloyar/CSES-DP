#include <bits/stdc++.h>
using namespace std;
using ll=long long;
//int MOD=1000000007;// will give tle;
const int MOD = (int)1e9 + 7;
long long deninv(int base,int pow,int mod) {
        //long deninverse =  deninv((int)den, mod - 2, mod);
        long long res=base;
        long long ans=1;
        while(pow!=0) {
            int bit=pow&1;
            if(bit==1) {
                ans=ans*res;
                ans%=mod;
            }
            res=res*res;
            res%=mod;
            pow=pow>>1;
        }
        return ans;
}

long long solve(int n) {
    int pivot=(n*(n+1))/2;
    vector<vector<long long>> dp(n+1,vector<long long>(pivot+1,0));
    if(pivot&1==1) return 0;
    dp[0][0]=1;
    for(int i=1;i<=n;i++) {
        for(int j=0;j<=pivot;j++) {
            if(dp[i-1][j]) {
                dp[i][j]+=(dp[i-1][j]);
                dp[i][j+i]+=(dp[i-1][j]);
                dp[i][j]%=MOD;
                dp[i][j+i]%=MOD;
            }
        }
    }
    // for(int i=0;i<=n;i++) {
    //     for(int j=0;j<=pivot;j++) {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    long long den=deninv(2,MOD-2,MOD);
    return ((dp[n][pivot/2]*den)%MOD);
}
int main() {
    ios_base::sync_with_stdio(0);
	cin.tie(0);  // see Fast Input & Output
    int n;
    cin>>n;
    cout<<solve(n)<<endl;
}
