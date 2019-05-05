#include <bits/stdc++.h>

using namespace std;

const int maxn = 500001;

long long sums[maxn];
long long remainders[maxn];
long long sol;
int n, k, a, b;

int main() {
  freopen("divk.in", "r", stdin);
  freopen("divk.out", "w", stdout);

  cin >> n >> k >> a >> b;

  for (int i = 1, x; i <= n; i++) {
    cin >> x;
    sums[i] += sums[i - 1] + x;
  }

  for (int i = 1; i <= n; i++) {
    if (i - b - 1 >= 0) remainders[sums[i - b - 1] % k]--;
    if (i - a >= 0) remainders[sums[i - a] % k]++;
    sol += remainders[sums[i] % k];
  }

  cout << sol << "\n";

  return 0;
}
