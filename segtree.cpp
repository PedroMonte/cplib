#include "base.cpp"

const int ms = 2e5+5;
ll seg[4*ms];
ll v[4*ms];

//NORMAIS:

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

//update point
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

    seg[i] = seg[left] + seg[right];
}

//query interval
ll query(ll i, ll l, ll r, ll ql, ll qr) {

    if (ql <= l && r <= qr) return seg[i];
    if (qr < l || ql > r) return 0;

    ll m = l + (r-l)/2;
    ll left = 2*i + 1;
    ll right = 2*i + 2;

    return query(left, l, m, ql, qr) + query(right, m+1, r, ql, qr);

}

//ALTERNATIVOS:
// (USAR O LAZY NESSES CASOS)
//OBS: sem o build da segtree inversa

ll update_interval(ll i, ll l, ll r, ll ql, ll qr, ll n) {

    if (ql <= l && r <= qr) {
        seg[i] += n;
        return;
    }
    if (qr < l || ql > r) return;

    ll m = l + (r-l)/2;
    ll left = 2*i + 1;
    ll right = 2*i + 2;

    update_interval(left, l, m, ql, qr, n);
    update_interval(right, m+1, r, ql, qr, n);

}

ll query_point(ll i, ll l, ll r, ll pos) {

    if (l == r) return seg[i];
    ll m = l + (r-l)/2;
    ll left = 2*i + 1;
    ll right = 2*i + 2;

    if (pos <= m) {
        return seg[i] + query_point(left, l, m, pos);
    } else {
        return seg[i] + query_point(right, m+1, r, pos);
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);



}
