#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
const int nmax = 10001;

int v[nmax];
int main() {
  //freopen("input", "r", stdin);

  int n;
  cin >> n;
  for (int i = 1; i<= n;i++) {
    cin >> v[i];
  }

  int sol = 1;
  int m = v[1];
  int i = 1;
  while (i < n) {
    m = max(v[i], m);

    while (i < m) { i++; m = max(v[i], m); }
    if (i >= n) break;
    sol++;
    i++;
  }
  cout << sol << "\n";

  return 0;
}
