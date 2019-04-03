#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char uchar;
const int nmax = 100001;
const int pmax = 40;
ull a[nmax], b[nmax];
ull sumb[nmax];
ull dp[2][pmax];
uint n;

ull pow2[pmax];
void init_pows() {
    for (uint i = 0; i < pmax; i++) {
        pow2[i] = 1ULL << i;
    }
}

inline uint row(uint x) {
    return x & 1;
}

int main() {
    freopen("hacker3.in", "r", stdin);
    freopen("hacker3.out", "w", stdout);

    init_pows();

    scanf("%u", &n);
    for (uint i = 1; i <= n; i++) {
        scanf("%llu %llu", &a[i], &b[i]);
    }

    for (uint i = 1; i <= n; i++) {
        sumb[i] += sumb[i - 1] + b[i];
    }
    dp[row(1)][0] = b[1];
    dp[row(1)][1] = a[1];

    for (uint i = 2; i <= n; i++) {
        dp[row(i)][0] = sumb[i];

        for (uint j = 1; j < pmax && j <= i; j++) {
            if (dp[row(i - 1)][j] == 0 && dp[row(i - 1)][j - 1] == 0) continue;

            if (dp[row(i - 1)][j] == 0) dp[row(i)][j] = 1ULL * pow2[j - 1] * a[i] + dp[row(i - 1)][j - 1];
            else if (dp[row(i - 1)][j - 1] == 0)  dp[row(i)][j] = 1ULL * pow2[j] * b[i] + dp[row(i - 1)][j];
            else dp[row(i)][j] = min(1ULL * pow2[j] * b[i] + dp[row(i - 1)][j], 1ULL * pow2[j - 1] * a[i] + dp[row(i - 1)][j - 1]);
        }
    }

    ull sol = ULLONG_MAX;
    for (uint i = 0; i < pmax; i++) {
        if (dp[row(n)][i]) sol = min(sol, dp[row(n)][i]);
    }
    printf("%llu\n", sol);

    return 0;
}


