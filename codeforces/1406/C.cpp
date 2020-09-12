#include <bits/stdc++.h>

using namespace std;

typedef unsigned int uint;
typedef unsigned long long ull;
typedef long long ll;

typedef vector<vector<int>> Graph;

const int maxn = 100005; 
Graph g(maxn);
int subtreeSize[maxn];
int maxChildSize[maxn];
bitset<maxn> visited;
int n;

template <typename T>
void printarray(T v[], uint n) {
    for (uint i = 0; i < n; i ++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

template <typename T>
void printvector(vector<T> v) {
    for (uint i = 0; i < v.size(); i ++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int target;

void dfs_subtrees(int root) {
    if (visited[root]) return;
    visited[root] = true;
    subtreeSize[root] = 1;

    int maxChild = 0;
    for (auto child: g[root]) {
        dfs_subtrees(child);
        subtreeSize[root] += subtreeSize[child];
        maxChild = max(maxChild, subtreeSize[child]);
    }

    maxChild = max(n - subtreeSize[root], maxChild);
    maxChildSize[root] = maxChild;
    target = min(target, maxChild);
}

int main() {
    //freopen("input.in", "r", stdin);

    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        g.clear();
        g.resize(n + 1);
        visited.reset();
        target = 9999999;

        for (int i = 0; i < n - 1; i++) {
            int x, y;
            cin >> x >> y;
            g[x].push_back(y);
        }

        for (int i = 1; i <= n; i++) dfs_subtrees(i);
        vector<int> centroids;
        for (int i = 1; i <= n; i++) {
            if (maxChildSize[i] == target) {
                centroids.push_back(i);
                }
        }

        if (centroids.size() == 1) {
            for (int i = 1; i <= n; i++) {
                if (g[i].size()) {
                    cout << i << " " << g[i][0] << "\n";
                    cout << g[i][0] << " " << i << "\n";
                    break;
                }
            }
        } else {
            int targetNode;
            for (auto node: g[centroids[0]]) {
                if (centroids[1] != node) {
                    cout << centroids[0] << " " << node << "\n";
                    cout << centroids[1] << " " << node << "\n";
                    break;
                }
            }
        }
    }

    return 0;
}