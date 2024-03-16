#include <bits/stdc++.h>

#include "base.cpp"

void bfs_grid(vvi &g, int m, int n, int i, int j, vvi &dist, vvi &vis) {
    dist[i][j] = 0;
    vis[i][j] = 1;
    queue<pii> q;
    q.push({i,j});

    while (!q.empty()) {
        int w = q.front().first;
        int x = q.front().second;
        q.pop();
        FOR(k, 0, 4) {
            int a = dirx[k] + w;
            int b = diry[k] + x;

            if (a < m && b < n && a >= 0 && b >= 0 && g[a][b] == '#' && vis[a][b] == 0) {
                q.push({a,b});
                dist[a][b] = dist[w][x] + 1;
                vis[a][b] = 1;
            }
        }
    }
    
}

int bfs_normal(vvi &g, int s, int n, vi &dist, vi &vis) {
    dist[s] = 0;
    vis[s] = 1;

    queue<int> q;
    q.push(s);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : g[u]) {
            if (vis[v] == 0) {
                vis[v] = 1;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    return dist[n];

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

}