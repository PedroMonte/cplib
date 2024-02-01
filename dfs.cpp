#include "base.cpp"

void dfs(vvi &g, int u, vi &vis) {
    vis[u] = 1;

    for (int v : g[u]) {
        if (!vis[v]) {
            dfs(g, v, vis);
        }
    }
    
    
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

}