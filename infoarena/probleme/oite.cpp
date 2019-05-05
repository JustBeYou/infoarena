#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
const int nmax = 1025;
uint A[nmax];
uint C, L;
uint sol;

unordered_map<uint, uint> sums;

int main() {
    freopen("oite.in", "r", stdin);
    freopen("oite.out", "w", stdout);

    scanf("%u%u", &C, &L);
    for (uint i = 0; i < C; i++) {
        scanf("%u", &A[i]);
    }

    for (uint i = 0; i < C; i++) {
        for (uint j = i + 1; j < C; j++) {
            if (A[i] + A[j] <= L) {
                sol += sums[L - A[i] - A[j]];
            }
        }

        // j e unsigned. cand ar trebui sa coboare sub 0 va deveni MAX INT
        for (uint j = i - 1; j < C; j--) {
            sums[A[i] + A[j]]++;
        }
    }

    printf("%d\n", sol);

    return 0;
}
