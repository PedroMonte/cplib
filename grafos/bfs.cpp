int n, m;
vector<vector<int>> g(n, vector<int>(m));
vector<vector<int>> dist(n, vector<int>(m, INF));
vector<vector<int>> vis(n, vector<int>(m, 0));

void grid(int i, int j) {
    dist[i][j] = 0;
    vis[i][j] = 1;
    queue<pii> q;
    q.push({i,j});

    while (!q.empty()) {
        int w = q.front().first;
        int x = q.front().second;
        q.pop();
        for (int k = 0; k < 4; k++) {
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

int n;
vector<int> dist(n, INF);
vector<int> vis(n, 0);

int bfs(int s) {
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