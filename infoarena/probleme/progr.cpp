#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char uchar;
const int nmax = 2001;
uint v[nmax];

unordered_map<uint, uint> M;

int main() {
    freopen("progr.in", "r", stdin);
    freopen("progr.out", "w", stdout);

    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &v[i]);
        }
        sort(v, v + n, greater<uint>());

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                M[v[i] - v[j]]++;
            }
        }

        printf("%d\n", M.size());
        M.clear();
    }

    return 0;
}


