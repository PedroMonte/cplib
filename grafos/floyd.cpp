vvl g;
vvl dist;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;

    for(int k = 1; k < n; k++) {
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

}
