struct DSU {
    int n;
    vector<int> root, size;
    DSU(int n) {
        root.resize(n);
        size.assign(n,1);
        for(int i = 0; i < n; i++) {
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