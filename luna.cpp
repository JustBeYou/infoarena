#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
typedef unsigned short ushort;
const int nmax = 51;
const int tmax = 2501;
uint M[nmax][nmax]; // the actual map
uint L[nmax][nmax]; // stores the lengths on vertical direction
bool DP[tmax][nmax][nmax]; // DP[t][i][j] = true if there is possible to create a square of (i, j) dimensions for country t
bool E[tmax]; // true if a country exists
uint n, m, k;

int main() {
    freopen("luna.in", "r", stdin);
    freopen("luna.out", "w", stdout);

    scanf("%u %u", &n, &m);
    for (uint i = 1; i <= n; i++) {
        for (uint j = 1; j <= m; j++) {
            scanf("%u", &M[i][j]);

            E[M[i][j]] = true;
            if (M[i][j] == M[i - 1][j]) L[i][j] = L[i - 1][j] + 1;
            else                        L[i][j] = 1;
        }
    }

    for (uint i = 1; i <= n; i++) {
        for (uint j = 1; j <= m; j++) {
            uint height = n + 1;
            for (uint k = j; k >= 1; k--) {
                height = min(height, L[i][k]);
                if (M[i][k] == M[i][j]) {
                    DP[M[i][j]][height][j - k + 1] = DP[M[i][j]][j - k + 1][height] = true;
                }
                else break;
            }
        }
    }

    uint t, w, h;
    scanf("%u", &k);
    for (uint i = 0; i < k; i++) {
        scanf("%u %u %u", &t, &w, &h);
        if (!E[t]) {
            printf("Tara de provenienta nu are parcele pe Luna!\n");
        } else if (w > 50 || h > 50) {
            printf("Cererea nu poate fi satisfacuta!\n");
        } else if (DP[t][w][h] || DP[t][h][w]) {
            printf("Cererea poate fi satisfacuta!\n");
        } else {
            printf("Cererea nu poate fi satisfacuta!\n");
        }
    }

    return 0;
}


