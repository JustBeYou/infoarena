#include <bits/stdc++.h>

using namespace std;

int main() {
  freopen("ssm.in", "r", stdin);
  freopen("ssm.out", "w", stdout);

  int v, best = -(1 << 17);
  int c_start;
  int start, finish;
  int sum;

  int n;
  scanf("%d", &n);

  sum = 0;
  c_start =start =finish = 0;

  for (int i = 0; i < n; i++) {
    scanf("%d", &v);

    if (sum < 0) {
      sum = v;
      c_start = i;
    } else {
      sum += v;
    }

    if (best < sum) {
      best = sum;
      start = c_start;
      finish = i;
    }
  }

  cout << best <<" "<<start+1 <<" "<<finish+1<<"\n";

  return 0;
}
