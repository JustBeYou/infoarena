#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
const int nmax = 3 * 100005;

uint st[nmax];
struct song{
uint t,b;
};
struct cmp {
  bool operator() (const song& left, const song& right) {
    if (left.b == right.b) {
      return left.t > right.t;
    }
    return left.b < right.b;
  }
}
song s[nmax];
uint n, k;

int main() {
  freopen("input", "r", stdin);
  scanf("%u%u", &n, &k);
  for (uint i = 1; i <= n; i++) {
    scanf("%u%u", &s[i].t, &s[i].b);
  }

  return 0;
}
