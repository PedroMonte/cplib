int n;
vector<vector<pii>> g(n);
vector<int> dist(n);
vector<int> par(n);

void dijkstra_normal(int s) {
    dist[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
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

int n, m;
vector<vector<int>> g(n, vector<int>(m));
vector<vector<int>> dist(n, vector<int>(m, INF));
vector<vector<int>> vis(n, vector<int>(m, 0));

void dijkstra_grid(int si, int sj) {
    dist[si][sj] = g[si][sj];
    priority_queue<iii, vector<iii>, greater<iii>> pq;
    pq.push({g[si][sj], si, sj});

    while (!pq.empty()) {
        auto [w, a, b] = pq.top();
        pq.pop();

        if (w <= dist[a][b]) {
            for(int l = 0; l < 4; l++) {
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