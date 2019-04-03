#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
const int nmax = 10000;

int n, v;
int sol;

int main() {
  //freopen("input", "r", stdin);
  
  cin >> n >> v;

  int cap = 0;
  for (int i = 0; i < n - 1; i++) {
    if (cap < v) {
      int dif = n - i - 1;
      if (dif > cap) {
        int to_fill = (cap + dif) > v ? v - cap : dif;
        sol += to_fill * (i + 1); 
        cap = v;
      }
    }

    cap--;
  }

  cout << sol << "\n";

  return 0;
}
