#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char uchar;
const int nmax = 101;

int a[nmax][nmax], b[nmax][nmax];
int n, m;

int main() {
    //freopen("input", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> b[i][j];
        }
    }    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] > b[i][j]) {
                swap(a[i][j], b[i][j]);
            }
        }
    }

    bool ok = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m - 1; j++) {
            if (a[i][j] >= a[i][j + 1] || b[i][j] >= b[i][j + 1]) {
                ok = false;
                break;
            }
        }
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] >= a[i + 1][j]  || b[i][j] >= b[i + 1][j]) {
                ok = false;
                break;
            }
        }
    }

    if (ok) cout << "Possible\n";
    else cout << "Impossible\n";

    return 0;
}

