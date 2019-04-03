#include <bits/stdc++.h>

using namespace std;

const int max_n = 501;
char v[max_n][max_n];
int n;
int sol;
int main() {
  //freopen("input", "r", stdin);
  //freopen(".out", "w", stdout);

  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> v[i][j];
    }
  }

  if (n < 3) {
    cout << "0\n";
    return 0;
  }

  for (int i=1;i<n-1;i++){
    for (int j=1;j<n-1;j++){
      if (v[i][j] == 'X' &&
          v[i -1][j - 1] == 'X' &&
          v[i - 1][j + 1] == 'X' &&
          v[i + 1][j - 1] == 'X' &&
          v[i + 1][j + 1] == 'X') sol++;
    }
  }

  cout << sol << "\n";

  return 0;
}
