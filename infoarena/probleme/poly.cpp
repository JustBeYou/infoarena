#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char uchar;
const int nmax = 30001;
const int mmax = (1 << 7) + 1;

const int M[] = {2, 3, 7, 11, 19, 23, 37};
int n;
int dp[2][mmax];

inline int idx(int i) { return i & 1; }

int main() {
    freopen("poly.in", "r", stdin);
    freopen("poly.out", "w", stdout);

    scanf("%d", &n);

    int curr, prev;
    for (int i = 0, x; i < n; ++i) {
        prev = idx(i);
        curr = idx(i + 1);
        scanf("%d", &x);

        int r = 0;
        for (int j = 0; j < 7; j++) {
            if (x % M[j] == 0) {
                r += 1 << j;
            }
        }

        for (int j = 0; j < mmax; j++) {
            if ((r & j) == 0) {
                dp[curr][r] = max(dp[curr][r], dp[prev][j] + 1);
            }
        }

        for (int j = 0; j < mmax; j++) {
            dp[prev][j] = dp[curr][j];
        }
    }

    int best = 0;
    for (int j = 0; j < mmax; j++) {
        best = max(best, dp[curr][j]);
    }
    printf("%d\n", best);

    return 0;
}


