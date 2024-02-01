#include "base.cpp"

bool bic(vvi g, int u, vector<bool> d, vector<bool> c) {
    d[u] = true;

    for (int v : g[u]) {
        if (!d[v]) {
            c[v] = !c[u];
            if (!bic(g, v, d, c)) return false;
        } else if (c[u] == c[v]) return false; 
    }
    return true;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

}