#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char uchar;
const int nmax = 101;

int n, h, m;
int v[nmax];

int main() {
    //freopen("input", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> n >> h >> m;
    for (int i = 1; i <= n; i++) {
        v[i] = h;
    }
    for (int i = 0, l, r, x; i < m; i++) {
        cin >> l >> r >> x;
        for (int j = l; j <= r; j++) {
            v[j] = min(v[j], x);
        }
    }

    int sol = 0;
    for (int i = 1; i <= n; i++) {
        sol += v[i] * v[i];
    }
    cout << sol << "\n";

    return 0;
}

