#include <bits/stdc++.h>

using namespace std;

int v[10000];
int main() {
  freopen("ferma.in", "r", stdin);
  //freopen("ferma.out", "w", stdout);

  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  int sol = 0;
  for (int i = 0; i < k; i++) {
    int sum = 0;
    int start, finish, idx;
    int bestSum = INT_MIN;
    for (int j = 0; j < n * 2; j++) {
      if (v[j] == INT_MIN) continue;

      if (sum < 0) {
        sum = v[j % n];
        idx = j % n;
      } else {
        sum += v[j % n];
      }

      if (bestSum < sum) {
        bestSum = sum;
        start = idx;
        finish = j % n;
      }

    }

    sol += bestSum;
    for (int j = min(start, finish); j < max(start, finish); j++) v[j] = INT_MIN;
  }

  cout << sol << "\n";

  return 0;
}
