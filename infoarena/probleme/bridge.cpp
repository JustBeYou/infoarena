#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char uchar;
const int nmax = 4002;
uchar bridge[nmax];
uint entrances[nmax];
// teleports[end point] = start points
vector<uint> teleports[nmax];
// 0 - good
// 1 - fragile
// 2 - bad
// 3 - teleport
uint n, m;
uint teleports_cnt;
const ull modulo = 666013;

// DP[K][I] = number of combinations to reach point I in K steps
uint DP[nmax][nmax];

int main() {
    freopen("bridge.in", "r", stdin);
    //freopen(".out", "w", stdout);

    scanf("%u %u", &n, &m);
    for (uint i = 1; i <= n; i++) {
        scanf("%u", &bridge[i]);
        if (bridge[i] == 3) {
            entrances[teleports_cnt++] = i;
        }
    }

    for (uint i = 0, x; i < teleports_cnt; i++) {
        scanf("%u", &x);
        teleports[x].push_back(entrances[i]);
    }

    DP[0][0] = 1;
    DP[1][1] = 1;

    for (uint i = 0; i <= n; i++) {
            cout << DP[0][i] << " ";
        } cout << endl;

    for (uint k = 1; k <= n; k++) {
        for (uint i = 2; i <= n; i++) {
            switch (bridge[i]) {
                case 0:
                    if (bridge[i - 1] != 3) DP[k][i] += DP[k - 1][i - 1];
                    if (bridge[i - 2] != 3) DP[k][i] += DP[k - 1][i - 2];
                    DP[k][i]

                    for (auto it: teleports[i]) {
                        DP[k][i] += DP[k - 1][it];
                    }
                    break;
                case 1:
                    if (bridge[i - 1] != 3) DP[k][i] += DP[k - 1][i - 1];

                    for (auto it: teleports[i]) {
                        DP[k][i] += DP[k - 1][it];
                    }
                    break;
            }
        }
        for (uint i = 0; i <= n; i++) {
            cout << DP[k][i] << " ";
        } cout << endl;
    }

    for (uint i = 0, x, k; i < m; i++) {
        scanf("%u %u", &x, &k);
        printf("%u\n", DP[k][x]);
    }

    return 0;
}


