#include <bits/stdc++.h>
using namespace std;
int mod=1000000007;
long long solve(int n) {
    if(n<10) return 1;
    vector<long long> dp(n+1,0);
    for(int i=0;i<=9;i++) dp[i]=1;
    for(int i=10;i<=n;i++) {
        long long ans=LONG_MAX;
        int curr=i;
        while(curr!=0) {
            int d=curr%10;
            if(d!=0) ans=min(ans,1+dp[i-d]);
            curr/=10;
        }
        dp[i]=ans;
    }
    return dp[n];
}
int main() {
    int n;
    cin>>n;
    cout<<solve(n)<<endl;
}