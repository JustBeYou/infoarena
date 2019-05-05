#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
const int nmax = 2 * 100005;


ull sol;
ull n, m, k;
ull v[nmax]; 
int main() {
  //freopen("input", "r", stdin);
  scanf("%llu%llu%llu", &n, &m, &k);
  for (ull i=0;i<n;i++) {
    scanf("%llu", &v[i]);
  }

  sort(v, v+n);
  if (n == 1) {
    printf("%llu\n", v[0] * k);
    return 0;
  }

  ull d = m / (k + 1);
  sol += (k * v[n - 1] + v[n - 2]) * d;
  ull dif = m - d * (k + 1);
  sol += dif * v[n - 1];

  printf("%llu\n", sol);

  return 0;
}
