#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
const int nmax = 10000;

int main() {
  //freopen("input", "r", stdin);
  ull n, m;
  scanf("%lld %lld", &n, &m);

  ull p2n = 0;
  while (n % 2 == 0) {
    p2n++;
    n /= 2;
  }
  ull p3n = 0;
  while (n % 3 == 0) {
    p3n++;
    n /= 3;
  }

  ull p2m = 0;
  while (m % 2 == 0) {
    p2m++;
    m /= 2;
  }
  ull p3m = 0;
  while (m % 3 == 0) {
    p3m++;
    m /= 3;
  }

  if (n != m || (p2n > p2m) || (p3n > p3m)) {
    printf("-1\n");
    return 0;
  }

  ull sol = p2m - p2n + p3m - p3n;
  printf("%lld\n", sol);

  return 0;
}
