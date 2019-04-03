#include <bits/stdc++.h>

using namespace std;

const int max_n = 100000;

int v[max_n];
int main() {
  freopen("lautari.in", "r", stdin);
  freopen("lautari.out", "w", stdout);
  
  int sol =0;
  int n, p, q;
  cin >> n >> p>>q;
  for (int i =0;i < n; i++){
    cin >> v[i];
  }

  for (int i =0; i<n;i++) {
    set<int> s;

    int j = i;
    int mini = 0;
    while (s.size() < p && j < n) {
      s.insert(v[j]);
      j++;
    }

    if (s.size() == p) {
      sol += n -j + 1;
    }
  }

  cout << sol << "\n";

  return 0;
}
