#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
const int nmax = 10000;

int f(int x) {
  x += 1;
  while ((x % 10 == 0) && (x != 0)) {
    x = x / 10;
  }
  return x;
}

int main() {
  //freopen("input", "r", stdin);

  int n;
  scanf("%d", &n);
  map<int, bool> M;
  
  M[n]=true;
  while (n != 0) {
    int y = f(n);
    if (M[y]) break;
    M[y]=true;
    n=y;
  }
  printf("%d\n", M.size());

  return 0;
}
