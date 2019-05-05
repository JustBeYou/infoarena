#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
const int nmax = 10000;

int v[100001];
int f[100001];
int g[100001];
int main() {
  //freopen("input", "r", stdin);
  int n;
  scanf("%d", &n);
  for(int i =0; i<n;i++) {
    scanf("%d", &v[i]);
    
  }

  f[0] = 1;
  for (int i = 1; i < n; i++) {
    if (v[i] == v[i - 1]) f[i] += f[i - 1] + 1;
    else f[i] = 1;
    
  }
  g[n - 1] = 1;
  for (int i = n - 2; i >= 0; i--) {
    if (v[i] == v[i + 1]) g[i] += g[i + 1] + 1;
    else g[i] = 1;
  }

  int sol = 0;
  for (int i = 0; i < n - 1; i++) {
    if (v[i] != v[i + 1]) {
      sol = max(sol, min(f[i], g[i + 1]) * 2);
    }
  }

  printf("%d\n", sol);

  return 0;
}
