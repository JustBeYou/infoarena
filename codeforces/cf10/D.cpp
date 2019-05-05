#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
const int nmax = 2 * 100000;

int n;
int a[nmax];
int b[nmax];

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);

        // Mainly for demonstration purposes, i.e. works but is overly simple
        // In the real world, use sth. like boost.hash_combine
        return ((h1 << 4) * 13 + 97 * (h2 >> 4));  
    }
};

unordered_map<pair<int, int>, int, pair_hash> S;
int any_sol;

int main() {
  //freopen("input", "r", stdin);

  scanf("%d",&n);
  for (int i =0;i<n;i++)scanf("%d", &a[i]);
  for (int i =0;i<n;i++)scanf("%d", &b[i]);

  for (int i = 0; i < n; i++) {
    if (a[i] == 0 && b[i] == 0) {
      any_sol++;
    } else if (a[i] == 0 && b[i] != 0) {
      continue;
    } else if (b[i] == 0) {
      S[make_pair(0, 0)]++;
    } else if (a[i] == b[i]) {
      S[make_pair(-1, 1)]++;
    } else if (a[i] == -b[i]) {
      S[make_pair(1, 1)]++;
    } else {
      int D = __gcd(a[i], b[i]);
      int A = abs(a[i] /D);
      int B = abs(b[i] /D);
      bool sgn = true;

      if ((a[i] > 0 && b[i] < 0) || (a[i] < 0 && b[i] > 0)) sgn = false;
      if (sgn) A = -A;
      S[make_pair(A, B)]++;
    }
  }

  int sol = 0;
  for (auto it: S) {
    sol = max(sol, it.second);
    //cout << it.first.first << "/" << it.first.second <<" " << it.second << endl;
  }

  printf("%d\n", sol+any_sol);

  return 0;
}
