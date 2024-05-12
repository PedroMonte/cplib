int n;
vector<vector<pii>> g(n);
vector<int> vis(n, 0);

int prim(int s) {
    int mstW = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, s});

    while (!pq.empty()) {
        auto [w, u] = pq.top();
        pq.pop();

        if (vis[u]) continue;
        vis[u] = 1;
        mstW += w;

        for (auto [w, v] : g[u]) {
            if (!vis[v]) {
                pq.push({w,v});
            }
        }
        
    }

    return mstW;
}