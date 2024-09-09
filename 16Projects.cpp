#include <bits/stdc++.h>
using namespace std;

struct Pair {
    int n, w;
    Pair(int n, int w) : n(n), w(w) {}
};

struct PC {
    bool operator()(const Pair& a, const Pair& b) {
        return a.w > b.w;
    }
};

void sort2darray(vector<vector<int>>& arr) {
    sort(arr.begin(), arr.end(), [](const vector<int>& a, const vector<int>& b) {
        if (a[0] != b[0])
            return a[0] < b[0];
        else 
            return a[1] < b[1];
    });
}

long long func1(vector<long long>& dp, const vector<vector<int>>& arr, const vector<int>& ind, int i, int n) {
    if (i == n) return 0;
    if (dp[i] != -1) return dp[i];
    long long skip = func1(dp, arr, ind, i + 1, n);
    long long take = func1(dp, arr, ind, ind[i], n) + arr[i][2];
    dp[i] = max(skip, take);
    return dp[i];
}

void solve(const vector<vector<int>>& arr, const vector<int>& ind, int n) {
    vector<long long> dp(n, -1);
    long long res = func1(dp, arr, ind, 0, n);
    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(3));

    for (int i = 0; i < n; ++i) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }

    priority_queue<Pair, vector<Pair>, PC> pq;
    sort2darray(arr);
    vector<int> dp(n, n);

    for (int i = 0; i < n; ++i) {
        int cs = arr[i][0], ce = arr[i][1];
        while (!pq.empty() && pq.top().w < cs) {
            dp[pq.top().n] = i;
            pq.pop();
        }
        pq.emplace(i, ce);
    }

    solve(arr, dp, n);

    return 0;
}
