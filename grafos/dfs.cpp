int n;
vector<vector<int>> g(n);
vector<int> vis(n);

void dfs(int u) {
    vis[u] = 1;

    for (int v : g[u]) {
        if (!vis[v]) {
            dfs(v);
        }
    }
}