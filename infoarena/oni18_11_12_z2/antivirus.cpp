#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char uchar;
const int nmax = 2001;

int n, t, k;
long long dp[nmax][nmax];
long long v[nmax];
long long s[nmax];
const long long INF = INT_MAX;

void show () {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            cout << dp[i][j] << " ";
        } cout << endl;
    }
}

int main() {
    freopen("antivirus.in", "r", stdin);
    freopen("antivirus.out", "w", stdout);

    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &k);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &v[i]);
            s[i] = v[i] + s[i - 1];
            if (v[i] == 0) {
                k--;
            }
        }

        for (int i = 0; i < nmax; i++) {
            for (int j = 0; j < nmax; j++) {
                dp[i][j] = INF;
            }
        }
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }

        int last = 0;
        for (int i = 1; i <= n; i++) {
            bool virusat = v[i] > 0;


            if (virusat) {

                if (last != 0) {
                    for (int j = 1; j <= k; j++) {
                        dp[i][j] = dp[i - 1][j];
                        if (i - last <= j && dp[last][j - (i - last)] != INF) {
                            dp[i][j] = min(dp[i][j], dp[last][j - (i - last)] + s[i] - s[last]);
                        }
                    }
                }

            } else {

                for (int j = 1; j <= k; j++) {
                    dp[i][j] = dp[i - 1][j];
                    for (int w = i - 1; w >= last; w--) {
                        if (i - w - 1 <= j && dp[w][j - (i - w - 1)] != INF) {
                            dp[i][j] = min(dp[i][j], dp[w][j - (i - w - 1)] + s[i] - s[w]);
                        }
                    }
                }
                last = i;

            }
        }

        //show();
        printf("%lld\n", dp[n][k]);
    }

    return 0;
}


