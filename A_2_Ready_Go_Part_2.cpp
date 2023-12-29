#include <bits/stdc++.h>
using namespace std;
#define Fast_IO                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define int long long int

/* ****  My code start here **** */
vector<string> v;
int r, c, cnt = 0;
int hagar = 0;
string s;
int t, z;
set<pair<int, int>> elar;
map<pair<int, int>, int> mp;

bool check(int x, int y) {
    if (x >= 0 && x < r && y >= 0 && y < c) {
        return true;
    }
    return false;
}

void dfs(int x, int y) {
    v[x][y] = '*';
    int d[] = {0, -1, 0, 1, 0};
    for (int i = 0; i < 4; i++) {
        int a = x + d[i];
        int b = y + d[i + 1];
        // cout << "\nvals:" << a << ' ' << b << '\n';
        // if (a == 2 && b == 0) {
        //     cout << "para:" << v[a][b];
        // }
        if (check(a, b)) {
            // cout << "\nvals:" << a << ' ' << b << '\n';

            if (v[a][b] == 'W') {
                hagar++;
                dfs(a, b);
            } else if (v[a][b] == '.' && elar.find({a, b}) == elar.end()) {
                cnt++;
                elar.insert({a, b});
                // v[a][b] = '*';
            }
        }
    }
}

void print() {
    cout << '\n';
    for (int i = 0; i < r; i++) {
        cout << v[i] << '\n';
    }
    cout << '\n';
}
int32_t main() {
    Fast_IO

    clock_t danger_close = clock();
    cin >> t;
    z = t;
    cout << fixed;
    while (t--) {
        cout << "Case #" << z - t << ": ";
        mp.clear();
        // cout << '\n';
        v.clear();
        cin >> r >> c;
        for (int i = 0; i < r; i++) {
            cin >> s;
            v.push_back(s);
        }
        int ans = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (v[i][j] == 'W') {
                    elar.clear();
                    hagar = 1;
                    dfs(i, j);
                    // cout << cnt << '\n';
                    if (cnt == 1) {
                        // cout << i << ' ' << j << '\n';
                        mp[{(*elar.begin()).first, (*elar.begin()).second}] += hagar;
                    }
                    cnt = 0;
                }
            }
        }
        for (auto i : mp) {
            ans = max(ans, i.second);
        }
        cout << ans << '\n';
        // print();
    }
    return 0;
}