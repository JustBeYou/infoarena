#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
const int nmax = 10000;

int main() {
  //freopen("input", "r", stdin);

  int n, k;
  cin >> n >> k;
  
  int sol = 0;

  int go, back;
  if (k < n - k + 1) {
    go = k;
    back = n - k;
  } else {
    go = n - k + 1;
    back = k - 1;
  }

  sol += 2 * go;
  sol += 2 * (go - 1);
  sol += 1;
  sol += 2 * back;
  sol += back;
//if (k == 1 || k == n) sol++;

  cout << sol << "\n";

  return 0;
}
