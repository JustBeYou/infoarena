#include <bits/stdc++.h>

using namespace std;

const int max_n = 100;
int n, k, e, s;
int v[max_n];
int sol = INT_MIN;

int main() {
    //freopen("input", "r", stdin);

    cin >> n >> k;
    for (int i =1;i<=n;i++){cin>>v[i];}

    for (int b = 1; b <=n; b++) {
      s = 0;
      e = 0;
      for (int  i = 1; i<=n;i++) {
        if ((i - b) % k == 0) {
          continue;
        } else if (v[i] == 1) {
          s++;
        } else {
          e++;
        }
      }

      sol = max(sol, abs(e - s));
    }

    cout << sol << "\n";

    return 0;
}
