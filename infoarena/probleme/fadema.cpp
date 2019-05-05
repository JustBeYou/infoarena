#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char uchar;

bool matrix[1001][1001];
int W[1001][1001];
int H[1001][1001];
int n, m;

int main() {
    freopen("fadema.in", "r", stdin);
    freopen("fadema.out", "w", stdout);

    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x;
            scanf("%d", &x);
            matrix[i][j] = (bool) x; 
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i >= 1) {
                if (matrix[i - 1][j] == !matrix[i][j]) H[i][j] = H[i - 1][j] + 1;
                else H[i][j] = 1;
            } else {
                H[i][j] = 1;
            }

            if (j >= 1) {
                if (matrix[i][j - 1] == !matrix[i][j]) W[i][j] = W[i][j - 1] + 1;
                else W[i][j] = 1;
            } else {
                W[i][j] = 1;
            }
        }
    }

    int area = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            bool good = true;
            int h = H[i][j];
            area = max(area, h);

            for (int k = j - 1; k >= 0; k--) {
                good = (j - k + 1) <= W[i][j] && area < (j + 1) * h;
                if (!good) break;

                h = min(h, H[i][k]);
                area = max(area, (j - k + 1) * h);
            }
        }
    }
    printf("%d\n", area);

    return 0;
}

