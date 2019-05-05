#include <bits/stdc++.h>

using namespace std;

typedef signed long long ll;

vector<pair<ll, ll>> sol;
ll num;
int main() {
  freopen("armonica.in", "r", stdin);
  freopen("armonica.out", "w", stdout);

  ll a, b, c;
  cin >> b;
  sol.reserve(8000000 / 2);

  for (a = 1; a <= b; a++) {
    if ((2 * a - b) != 0 && 
        (b * a) % (2 * a - b) == 0) {
      c = (b * a) / (2 * a - b);
      if(c > 0) {
        num++;
        if (a!=c) num++;
        sol.push_back(make_pair(a, c));
      }
    }
  }

  cout << num << "\n";
  for (int i = 0;i<sol.size();i++){
    cout << sol[i].first << " " << sol[i].second << "\n";
    if (sol[i].first != sol[i].second) cout << sol[i].second << " " << sol[i].first << "\n";
  }

  return 0;
}
