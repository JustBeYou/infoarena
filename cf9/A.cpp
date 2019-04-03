#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
const int nmax = 10000;

int main() {
  //freopen("input", "r", stdin);
  int a,b,c,d;
  cin >> a>>b>>c>>d;
  
  if (a == d && a > 0) {
    cout << "1\n";
  } else if (a == d && a == 0 && c == 0) {
    cout << "1\n";
  } else {
    cout << "0\n";
  }

  return 0;
}
