#include <bits/stdc++.h>

using namespace std;

const int nmax = 100001;
int v[nmax], tail[nmax], before[nmax], sol[nmax];
int n, length, last;

int find_best(int value) {
  int l = -1, r = length;
  int m = 0;

  while (l + 1< r) {
    m = l + (r - l) / 2;

    if (v[tail[m]] < value) {
        l = m;
    } else {
        r = m;
    }
  }
  return r;
}

int main() {
  freopen("scmax.in", "r", stdin);
  freopen("scmax.out", "w", stdout);

  cin >> n;
  for (int i=0;i<n;i++) {
    cin>>v[i];
    tail[i]=0;
    before[i]=-1;
  }

  for (int i = 1; i < n; i++) {
    if (v[i] < v[tail[0]]) {
      tail[0] = i;
    } else if (v[i] > v[tail[length]]) {
      tail[length + 1] = i;
      before[i] = tail[length];
      last = i;
      length++;
    } else {
      int best = find_best(v[i]);
      tail[best] = i;
      before[i] = tail[best - 1];
    }
  }

  cout << length + 1 << "\n";
  int tmp = length;
  while (before[last] != -1) {
    sol[length--] = v[last];
    last = before[last];
  }
  sol[0] = v[last];

  for (int i = 0; i <= tmp; i++) {
    cout << sol[i] <<" ";
  }
  cout << "\n";

  return 0;
}
