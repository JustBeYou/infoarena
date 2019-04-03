#include <bits/stdc++.h>

using namespace std;

typedef long long unsigned ull;
ull T, P;
const ull nmax = 301;
ull dp[nmax][nmax];

int main() {
  freopen("basket.in", "r", stdin);
  freopen("basket.out", "w", stdout);


  scanf("%llu %llu", &T, &P);
  for (ull i = 1; i < nmax; i++) {
    dp[i][0] = 1;
    for (ull j = 1; j < i; j++) {
      dp[i][j] = (((i - j) * dp[i - 1][j - 1]) % P + ((j + 1) * dp[i - 1][j]) % P) % P;
    }
  }

  for (ull i = 0, n, m; i < T; i++) {
    scanf("%llu %llu", &n, &m);
    printf("%llu\n", dp[n][m]);
  }

  return 0;
}
