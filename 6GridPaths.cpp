#include <bits/stdc++.h>
using namespace std;
int mod=1000000007;
long long solve(int n,vector<vector<char>> arr) {
    vector<vector<long long>> dp(n+1,vector<long long>(n+1));
    if(arr[n-1][n-1]=='.') dp[n-1][n-1]=1;
    for(int i=n-1;i>=0;i--) {
        for(int j=n-1;j>=0;j--) {
            if(arr[i][j]=='.') dp[i][j]+=(dp[i+1][j]+dp[i][j+1]);
            dp[i][j]%=mod;
        }
    }
    return dp[0][0];
}
int main() {
    int n;
    cin>>n;
    vector<vector<char>> arr(n,vector<char>(n));
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin>>arr[i][j];
        }
    }
    cout<<solve(n,arr)<<endl;
}