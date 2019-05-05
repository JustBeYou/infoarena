#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char uchar;
const int nmax = 101;

int sums[(1 << 10)];
int v[10];
int pows[11];

int main() {
    freopen("numere8.in", "r", stdin);
    freopen("numere8.out", "w", stdout);
  
    for (int i = 0; i < 11; i++) pows[i] = 1 << i;

    for (int i = 0; i < 10; i++) {
        scanf("%d", &v[i]);
    }

    for (int i = 0; i < pows[10]; i++) {
        for (int j = 0; j < 10; j++) {
            if (i & pows[j]) sums[i] += v[j];
        }
    }

    int numpair = 0;
    int valmax = INT_MIN;
    int subset1, subset2;

    for (int i = 0; i < pows[10]; i++) {
        for (int j = i + 1; j < pows[10]; j++) {
            if ((i & j) == 0 && sums[i] == sums[j]) {
                numpair++;

                if (valmax < sums[i]) {
                    valmax = sums[i];
                    subset1 = i;
                    subset2 = j;
                }
            }
        }
    }

    printf("%d %d\n", numpair, valmax);
    for (int i = 0; i < 10; i++) {
        if (pows[i] & subset1) printf("%d ", v[i]);
    }
    printf("\n");
    for (int i = 0; i < 10; i++) {
        if (pows[i] & subset2) printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}

