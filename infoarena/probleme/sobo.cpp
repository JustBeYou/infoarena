#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char uchar;
const int lmax = 2001;
const int nmax = 16;
const ll INF = 1e16;

void printbin(int x) {
    bitset<sizeof(x) * 8> a(x);
    cout << a << endl;
}

int n, l;
int op[2][lmax];
int cost[lmax];
ll dp[(1 << nmax) + 10];

int pows[nmax + 1];
inline void precalc() {
    for (int i = 0; i <= nmax; i++) {
        pows[i] = 1 << i;
    }
}

inline ll solve(int state) {
    if (dp[state] != -1) return dp[state];

    dp[state] = INF;
    for (int i = 0; i < l; i++) {
        dp[state] = min(dp[state], max(solve(state & op[0][i]), solve(state & op[1][i])) + cost[i]);
    }
    return dp[state];
}

int main() {
    freopen("sobo.in", "r", stdin);
    freopen("sobo.out", "w", stdout);

    precalc();
    scanf("%d %d\n", &n, &l);
    for (int i = 0; i < n; i++) {
        char sobo[lmax + 10];
        scanf("%s\n", sobo);
        //cout << sobo << endl;

        for (int j = 0; j < l; j++) {
            op[sobo[j] - '0'][j] |= pows[i];
        }
    }
    /*for (int i = 0; i < l; i++) {
        printbin(op[0][i]);
        printbin(op[1][i]);
    }*/

    for (int i = 0; i < l; i++) {
        scanf("%d", &cost[i]);
    }

    for (int i = 0; i < pows[n]; i++) {
        dp[i] = -1;
    }
    for (int j = 0; j < n; j++) {
        dp[pows[j]] = 0;
    }

    printf("%d\n", solve(pows[n] - 1));

    return 0;
}

