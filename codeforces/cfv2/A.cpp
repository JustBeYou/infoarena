#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
const int nmax = 10000;

int main() {
  //freopen("input", "r", stdin);
  int af = 0, of = 0;
  string s;
  cin >> s;

  int len = s.size();
  for (auto c: s) {
    if (c == 'a') af++;
    else of++;
  }

  if ((float)af > ((float)len / 2.0)) {
    cout << len << "\n";
    return 0;
  } else {
    for (int i = len - 1, j = of - 1; i >= 0 && of >= 0; i--, j--) {
      if ((float)af > ((float)i / 2.0)) {
        cout << i << "\n";
        return 0;
      }
    }
  }

  return 0;
}
