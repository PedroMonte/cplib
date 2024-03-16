#include <bits/stdc++.h>
#include "base.cpp"

void dijkstra_normal(vector<vpii>& g, int s, vi& dist, vi& par) {
    dist[s] = 0;
    priority_queue<pii, vpii, greater<pii>> pq;
    pq.push({0, s});

    while (!pq.empty()) {
        auto [du, u] = pq.top();
        pq.pop();

        if (du <= dist[u]) {
            for (auto [dv, v] : g[u]) {
                if (dv + dist[u] < dist[v]) {
                    dist[v] = dv + dist[u];
                    par[v] = u;
                    pq.push({dist[v],v});
                }
            }
        }
    }
}

void dijkstra_grid(vvi g, int n, int m, int si, int sj, vvi dist) {
    dist[si][sj] = g[si][sj];
    priority_queue<iii, vector<iii>, greater<iii>> pq;
    pq.push({g[si][sj], si, sj});

    while (!pq.empty()) {
        auto [w, a, b] = pq.top();
        pq.pop();

        if (w <= dist[a][b]) {
            FOR(l, 0, 4) {
                int i = dirx[l] + a;
                int j = diry[l] + b;
                if (i >= 0 && j >= 0 && i < n && j < m && (g[i][j] + w < dist[i][j])) {
                    dist[i][j] = g[i][j] + w;
                    pq.push({dist[i][j], i, j});
                }
            }
        }
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);   




}