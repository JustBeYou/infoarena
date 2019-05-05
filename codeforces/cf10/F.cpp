#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
const int nmax = 2*100000+5;

vector<int> G[nmax];
bitset<nmax> visited;
int cnt = 0;

int n, m;
queue<int> Q;
void bfs(int node) {
  Q.push(node);

  visited[node] = true;
  while (!Q.empty() && cnt < n - 1) {
    int node = Q.front();
    Q.pop();

    for (auto it: G[node]) {
      if (!visited[it]) {
        Q.push(it);
        visited[it] = true;
        cnt++;
        printf("%d %d\n", node, it);
        if (cnt == n - 1) break;
      }
    }
  }
}

int main() {
  //freopen("input", "r", stdin);

  scanf("%d%d", &n,&m);
  for (int i =0, x, y;i<m;i++){
    scanf("%d%d", &x, &y);
    G[x].push_back(y);
    G[y].push_back(x);
  }

  int max_d = 0;
  int max_pos = 0;
  for (int i = 1; i<=n;i++){
    if (G[i].size() > max_d) {
      max_d = G[i].size();
      max_pos = i;
    }
  }

  bfs(max_pos);

  return 0;
}
