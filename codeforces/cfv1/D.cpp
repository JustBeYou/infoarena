#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
const int nmax = 10000;

ull sol;
ull n;
int main() {
  //freopen("input", "r", stdin);
  
  cin >> n;
  for (ull i = 2; i < n; i++) {
    sol += i * (i + 1) * 1ULL;
  }

  cout << sol << "\n";

  return 0;
}
