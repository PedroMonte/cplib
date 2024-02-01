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

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

}