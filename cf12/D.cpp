#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
const int nmax = 10000;

char sleft[150001];
char sright[150001];
stack<int> vleft[30];
stack<int> vright[30];
vector<pair<int, int>> sol;
int main() {
  //freopen("input", "r", stdin);

  int n;
  scanf("%d", &n);
  scanf("%s", sleft);
  for (int i = 0; i < n; i++) {
    if (sleft[i] >= 'a' && sleft[i] <= 'z') {
      vleft[sleft[i] - 'a'].push(i + 1);
    } else {
      vleft[29].push(i + 1);
    }
  }
  scanf("%s", sright);
  for (int i = 0; i < n; i++) {
    if (sright[i] >= 'a' && sright[i] <= 'z') {
      vright[sright[i] - 'a'].push(i + 1);
    } else {
      vright[29].push(i + 1);
    }
  }

  for (int i = 0; i <= 'z' - 'a'; i++) {
    while (!vleft[i].empty() && !vright[i].empty()) {
      sol.push_back(make_pair(vleft[i].top(), vright[i].top()));
      vleft[i].pop();
      vright[i].pop();
    }

    while (!vleft[i].empty() && !vright[29].empty()) {
      sol.push_back(make_pair(vleft[i].top(), vright[29].top()));
      vleft[i].pop();
      vright[29].pop();    
    }

    while (!vleft[29].empty() && !vright[i].empty()) {
      sol.push_back(make_pair(vleft[29].top(), vright[i].top()));
      vleft[29].pop();
      vright[i].pop();
    }
  }
    
  while (!vleft[29].empty() && !vright[29].empty()) {
      sol.push_back(make_pair(vleft[29].top(), vright[29].top()));
      vleft[29].pop();
      vright[29].pop();
    } 

  printf("%d\n", sol.size());
  for (int i = 0; i < sol.size(); i++) {
    printf("%d %d\n", sol[i].first, sol[i].second);
  }

  return 0;
}
