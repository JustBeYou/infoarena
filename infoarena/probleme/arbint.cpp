#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
const int nmax = 100000 * 4 + 5;
uint arb[nmax];
int n, m;


void update(int x, int pos, int node, int l, int r) {
    if (l == r) {
        arb[node] = x;
        return ;
    }

    int m = (l + r) / 2;
    if (pos <= m) update(x, pos, 2 * node + 1, l,     m);
    else          update(x, pos, 2 * node + 2, m + 1, r);

    arb[node] = max(arb[2 * node + 1], arb[2 * node + 2]);
}

uint result;
void query(int a, int b, int node, int l, int r) {
    if (a <= l && b >= r) {
        result = max(arb[node], result);
        return ;
    }

    int m = (l + r) / 2;
    if (a <= m) query(a, b, 2 * node + 1, l, m);
    if (b > m) query(a, b, 2 * node + 2, m + 1, r);
}

int main() {
    freopen("arbint.in", "r", stdin);
    freopen("arbint.out", "w", stdout);

    scanf("%d%d", &n, &m);
    for (int i = 0, x; i < n; i++) {
        scanf("%d", &x);
        update(x, i, 0, 0, n - 1);
    }

    for (int i = 0, op, x, y; i < m; i++) {
        scanf("%d %d %d", &op, &x, &y);
        if (op == 0) {
            result = 0;
            query(x - 1, y - 1, 0, 0, n - 1);
            printf("%u\n", result);
        } else {
            update(y, x - 1, 0, 0, n - 1);
        }
    }

    return 0;
}


