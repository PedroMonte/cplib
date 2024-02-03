#include <bits/stdc++.h>
#include "base.cpp"

int knapsack_rec(int i, int c, int n, vi weights, vi values, vvl& dp) {
    if (i == n) return 0;
    if (dp[i][c] != -1) return dp[i][c];

    ll op1 = knapsack_rec(i+1, c, n, weights, values, dp);
    ll op2 = 0;

    if (c >= weights[i]) {
        op2 = values[i] + knapsack_rec(i+1, c - weights[i], n, weights, values, dp);
    }

    return dp[i][c] = max(op1, op2);
}

int knapsack_int(int i, int c, int n, vi weights, vi values, vvl& dp) {
    FORLE(i, 1, n) {
        FORLE(j, 1, c) {
            dp[i][c] = dp[i-1][c];

            if (weights[i-1] <= c) {
                dp[i][c] = max(dp[i][c], dp[i-1][c-weights[i-1]] + values[i-1]);
            }
        }
    }
}

int lcs(int i, int j, string s, string t, vvl dp) {
    if (i == s.size() || j == t.size()) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    if (s[i] == t[j]) return dp[i][j] = 1 + lcs(i+1, j+1, s, t, dp);

    return dp[i][j] = max(lcs(i+1, j, s, t, dp), lcs(i, j+1, s, t, dp));

}

int lis(vi &nums) {
    vi l;
    for(auto x : nums) {
        auto it = lower_bound(l.begin(), l.end(), x);
        if (it == l.end()) l.push_back(x);
        else *it = x;
    }

    return (int) l.size();

}

int kadane(int n, vi &v) {
    int ans = 0;
    int cur = 0;
    FOR(i, 0, n) {
        cur = max(v[i], cur + v[i]);
        ans = max(ans, cur);
    }

    return ans;

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);   


}