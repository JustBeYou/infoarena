#include <bits/stdc++.h>

using namespace std;

int n;
int k = INT_MAX;
int v[1001];
int main() {
  //freopen("input", "r", stdin);
  cin >> n;

  int dig = 0;
  for (int i = 1 ; i <= 9;i++) {
    int tmp = n / i + (n % i == 0 ? 0 : 1);

    if (tmp < k && tmp <= n && tmp > 0) {
      k = tmp;
      dig = i;
    }
  }

  cout << k << "\n";
  for (int i = 0; i < k; i++) {
    cout << dig << " ";
  }

  if (n - (n / dig) * dig != 0) {
    cout << n - (n / dig) * dig;
  }
  cout << "\n";

  return 0;
}
