
#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char uchar;
const int nmax = 200001;
int v[nmax];

int main() {
    freopen("and.in", "r", stdin);
    //freopen("and.out", "w", stdout);

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    int best = 0;
    for (int i = 0; i <= 32; i++) {

        int clen = 0;
        for (int j = 0; j < n; j++) {
            if (v[j] & (1<< i)) {
                clen++;
            } else {
                best = max(best, clen);
                clen = 0;
            }
        }
        best = max(best, clen);
    }

    printf("%d\n", best);

    return 0;
}


