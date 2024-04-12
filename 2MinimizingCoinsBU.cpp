#include <bits/stdc++.h>
using namespace std;
int mod=1000000007;
long long solve(int n,int m,vector<long long>& arr) {
    vector<long long> dp(n+1,100000000);
    dp[0]=0;
    for(int i=1;i<=n;i++) {
        int j=0;
        long long sum=100000000;
        //cout<<sum<<endl;
        while(j<m && i-arr[j]>=0) {
            sum=min(sum,dp[i-arr[j]]+1);
            j++;
        }
        dp[i]=sum;
    }
    if(dp[n]>=100000000) return -1;
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