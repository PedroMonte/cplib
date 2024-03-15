#include <bits/stdc++.h>

#include "base.cpp"

struct DSU {
    int n;
    vi root, size;
    DSU(int n) {
        root.resize(n);
        size.assign(n,1);
        FOR(i, 0, n) {
            root[i] = i;
        }
    }

    int find(int a) {
        if (a == root[a]) return a;
        return root[a] = find(root[a]);
    }

    void (join(int a, int b)) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (size[a] < size[b]) {
                root[b] = a;
            } else root[a] = b;
            size[a] += size[b];
            size[b] = size[a];
        }
    }


};

ll kruskal(int n, vector<lll> &edges) {
    DSU dsu(n);
    int mst_cost = 0;
    int comp = 0;

    for (auto &[w,u,v] : edges) {
        if (dsu.find(u) != dsu.find(v)) {
            comp++;
            mst_cost+= w;
            dsu.join(u, v);
        }
    }

    return mst_cost;

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

}
