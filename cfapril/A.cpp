#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
const int nmax = 10000;

  int n;
int sol = 0;
int v[100];
void solve(int left, int right) {
  if (right < left || left == 0 || right == 0 || left > n || right > n) return ;
  if (left == right) {
    sol = max(sol, 1);
    return ;
  }
  bool sorted = true;
  for (int i = left; i < right; i++) {
    if (v[i] > v[i + 1]) {sorted = false;break;}
  }

  if (sorted) {
    sol = max(sol, right - left + 1);
  } else {
    int mid = (left + right) / 2;
    solve(left, mid);
    solve(mid + 1, right);
  }
}

int main() {
  //freopen("input", "r", stdin);

  cin >> n;
  for (int i = 1; i <= n; i++) cin>>v[i];
  solve(1, n);

  cout << sol << endl;
  return 0;
}
