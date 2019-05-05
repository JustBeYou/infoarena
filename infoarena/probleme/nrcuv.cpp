#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
const int nmax = 1005;
uint n, m;
bool forb[28][28];
uint dp[nmax][28];
const uint mod = 104659;

inline uint chr_idx(char c) {
    return c - 'a';
}

int main() {
    freopen("nrcuv.in", "r", stdin);
    freopen("nrcuv.out", "w", stdout);

    scanf("%u %u\n", &n, &m);

    char a, b;
    for (uint  i = 0;i < m; i++) {
        scanf("%c %c\n", &a, &b);
        forb[chr_idx(a)][chr_idx(b)] = forb[chr_idx(b)][chr_idx(a)] = true;
    }

    for (uint i = 0; i < 26; i++) {
        dp[1][i] = 1;
    }

    for (uint len = 1; len <= n; len++) {
        for (uint i = 0; i < 26; i++) {
            for (uint j = 0; j < 26; j++) {
                if (!forb[i][j]) {
                    dp[len][i] += dp[len - 1][j];
                    dp[len][i] %= mod;
                }
            }
        }
    }

    uint sol = 0;
    for (uint i = 0; i < 26; i++) {
        sol += dp[n][i];
        sol %= mod;
    }

    printf("%u\n", sol);

    return 0;
}


