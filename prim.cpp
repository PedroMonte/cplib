#include "base.cpp"

int prim(vector<vpii>& g, int s, vi& vis) {
    int mstW = 0;
    priority_queue<pii, vpii, greater<pii>> pq;
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

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

}