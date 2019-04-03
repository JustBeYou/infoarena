#include <bits/stdc++.h>

using namespace std;

const int nmax = 1024 + 2;
int A[nmax], B[nmax], dp[nmax][nmax];
int sol[nmax];

int main() {
  freopen("cmlsc.in", "r", stdin);
  freopen("cmlsc.out", "w", stdout);

  int n, m;
  cin >> n >> m;
  
  for (int i = 1; i <= n; i++) {
    cin >> A[i];
  }

  for (int j = 1; j <= m; j++) {
    cin >> B[j];
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (A[i] == B[j]) {
        dp[i][j] = 1 + dp[i - 1][j - 1]; 
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  
  int len = dp[n][m];
  int i = n, j = m;
  while (len) {
    if (A[i] == B[j]) {
      sol[len--] = A[i];
      i = i - 1;
      j = j - 1;
    } else {
      if (dp[i - 1][j] > dp[i][j - 1]) {
        i = i - 1;
      } else {
        j = j - 1;
      }
    }
  }

  cout << dp[n][m] << "\n";
  for (int i = 1; i <= dp[n][m]; i++) cout << sol[i] << " ";
  cout << "\n";

  return 0;
}
