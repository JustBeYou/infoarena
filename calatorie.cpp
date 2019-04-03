#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
const int nmax = 51;
const int hmax = 500;
const long long INF = 200000000000000000;
ll N[nmax];
ll H[nmax];
ll Hmax;
ll DP[nmax][hmax];
ll n, t;

inline ll pow4(ll x) {
    return x * x * x * x;
}

int main() {
    freopen("calatorie.in", "r", stdin);
    freopen("calatorie.out", "w", stdout);

    scanf("%lld", &t);
    while (t--) {
        scanf("%lld", &n);
        Hmax = 5;
        for (ll i = 1; i <= n - 1; i++) {
            scanf("%lld %lld", &N[i], &H[i]);
            Hmax += H[i];
        }

        for (ll i = 0; i <= n; i++) {
            for (ll j = 0; j <= hmax; j++) {
                DP[i][j] = INF;
            }
        }

        DP[2][0] = N[1];
        DP[2][H[1]] = 0;
        for (ll i = 2; i <= n; i++) {
            for (ll j = 0; j <= Hmax; j++) {
                if (DP[i - 1][j] == INF) continue;
                DP[i][j] = min(DP[i][j], DP[i - 1][j] + N[i - 1]);
                DP[i][j + H[i - 1]] = min(DP[i - 1][j], DP[i][j + H[i - 1]]);
            }
        }

        ll sol = INF;
        for (ll i = 0; i <= Hmax; i++) {
            sol = min(sol, DP[n][i] + pow4(1LL * i));
        }
        printf("Consumul minim = %lld.\n", sol);
    }

    return 0;
}


