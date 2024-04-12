#include <bits/stdc++.h>
using namespace std;
int mod=1000000007;
long long solve(int n,int x,vector<int> cost,vector<int> pages) {
    vector<long long> dp1(x+1);
    vector<long long> dp2(x+1);
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=x;j++) {
            long skip=dp1[j];
            long take=((cost[i]<=j)?dp1[j-cost[i]]+pages[i]:0);
            dp2[j]=max(take,skip);
        }
        for(int j=1;j<=x;j++) dp1[j]=dp2[j];
    }
    return dp1[x];
}
int main() {
    int n, x;
    cin >> n >> x;
    vector<int> cost(n+1);
    vector<int> pages(n+1);
    for (int i = 1; i <= n; ++i) {
        cin >> cost[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> pages[i];
    }
    cout<<solve(n,x,cost,pages)<<endl;
}