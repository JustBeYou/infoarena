#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char uchar;
const int nmax = 100001;
int v[2][nmax];
ll sums[2][nmax];
int n, m, q;
ll s;

inline void swap(int idx, int x, int y) {
    if (x > y) swap(x, y);

    sums[idx][x] = sums[idx][x] - v[idx][x] + v[idx][y];
    swap(v[idx][x], v[idx][y]);
}

inline int search_best(int idx, int left, int right, ll current) {
    int sgn = idx == 0 ? +1 : -1;
    int mid;
    int base = left;
    int rsp = -1;

    while (left <= right) {
        mid = (left + right) / 2;
        ll result = sgn * (sums[idx][mid] - sums[idx][base - 1]) + current;

        if (abs(result) <= abs(s)) {
            rsp = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return rsp;
}

int solve() {
    int b_idx = 1;
    int f_idx = 1;
    ll current_s = 0;

    while (b_idx <= n && f_idx <= m) {
        //cout << "Current S: " << current_s << endl;

        int best_b = search_best(0, b_idx, n, current_s);
        if (best_b != -1) {
            //cout << "Best B " << best_b << endl;
            current_s += sums[0][best_b] - sums[0][b_idx - 1];
            b_idx = best_b + 1;
            continue;
        }

        int best_f = search_best(1, f_idx, m, current_s);
        if (best_f != -1) {
            //cout << "Best F "  << best_f << endl;
            current_s -= sums[1][best_f] - sums[1][f_idx - 1];
            f_idx = best_f + 1;
            continue;
        }

        return 0;
    }

    return 1;
}

int main() {
    freopen("bfs2.in", "r", stdin);
    freopen("bfs2.out", "w", stdout);

    scanf("%d %d %d", &n, &m, &s);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &v[0][i]);
        sums[0][i] += sums[0][i - 1] + v[0][i];
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d", &v[1][i]);
        sums[1][i] += sums[1][i - 1] + v[1][i];
    }
    scanf("%d\n", &q);

    while (q--) {
        char c;
        int x, y;

        scanf("%c %d %d\n", &c, &x, &y);
        int idx = c == 'B' ? 0 : 1;

        //cout<<endl;
        swap(idx, x, y);
        int rsp = solve();
        printf("%d\n", rsp);
        //cout<<endl<<endl;
    }

    return 0;
}


