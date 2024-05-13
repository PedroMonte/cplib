int n;
vector<vector<int>> g(n);
vector<vector<int>> reversed(n);
vector<int> vis(n);

stack<int> order;
vector<int> comp(n, -1);

void dfs(int u) {
    vis[u] = 1;

    for (int v : g[u]) {
        if (!vis[v]) {
            dfs(v);
        }
    }

    order.push(u);
}

void dfs2(int u, int c) {
    comp[u] = c;

    for (int v : reversed[u]) {
        if (comp[v] == -1) {
            dfs2(v, c);
        }
    }
}

void calldfs1() {
    for(int i = 0; i < n; i++) {
        if (vis[i] == 0) {
            dfs(i);
        }
    }
}

void calldfs2() {
    int j = 0;
    while (!order.empty()) {
        int i = order.top();
        order.pop();

        if (comp[i] == -1) {
            dfs2(i, j++);
        }
    }
}