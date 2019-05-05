#include <bits/stdc++.h>

using namespace std;

const int max_n = 100000;
int n, m;
bitset<max_n> viz;

vector<int> G[max_n];
int sol[max_n], csol;
std::priority_queue<int, std::vector<int>, std::greater<int> > PQ;

int main() {
  //freopen("input", "r", stdin);
  //freopen(".out", "w", stdout);

  cin >> n >> m;
  for (int i =0, x, y;i<m;i++) {
    cin >> x >> y;
    x--; y--;
    G[x].push_back(y);
    G[y].push_back(x);
  }
  

  PQ.push(0);
  while (!PQ.empty() && csol < n) {
    int cnode = PQ.top();
    PQ.pop();
    if (viz[cnode]) continue;

    viz[cnode] = 1;
    sol[csol++] = cnode;

    for (int i = 0; i < G[cnode].size(); i++) {
      if (!viz[G[cnode][i]])PQ.push(G[cnode][i]);
    }
  }


  for (int i = 0; i < n; i++) {
    cout << sol[i] + 1 << " ";
  }
  cout << "\n";

  return 0;
}
