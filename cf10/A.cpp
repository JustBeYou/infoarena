#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
const int nmax = 100000 * 2;

uint n, k;
uint v[nmax];
unordered_map<uint, uint> M;

int main() {
  //freopen("input", "r", stdin);
  scanf("%u %u", &n, &k);

  ull sol = 0;
  for (uint i = 0; i < n; i++) {
    scanf("%u", &v[i]);
    v[i] %= k;
    
    if (v[i] == 0 && M[k]) {
      sol++;
      M[k]--;
    } else if (M[v[i]]) {
      sol++;
      M[v[i]]--;
    } else {
      M[k - v[i]]++;
    }
  }

  printf("%llu\n", 2ull * sol);

  return 0;
}
