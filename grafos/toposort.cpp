#include "base.cpp"

void tps(vvi g, int n, vi npar) {
    queue<int> q;
    FORLE(i, 1, n) {
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