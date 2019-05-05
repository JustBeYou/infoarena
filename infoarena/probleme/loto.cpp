#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char uchar;
const int nmax = 101;
int v[nmax];

struct elem {
    ll s;
    int a, b, c;

    bool operator() (const elem &left, const elem &right) {
        return left.s < right.s;
    }
};
vector<elem> a;

int main() {
    freopen("loto.in", "r", stdin);
    freopen("loto.out", "w", stdout);

    int n, S;
    scanf("%d %d", &n, &S);
    a.reserve(n * n * n + 1);
    for (int i = 0; i < n; i++) scanf("%d", &v[i]);

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            for (int k = j; k < n; k++) {
                ll tmp = v[i] + v[j] + v[k];
                a.push_back({tmp, v[i], v[j], v[k]});
            }
        }
    }

    sort(a.begin(), a.end(), elem());
    for (auto e: a) {
        int left = 0;
        int right = n - 1;
        ll target = S - e.s;
        while (left <= right) {
            int mid = (left + right) / 2;

            if (a[mid].s == target) {
                printf("%d %d %d %d %d %d\n", a[mid].a, a[mid].b, a[mid].c, e.a, e.b, e.c);
                return 0;
            } else if (a[mid].s < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }


    printf("-1\n");

    return 0;
}
