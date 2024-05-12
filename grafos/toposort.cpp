int n;
vector<vector<pii>> g(n);
vector<int> npar(n, 0);

void tps(int n) {
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (npar[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : g[u]) {
            npar[v]--;

            if (npar[v] == 0) {
                q.push(v);
            }
        }
    
    }
    
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

}