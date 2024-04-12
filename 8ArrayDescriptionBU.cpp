#include <bits/stdc++.h>
using namespace std;
int mod=1000000007;
void fill(vector<vector<long long>>& dp,int i,int j) {
    dp[i][j]=dp[i-1][j]+dp[i-1][j-1]+dp[i-1][j+1];
    dp[i][j]%=mod;
}
long long solve(int n,int m,vector<long long>& arr) {
    vector<vector<long long>> dp(n+1,vector<long long>(m+2,0));
    if(arr[1]==0) {
        for(int i=1;i<=m;i++) dp[1][i]=1;
    }
    else dp[1][arr[1]]=1;
    for(int i=2;i<=n;i++) {
        if(arr[i]==0) {
            for(int j=1;j<=m;j++) fill(dp,i,j);
        }
        else fill(dp,i,arr[i]);
    }
    if(arr[n]!=0) return dp[n][arr[n]];
    else {
        long long sum=0;
        for(int j=1;j<=m;j++) {
            sum+=dp[n][j];
            sum%=mod;
        }
        return sum;
    }
}
int main() {
    int n,m;
    cin>>n>>m;
    vector<long long> arr(n+1);
    for(int i=1;i<=n;i++) cin>>arr[i];
    cout<<solve(n,m,arr)<<endl;
}