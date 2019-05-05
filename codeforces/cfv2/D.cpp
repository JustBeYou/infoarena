#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
const int nmax = 10000;

void euclid(int a, int b, int &d, int &x, int &y)	
{
    if (!b) {
        d = a;
        x = 1;
        y = 0;
    } else {
        int x0, y0;
        euclid(b, a % b, d, x0, y0);
        x =  y0;
        y =  x0 - y0 * (a / b);
    }
}

ll m;

inline ll tetha(ll i, int a, int b, int x, int y, int d) {
  if (i % d == 1) return 0; // no solution
  
  x = x * (i/d);
  y = y * (i/d);

  if (x < 0 || y > 0) {
    int k1 = (abs(x) * d) / b + 1;
    int k2 = (abs(y) * d) / a + 1;
    int k = max(k1, k2);
   
    x = x + k * b / d;
    y = y - k * a / d;
  }

  printf("i = %d\n(x, y) = (%d, %d)\n", i, x, y);
  return 0;
}

int main() {
  freopen("input", "r", stdin);
  int a, b;

  scanf("%lld %d %d", &m, &a, &b);
  int x, y, d;
  euclid(a, b, d, x, y);

  ll sol = m+1;
  for (ll i = 1; i <= m; i++) {
    sol += tetha(i, a, b, x, y, d);
  }
  printf("%lld\n", sol);

  return 0;
}
