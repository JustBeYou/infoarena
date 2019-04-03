#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
const int nmax = 2 * 100000;

ll hp, n;
ll v[nmax];
ll s;

int main() {
  freopen("input", "r", stdin);

  ll ming = 1000000000;
  ll posg = 0;

  scanf("%lld %lld", &hp, &n);
  for (int i = 0; i < n; i++) {
    scanf("%lld", &v[i]);
    s += v[i];

    if (ming > v[i]) {
      ming = v[i];
      posg = i;
    }

    if (hp + s <= 0) {
      printf("%d", i + 2);
      return 0;
    }
  }

  if (s >= 0) {
    printf("-1\n");
    return 0;
  }

  ll left = 1;
  ll right = hp + 1;
  ll sol = hp + 5;
  ll mid;
  printf("%lld\n", posg); 
  printf("%lld\n", s);
  while (left <= right) {
    mid = (left + right) /2;
    printf("%lld\n", mid);
    ll d = mid / n;
    ll r = mid % n;
    printf("%lld %lld\n", d, r);

    ll k = hp;
    k += d * s;
    for (int i = 0; i < r; i++) {
      cout<<v[(i + posg) % n]<<endl;
      k += v[(i + posg) % n];
    }

    if (k <= 0) {
      sol = min(mid, sol);
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }

  printf("%lld\n", sol);

  return 0;
}
