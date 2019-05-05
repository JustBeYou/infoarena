#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
const int nmax = 10000;

ull q, n, a, b;
int main() {
  //freopen("input", "r", stdin);

  scanf("%llu", &q);
  for (uint i =0;i<q;i++) {
    scanf("%llu%llu%llu", &n, &a, &b);
    
    ull sol;
      sol = min({n * a, (n / 2) * b + (n % 2) * a});
      printf("%llu\n", sol);
  }

  return 0;
}
