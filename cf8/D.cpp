#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
const int nmax = 10000;

ull n, m;
ull v[101];
ull sum[101];

int main() {
  freopen("input", "r", stdin);
  scanf("%llu%llu",&n, &m);
  for (uint i =1;i<=n;i++){
    scanf("%llu", &v[i]);
  }
  sort(v, v+n);

  ull sol = 0;
  while (true) {
    ull val = -1;
    
    ull csum = 0;
    for (uint i =1;i<=n;i++) {
      for (uint j=i+1;j<=n;j++){
        for (uint k=i;k<=j;k++){
          if (v[k] != -1) csum += v[k];
        }
        csum -= (j - i + 1) * (j - i) / 2;

        if (csum <= m && csum >= val) {
          val = csum;
          for (uint k=i;k<=j;k++)v[k]=-1;
        }
      }
    }


    if (val == -1) {
      printf("-1\n");
      return 0;
    }

    m -= val;
    sol += 1;
    if (m == 0) break;
  }

  printf("%llu\n", sol);

  return 0;
}
