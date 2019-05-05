#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
const int nmax = 101;
const int kmax = 21;

uint dp[kmax][nmax][nmax];
uint n, m, k;
bitset<nmax> matrix[nmax];

int x_dir[] = {1, -1, 0, 0};
int y_dir[] = {0, 0, 1, -1};

inline bool check(uint x, uint y) {
    return x >= 1 && y >= 1 && x <= n && y <= m;
}

inline void calc(uint steps, uint x, uint y) {
    uint new_x, new_y;
    for (uint i = 0; i < 4; i++) {
        new_x = x + x_dir[i];
        new_y = y + y_dir[i];
        if (check(new_x, new_y)) {
            dp[steps][x][y] += dp[steps - 1][new_x][new_y];
        }
    }
}

int main() {
    freopen("homm.in", "r", stdin);
    freopen("homm.out", "w", stdout);

    scanf("%u%u%u", &n, &m, &k);
    int tmp;
    for (uint i = 1; i <= n; i++) {
        for (uint j = 1; j <= m; j++) {
            scanf("%d", &tmp);
            matrix[i][j] = !tmp;
        }
    }

    uint x1, y1, x2, y2;
    scanf("%u %u %u %u", &x1, &y1, &x2, &y2);

    dp[0][x1][y1] = 1;
    for (uint steps = 1; steps <= k; steps++) {
        for (uint i = 1; i <= n; i++) {
            for (uint j = 1; j <= m; j++) {
                if (matrix[i][j]) calc(steps, i, j);
            }
        }
    }

    uint sol = 0;
    for (uint steps = 0; steps <= k; steps++) {
        sol += dp[steps][x2][y2];
    }

    printf("%u", sol);

    return 0;
}


