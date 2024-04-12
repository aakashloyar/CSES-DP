#include <bits/stdc++.h>
using namespace std;
int mod=1000000007;
long long solve(int n,int m,vector<long long>& arr) {
    vector<long long> dp(n+1,0);
    dp[0]=1;
    for(int i=1;i<=n;i++) {
        int j=0;
        long long sum=0;
        while(j<m && i-arr[j]>=0) {
            sum+=dp[i-arr[j]];
            j++;
        }
        dp[i]=sum%mod;
    }
    return dp[n];
}
int main() {
    int m,n;
    cin>>m>>n;
    vector<long long> arr(m);
    for(int i=0;i<m;i++) cin>>arr[i];
    sort(arr.begin(), arr.end());
    cout<<solve(n,m,arr)<<endl;
}