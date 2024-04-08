#include "../base.cpp"
// O(2^n * n^2)

#include <bits/stdc++.h>

const int ms = 20;

int n;
int dp[ms][1 << ms];
int g[ms][ms];


int tsp(int u, int mask) {
    if (mask == (1 << n) - 1) return dp[u][mask] = g[u][0];
    if (dp[u][mask] != -1) return dp[u][mask];
    int ans = INF;

    FOR(v, 0, n) {
        if (mask & (1 << v) == 0) {
            ans = min(ans, g[u][v] + tsp(v, mask | (1 << v)));
        }
    }

    return dp[u][mask] = ans;

}
