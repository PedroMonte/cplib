vector<int> zfunc(string &s) {
    int n = s.size();
    vector<int> z (n, 0);

    for (int i = 0; i < n; i++) {
        int l, r = 0;
        if (i <= r) z[i] = min(z[i-l], r-i+1);

        while (z[i] + i < n && s[z[i]] == s[i+z[i]]) z[i]++;

        if (r < i +z[i] - 1) {
            l = i;
            r = i + z[i] - 1;
        }
    }
}