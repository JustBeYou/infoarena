#include <bits/stdc++.h>

using namespace std;

const int max_n = 1200;
int n, k, l;

struct step {
    int x;
    int y;
};
step ladder[max_n];

struct elem {
    int p;
    int c;

    const bool operator< (const elem& rhs) const {
        if (p == rhs.p) {
            return c < rhs.c;
        }

        return p < rhs.p;
    }
};
elem dp[max_n];

int main() {
    freopen("scara3.in", "r", stdin);
    freopen("scara3.out", "w", stdout);

    cin >> n;
    cin >> k;
    for (int i = 0, pos, x; i < k; i++) {
        cin >> pos >> x;
        ladder[pos - 1].x = x;
    }
    cin >> l;
    for (int i = 0, pos, y; i < l; i++) {
        cin >> pos >> y;
        ladder[pos - 1].y = y;
    }

    for (int i = 0; i < n; i++) {
        dp[i].p = dp[i].c = INT_MAX;
    }

    elem temp;
    dp[0].p = 1;
    dp[0].c = 0;
    for (int i = 0; i < n; i++) {
        // default move
        temp.p = dp[i].p + 1;
        temp.c = dp[i].c;
        dp[i + 1] = min(temp, dp[i + 1]);

        // free moves
        for (int j = 1; 
             j <= ladder[i].x && i + j < n; 
             j++) {
            dp[i + j] = min(temp, dp[i + j]);
        }

        // paid moves
        for (int j = ladder[i].x + 1; 
             j <= ladder[i].y * 2 && i + j < n; 
             j++) {
            
            temp.c = dp[i].c + 
                     (j % 2 == 0 ? j : j + 1) / 2;
            dp[i + j] = min(temp, dp[i + j]);
        }
    }

    cout << dp[n - 1].p << " " << dp[n - 1].c << "\n";

    return 0;
}
