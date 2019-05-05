#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char uchar;
const int nmax = 20;

int n, m;
vector<int> G[nmax];
int cost[nmax][nmax];
int dp[(1 << 18)][nmax];
int pows[nmax + 1];
const int INF = 1000000000;

void precalc() {
    for (int i = 0; i <= nmax;i ++) {
        pows[i] = 1 << i;
    }
}

int solve(int state, int last) {
    if (dp[state][last] != -1) {
        return dp[state][last];
    }

    //cout << "solving "<< last << " "; printbin(state);
    dp[state][last] = INF;
    for (auto v: G[last]) {
        if (pows[v] & state) {
            if (v == 0 && state != pows[last] + 1) continue;
            dp[state][last] = min(dp[state][last], solve(state ^ pows[last], v) + cost[v][last]);
        }
    }

    return dp[state][last];
}

int main() {
    freopen("hamilton.in", "r", stdin);
    freopen("hamilton.out", "w", stdout);

    precalc();

    scanf("%d %d", &n, &m);
    for (int i = 0, x, y, c; i < m; i++) {
        scanf("%d %d %d", &x, &y, &c);
        G[y].push_back(x);
        cost[x][y] = c;
    }

    memset(cost, INF, sizeof(cost));
    memset(dp, -1, sizeof(dp));

    dp[pows[0]][0] = 0;
    int sol = INF;
    for (auto v: G[0]) {
        //cout<<v<<endl;
        sol = min(sol, solve(pows[n] - 1, v) + cost[v][0]);
    }

    if (sol == INF) {
        puts("Nu exista solutie");
    } else {
        printf("%lld\n", sol);
    }

    return 0;
}


