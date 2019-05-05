#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
const int nmax = 100002;
uint n, m;

uint v[nmax];
int main() {
  //freopen("input", "r", stdin);

  scanf("%u", &n);
  for (int i =0;i<n;i++)scanf("%u", &v[i]);
  
  uint sol = 1;
  uint sol_num = v[0];

  uint cs = 1;
  uint cn = v[0];
  for (int i = 1; i < n; i++) {
    if (v[i] == v[i - 1]) {
      cs++;
    } else {
      if (cn > sol_num) {
        sol = cs;
        sol_num = cn;
      } else if (cn == sol_num) {
        sol = max(cs, sol);
      }

      cs = 1;
      cn = v[i];
    }
  }

  if (cn > sol_num) {
    sol = cs;
  } else if (cn == sol_num) {
    sol = max(cs, sol);
  }

  printf("%u\n", sol);

  return 0;
}
