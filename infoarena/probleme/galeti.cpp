#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

struct interval {
  ull left;
  ull right;
  ull type; 
};

void solve(ull left, ull right, ull effort) {
  stack<interval> S;

  while (left + 1!= right) {
    ull m = right - left + 1;

    interval T;
    T.left = left;
    T.right = right;
    if (effort >= 2 * m - 3) {
      T.type = 1;
      left = left + 1;
      effort = effort - m + 1;
    } else {
      T.type = 2;
      right = right - 1;
      effort = effort - 1;
    }
    S.push(T);
  }

  cout << right << " " << left << "\n"; 
  while (!S.empty()) {
    interval T = S.top();
    S.pop();

    if (T.type == 1) {
      cout << T.left + 1 << " " <<T.left << "\n";
    } else {
      cout << T.right << " " << T.left << "\n";
    }
  }
}

int main() {
  freopen("galeti.in", "r", stdin);
  //freopen("galeti.out", "w", stdout);
  
  ull n, e;
  cin >> n >> e;

  solve(1, n, e);
  
  return 0;
}
