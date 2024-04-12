#include <bits/stdc++.h>
using namespace std;
//int MOD=1000000007;// will give tle;
const int MOD = (int)1e9 + 7;
long long solve(int n,int m,vector<long long>& arr) {
    vector<long long> dp(n+1,0);
    dp[0]=1;
    for(int i=0;i<m;i++) {
        for(int j=1;j<=n;j++) {
            if(arr[i]<=j) {
                dp[j]+=dp[j-arr[i]];
                dp[j]%=MOD;
            }
        }
    }
    return dp[n];
}
int main() {
    ios_base::sync_with_stdio(0);
	cin.tie(0);  // see Fast Input & Output
    int m,n;
    cin>>m>>n;
    vector<long long> arr(m);
    for(int i=0;i<m;i++) cin>>arr[i];
    cout<<solve(n,m,arr)<<endl;
}
