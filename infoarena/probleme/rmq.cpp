#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char uchar;
const int nmax = 100005;
const int lgmax = 18;

int n, m;
int v[nmax];
int rmq[lgmax][nmax];
int lg2[nmax];

inline int pow2(int x) { return (1 << x); }

void precalc() {
    lg2[0] = 1;
    lg2[1] = 0;
    lg2[2] = 1;
    for (int i = 3; i <= n; i++) {
        lg2[i] = lg2[i / 2] + 1;
    }
}

int main() {
    freopen("rmq.in", "r", stdin);
    freopen("rmq.out", "w", stdout);

    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &v[i]);
    }

    precalc();

    for (int i = 1; i <= n; i++) {
        rmq[0][i] = i;
    }
    for (int i = 1; i <= lg2[n]; i++) {
        for (int j = 1; j <= n - pow2(i) + 1; j++) {
            if (v[rmq[i - 1][j]] <= v[rmq[i - 1][j + pow2(i - 1)]]) {
                rmq[i][j] = rmq[i - 1][j];
            } else {
                rmq[i][j] = rmq[i - 1][j + pow2(i - 1)];
            }
        }
    }

    for (int i = 0, x, y; i < m; i++) {
        scanf("%d %d", &x, &y);
        if (x > y) swap(x, y);

        int k = lg2[y - x + 1];
        if (v[rmq[k][x]] <= v[rmq[k][y - pow2(k) + 1]]) {
            printf("%d\n", v[rmq[k][x]]);
        } else {
            printf("%d\n", v[rmq[k][y - pow2(k) + 1]]);
        }
    }

    return 0;
}


