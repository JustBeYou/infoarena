#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
const int nmax = 2 * 100000;
int v[nmax];

int search_best(int l, int r, int val) {
  int mid;

  int sol = 1 << 17;
  while (l <= r) {
    mid = (l + r) / 2;

    if (v[mid] >= val) {
      sol = min(sol, mid);
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }

  return sol;
}

int n;
int main() {
  //freopen("input", "r", stdin);
  scanf("%u", &n);
  for (int i =0;i < n; i++){
    scanf("%u", &v[i]);
  }

  sort(v, v+n);

  int sol = 0;
  for (int i = 1; i < n; i++) {
    int to_find;
    if (v[i] >= 5) {
      to_find = v[i] - 5;
    } else {
      to_find = 0;
    }
    int j = search_best(0, i, to_find);
    sol = max(sol, i - j + 1);
  }
  printf("%u\n", sol);

  return 0;
}
