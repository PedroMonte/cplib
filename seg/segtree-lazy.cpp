#include "base.cpp"


// usar em casos de range update
// para casos de point query só usar o intervalo [k,k]
const int ms = 2e5+5;
ll seg[4*ms];
ll v[4*ms];
ll lazy[4*ms];

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

void push(int i, int l, int r) {
    if (lazy[i]) {
        seg[i] += lazy[i] * (r - l + 1);
    }
    if (l != r) {
        ll left = 2*i + 1;
        ll right = 2*i + 2;
        
        lazy[left] += lazy[i];
        lazy[right] += lazy[i];
    }

    lazy[i] = 0;
}

void update(ll i, ll l, ll r, ll ql, ll qr, ll n) {
    push(i, l, r);

    if (qr < l || ql > r) return;

    if (ql <= l && r <= qr) {
        lazy[i] += n;
        push(i, l, r);
    } else {
        ll m = l + (r-l)/2;
        ll left = 2*i + 1;
        ll right = 2*i + 2;

        update(left, l, m, ql, qr, n);
        update(right, m+1, r, ql, qr, n);

        seg[i] = seg[left] + seg[right];
    }
    

}

ll query(ll i, ll l, ll r, ll ql, ll qr) {
    push(i, l, r);
    if (ql <= l && r <= qr) return seg[i];
    if (qr < l || ql > r) return 0;

    ll m = l + (r-l)/2;
    ll left = 2*i + 1;
    ll right = 2*i + 2;

    return query(left, l, m, ql, qr) + query(right, m+1, r, ql, qr);

}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);



}
