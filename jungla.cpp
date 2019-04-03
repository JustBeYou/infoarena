#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char uchar;
const int nmax = 5005;

vector<int> G[nmax];
int level[nmax];
int before[nmax];
int n, m;

void reinit() {
    for (int i = 1; i <= n; i++) {
        level[i] = -1;
        before[i] = -1;
    }
}

int sol_cycle = INT_MAX;
int sol_node;
int sol_before[nmax];
int sol_u, sol_v;

void bfs(int root, int max_level) {
    int best_cycle = INT_MAX;
    int best_u, best_v;

    level[root] = 0;
    before[root] = root;

    queue<int> Q;
    Q.push(root);

    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();

        if (level[u] > max_level) {
            continue;
        }

        for (auto v: G[u]) {
            if (v == before[u]) {
                continue;
            } else if (level[v] == -1) {
                level[v] = level[u] + 1;
                before[v] = u;
                Q.push(v);
            } else {
                max_level = level[v] - 1;
                int cycle = level[u] + level[v] + 1;
                if (cycle < best_cycle) {
                    best_cycle = cycle;
                    best_u = u;
                    best_v = v;
                }
            }
        }
    }

    if (best_cycle < sol_cycle) {
        sol_cycle = best_cycle;
        sol_node = root;
        sol_u = best_u;
        sol_v = best_v;
        memcpy(sol_before, before, n + 1);
    }
}

int sol_vect_u[nmax];
int sol_vect_v[nmax];
void solution() {
    printf("%d\n", sol_cycle);

    int idx_u = 0;
    cout << sol_u << " " <<  sol_before[1] << endl;
    while (sol_before[sol_u] != sol_node) {
        sol_vect_u[idx_u++] = sol_u;
        sol_u = sol_before[sol_u];
    }
    sol_vect_u[idx_u++] = sol_u;

    int idx_v = 0;
    while (sol_before[sol_v] != sol_node) {
        sol_vect_v[idx_v++] = sol_v;
        sol_v = sol_before[sol_v];
    }
    sol_vect_v[idx_v++] = sol_v;

    printf("%d ", sol_node);
    for (int i = 0; i < idx_v; i++) {
        printf("%d ", sol_vect_v[i]);
    }
    for (int i = idx_u - 1; i >= 0; i--) {
        printf("%d ", sol_vect_u[i]);
    }
}

int main() {
    freopen("jungla.in", "r", stdin);
    //freopen("jungla.out", "w", stdout);

    scanf("%d %d", &n, &m);
    for (int i = 0, x, y; i < m; i++) {
        scanf("%d %d", &x, &y);
        G[x].push_back(y);
        G[y].push_back(x);
    }

    for (int i = 1; i <= n; i++) {
        reinit();
        bfs(i, sol_cycle / 2 + 1);
    }

    solution();

    return 0;
}


