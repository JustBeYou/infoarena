#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
const int nmax = 10000;

int main() {
  //freopen("input", "r", stdin);
  int n;
  scanf("%d", &n);

  int csec = 0;
  int best = 0;
  int first = -1;
  int last = -1;
  for (int i = 0, x; i < n; i++) {
    scanf("%d",&x);

    if (x) {
      csec++;
      best = max(best, csec);

      if (last == -1 && i == n - 1) last = csec;
    } else {
      if (first == -1) first = csec;
      best = max(best, csec);
      csec = 0;
    }
  }
  if (last != -1)
    best = max(best, first + last);

  printf("%d\n", best);

  return 0;
}
