#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
const int nmax = 10000;

int main() {
  //freopen("input", "r", stdin);

  int n;
  cin >> n;
  pair<int, int> v[101];
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    v[i].first = x;
    v[i].second = y;
  }
  int k;
  cin >> k;
  int a = 0;
  for (int i = 0; i < n; i++) {
    if (k > v[i].second) a++;
    else break;
  }
  cout << n - a << "\n";

  return 0;
}
