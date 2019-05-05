#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
const int nmax = 100001;

int n, m;
int v[nmax];
int roots[nmax];
int levels[nmax];

void dfs(int node) {
    int R = node;
    int level = 0;
    while (levels[R] == 0) {
        level++;
        R = roots[R];
    }

    level += levels[R];

    R = node;
    while (levels[R] == 0) {
        levels[R] = level;
        R = roots[R];
        level--;
    }
}

int main() {
    freopen("tequila.in", "r", stdin);
    freopen("tequila.out", "w", stdout);

    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &v[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &roots[i]);
        if (roots[i] == -1) levels[i] = 1;
    }
    for (int i = 1; i <= n; i++) {
        dfs(i);
    }

    double solution = 0;
    for (int i = 1; i <= n; i++) {
        solution += static_cast<double>(v[i]) / static_cast<double>(levels[i]);
    }
    printf("%.6f\n", solution);
    int x, y;
    while (m--) {
        scanf("%d %d", &x, &y);
        solution += static_cast<double>(y - v[x]) / static_cast<double>(levels[x]);
        v[x] = y;
        printf("%.6f\n", solution);
    }

    return 0;
}

