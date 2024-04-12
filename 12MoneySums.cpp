#include <bits/stdc++.h>
using namespace std;
//int MOD=1000000007;// will give tle;
const int MOD = (int)1e9 + 7;
void solve(int n,vector<int> &arr) {
    vector<vector<bool>> dp(n+1,vector<bool>(100001,false));
    for(int i=0;i<=n;i++) {
        dp[i][0]=true;
    }
    for(int i=1;i<=n;i++) {
        for(int j=0;j<=100000;j++) {
            if(dp[i-1][j]) {
                dp[i][j]=true;
                dp[i][j+arr[i]]=true;
            }
        }
    }
    vector<int> ans;
    for(int i=1;i<=100000;i++) {
        if(dp[n][i]) ans.push_back(i);
    }
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
int main() {
    ios_base::sync_with_stdio(0);
	cin.tie(0);  // see Fast Input & Output
    int n;
    cin>>n;
    vector<int> arr(n+1);
    for(int i=1;i<=n;i++) cin>>arr[i];
    solve(n,arr);
}
