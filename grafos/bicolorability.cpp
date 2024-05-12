int n;
vector<vector<int>> g(n);
vector<bool> d;
vector<bool> c;

bool bic(int u) {
    d[u] = true;

    for (int v : g[u]) {
        if (!d[v]) {
            c[v] = !c[u];
            if (!bic(v)) return false;
        } else if (c[u] == c[v]) return false; 
    }
    return true;
}