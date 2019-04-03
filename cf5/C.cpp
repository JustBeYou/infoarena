#include <bits/stdc++.h>

using namespace std;

const int max_n = 100000 * 3 + 1;
unsigned long long v[max_n];
int n;

int main() {
  //freopen("input", "r", stdin);
  //freopen(".out", "w", stdout);
  
  cin >> n;
  for (int i = 0; i < n;i++) cin>>v[i];
  sort(v, v + n);
  
  unsigned long long sol = 0;
  for (int i = 0; i < n / 2; i++) {
    sol += (v[i] + v[n - i - 1]) * (v[i] + v[n - i - 1]);
  }

  cout << sol << "\n";

  return 0;
}
