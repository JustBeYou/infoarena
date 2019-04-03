#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input", "r", stdin);
  int x, y, z;
  int a, b, c;

  cin >> x >> y >> z;
  cin >> a >> b >> c;

  if (x > a) {
    cout << "NO\n";
    return 0;
  }

  a -= x;

  if (y > a + b) {
    cout << "NO\n";
    return 0;
  }

  if (y > a) {
    y -= a;
    a = 0;
    b -= y;
  } else if (y > b) {
    y -= b;
    b = 0;
    a -= y;
  } else {
    a -= y;
  }

  if (z > a + b + c) {
    cout << "NO\n";
    return 0;
  }

  cout << "YES\n";

    return 0;
}
