#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<pll> vpll;
typedef map<int,int> mii;
typedef map<ll, ll> mll;
typedef tuple<ll, ll, ll> lll;
typedef tuple<int,int,int> iii;

#define endll '\n';

int INF = INT_MAX;
long long INFF = LLONG_MAX;
int dirx[8] = { -1, 0, 0, 1, -1, -1, 1, 1 };
int diry[8] = { 0, 1, -1, 0, -1, 1, -1, 1 };

#define bit(x,i) (x&(1<<i))  //select the bit of position i of x
#define lowbit(x) ((x)&((x)^((x)-1))) //get the lowest bit of x
#define hBit(msb,n) asm("bsrl %1,%0" : "=r"(msb) : "r"(n)) //get the highest bit of x, maybe the fastest

#define FOR(i,L,R) for (int i = L; i < R; i++)
#define FORLE(i,L,R) for (int i = L; i <= R; i++)
#define FORM(i,L,R) for (int i = L; i > R; i--)
#define FORME(i,L,R) for (int i = L; i >= R; i--)

#define ALL(c) (c).begin(),(c).end() //handy for function like "sort()"

#define MP make_pair
#define ff first
#define ss second
#define PB push_back

#define MAXN 10000

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

void update_point(ll i, ll l, ll r, ll pos, ll n) {
    if (l == r) {
        seg[i] = n;
        return;
    }

    ll m = l + (r-l)/2;
    ll left = 2*i + 1;
    ll right = 2*i + 2;

    if (pos <= m) {
        update_point(left, l, m, pos, n);
    } else {
        update_point(right, m+1, r, pos, n);
    }

    seg[i] = seg[left] + seg[right];
}

ll query_interval(ll i, ll l, ll r, ll ql, ll qr) {

    if (ql <= l && r <= qr) return seg[i];
    if (qr < l || ql > r) return 0;

    ll m = l + (r-l)/2;
    ll left = 2*i + 1;
    ll right = 2*i + 2;

    return query_interval(left, l, m, ql, qr) + query_interval(right, m+1, r, ql, qr);

}

//ALTERNATIVOS:

//OBS: falta o build da segtree inversa

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
