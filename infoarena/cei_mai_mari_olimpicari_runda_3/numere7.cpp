#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char uchar;
const int nmax = 101;

int main() {
    freopen("numere7.in", "r", stdin);
    freopen("numere7.out", "w", stdout);

    ull n, x;
    scanf("%llu %llu", &n, &x);
    int v[25];
    int i;
    while (x) {
        v[i++] = x % 10;
        x /= 10;
    }

    sort(v, v + i);
    do {
        if (--n == 0) break;
    } while (next_permutation(v, v + i));

    if (n) {
        printf("-1\n");
        return 0;
    }

    for (int j = 0; j < i; j++) {
            printf("%d", v[j]);
        }
    printf("\n");

    return 0;
}


