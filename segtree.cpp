const int ms = 1e5+5;
ll seg[4*ms];
vl v;

void update(ll i, ll l, ll r, ll pos, ll n) {
    if (l == r) {
        seg[i] = n;
        return;
    }

    ll m = l + (r-l)/2;
    ll left = 2*i + 1;
    ll right = 2*i + 2;

    if (pos <= m) {
        update(left, l, m, pos, n);
    } else {
        update(right, m+1, r, pos, n);
    }
}

void build(ll i, ll l, ll r) {
    if (l == r) {
        seg[i] = v[l];
        return;
    }

    ll m = l + (r-l)/2;
    ll left = 2*i + 1;
    ll right = 2*i + 2;

    build(left, l, m);
    build(right, m+1, r);

    seg[i] = seg[left] + seg[right];
}


ll query(ll i, ll l, ll r, ll ql, ll qr) {

    if (ql <= l && r <= qr) return seg[i];
    if (qr < l || ql > r) return 0;

    ll m = l + (r-l)/2;
    ll left = 2*i + 1;
    ll right = 2*i + 2;

    return query(left, l, m, ql, qr) + query(right, m+1, r, ql, qr);

}
