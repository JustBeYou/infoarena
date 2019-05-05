#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char uchar;
const int nmax = 1000000000;
const int mmax = 10001;

int n, m;
int p[mmax];

int calc(int f, int n) {
    if (n == 1) return 1;

    if (f % 2 == 0) {
        return calc(f / 2, n / 2);
    }

    return n/2 + calc((f + 1) / 2, n / 2);
}

int main() {
    freopen("ultimulcartus.in", "r", stdin);
    freopen("ultimulcartus.out", "w", stdout);

    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &p[i]);
    }

    int k = 1;
    int tmp = 2;
    for (; tmp <= n; k++, tmp <<= 1) ;
    k--;

    long long int ops = n / 2;
    long long int sum = n / 2;
    long long int dif = n / 4;
    for (int i = 2; i <= k; i++) {
        ops += dif;
        sum += ops;
        dif *= 2;
    }
    printf("%lld\n", sum);

    printf("1\n");
    for (int i = 0; i < m; i++) {
        int sol = calc(p[i], n);
        printf("%d ", sol);
    }
    printf("\n");

    return 0;
}


