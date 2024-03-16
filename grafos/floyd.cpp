#include <bits/stdc++.h>

#include "base.cpp"

vvl g;
vvl dist;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;

    FORLE(k, 1, n) {
        FORLE(i, 1, n) {
            FORLE(j, 1, n) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

}