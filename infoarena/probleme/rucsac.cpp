#include <bits/stdc++.h>

using namespace std;

const int nmax = 5000;
const int gmax = 10000;

typedef unsigned int uint; 
uint n, G, W[nmax], P[nmax];
uint dp[gmax];
uint sol;

int main() {
  freopen("rucsac.in", "r", stdin);
  freopen("rucsac.out", "w", stdout);

  cin >> n >> G;
  for (int i = 0; i < n; i++) {
    cin >> W[i] >> P[i];
  }

  for (int i = 0; i < n; i++) {
    for (int j = G - W[i]; j >= 0; j--) {
      dp[j + W[i]] = max(
            dp[j + W[i]],
            dp[j] + P[i]
          );
      sol = max(sol, dp[j + W[i]]);
    }
  }

  cout << sol << "\n";

  return 0;
}
