#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char uchar;
const int nmax = 5001;
uint v[nmax];

int main() {
    freopen("grade.in", "r", stdin);
    freopen("grade.out", "w", stdout);

    uint n;
    scanf("%u", &n);
    for (uint i = 0; i < n; i++) {
        scanf("%u", &v[i]);
    }

    sort(v, v + n, greater<uint>());

    for (uint i = 0; i < n; i++) {
        for (int j = i + 1; v[i] && j < n; j++) {
            if (v[j]) {
                printf("%u %u\n", i + 1, j + 1);
                v[i]--;
                v[j]--;
            }
        }
    }

    return 0;
}


