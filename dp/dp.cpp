vector<int> weights; 
vector<int> values;
vector<vector<int>> dp;

int knapsack_rec(int i, int c, int n) {
    if (i == n) return 0;
    if (dp[i][c] != -1) return dp[i][c];

    ll op1 = knapsack_rec(i+1, c, n);
    ll op2 = 0;

    if (c >= weights[i]) {
        op2 = values[i] + knapsack_rec(i+1, c - weights[i], n);
    }

    return dp[i][c] = max(op1, op2);
}

vector<int> weights; 
vector<int> values;
vector<vector<int>> dp;

int knapsack_int(int i, int c, int n) {
    
    for(int i = 1; i <= n; i++) {
        for (int j = 1; j <= c; j++) {
            dp[i][c] = dp[i-1][c];

            if (weights[i-1] <= c) {
                dp[i][c] = max(dp[i][c], dp[i-1][c-weights[i-1]] + values[i-1]);
            }
        }
    }
}

vector<vector<int>> dp;

int lcs(int i, int j, string s, string t) {
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
//nlogn
int lis(vector<int> const& a) {
    int n = a.size();
    const int INF = 1e9;
    vector<int> d(n+1, INF);
    d[0] = -INF;

    for (int i = 0; i < n; i++) {
        int l = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
        if (d[l-1] < a[i] && a[i] < d[l])
            d[l] = a[i];
    }

    int ans = 0;
    for (int l = 0; l <= n; l++) {
        if (d[l] < INF)
            ans = l;
    }
    return ans;
}

int kadane(int n, vector<int> &v) {
    int ans = 0;
    int cur = 0;
    for(int i = 0; i < n; i++) {
        cur = max(v[i], cur + v[i]);
        ans = max(ans, cur);
    }

    return ans;

}