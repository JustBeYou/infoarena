#include <bits/stdc++.h>

using namespace std;

const int max_m = 100005;
bitset<max_m> sol;
int K[max_m];
int rnds[max_m];
int main() {
    //freopen("input", "r", stdin);


    int n, m;
    int c_round =1;

    cin >> n >> m;
    int tmp;
    int s = n * (n + 1) / 2;
    for (int i = 0; i < m; i++) {
      rnds[i] = s;
    }

    for (int i=0; i<m;i++) {
      cin >>tmp;
      rnds[K[tmp]] -= tmp;
      if (rnds[K[tmp]] == 0) {
        sol[i] = 1;
      }
      K[tmp]++;
    }

    for (int i=0; i<m;i++) {
      cout << sol[i];
    }
    cout << "\n";

    return 0;
}
