#include <bits/stdc++.h>
using namespace std;
long mod=1000000007;

long long solve(int n) {
    vector<long long> dp(n+1); 
    dp[0]=1;
    for(int i=1;i<=n;i++) {
        long long sum=0;
        int j=1;
        while(i-j>=0 &&j<=6) {
            sum+=dp[i-j];
            j++;
        }
        dp[i]=sum%mod;
    }
    return dp[n];
}
int main() {
    int n;
    cin>>n;
    cout<<solve(n);
}
