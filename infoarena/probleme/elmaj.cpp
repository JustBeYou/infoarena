#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char uchar;
const int nmax = 101;

int main() {
    freopen("elmaj.in", "r", stdin);
    freopen("elmaj.out", "w", stdout);

    int n;
    int candidat = -1;
    int k = 0;

    scanf("%d", &n);
    for (int i = 0, x; i < n; i++) {
        scanf("%d", &x);

        if (k == 0) {
            k = 1;
            candidat = x;
        } else if (candidat == x) {
            k++;
        } else {
            k--;
        }
    }

    if (candidat == -1) {
        puts("-1");
        return 0;
    }


    freopen("elmaj.in", "r", stdin);
    int cnt = 0;
    scanf("%d", &n);
    for (int i = 0, x; i < n; i++) {
        scanf("%d", &x);
        if (x == candidat) cnt++;
    }

    if (cnt >= n / 2 + 1) {
        printf("%d %d\n", candidat, cnt);
    } else {
        puts("-1");
    }

    return 0;
}


