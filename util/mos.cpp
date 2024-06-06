struct Query {
    int l, r, idx;
    bool operator<(Query other) const
    {
        return make_pair(l / block, r) <
               make_pair(other.l / block, other.r);
    }
};

for (int i = 0; i < q; i++) {
        Query qq = querys[i];

        while (l > qq.l) {
            l--;
            add(m1,m2,l);
        }
        while (r < qq.r) {
            r++;
            add(m1,m2,r);
        }
        while (l < qq.l) {
            remove(m1,m2,l);
            l++;
        }
        while (r > qq.r) {
            remove(m1,m2,r);
            r--;
        }

        ans[qq.idx] = get_ans();

    }