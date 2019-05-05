#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char uchar;
const int nmax = 50001 * 2;

#define RED 0
#define WHITE 1
#define BLACK 2

vector<int> white[nmax];
int rank_white[nmax / 2 + 5];
vector<int> black[nmax];
int rank_black[nmax / 2 + 5];
int red[nmax];
int t, n;
bitset<nmax> visited;

void clear_graphs() {
    for (int i = 1; i <= n; i++) {
        white[i].clear();
        red[i] = 0;
    }
    for (int i = n + 1; i <= n * 2; i++) {
        black[i].clear();
        red[i] = 0;
    }
    visited.reset();
}

void dfs(int node, int edge_color) {
    printf("%d ", node);
    visited[node] = true;

    int node_color = node > n ? BLACK : WHITE;

    switch (edge_color) {
        case RED:
            switch (node_color) {
                case WHITE:
                    for (auto next_node: white[node]) {
                        if (!visited[next_node]) {
                            dfs(next_node, WHITE);
                        }
                    }
                    break;

                case BLACK:
                    for (auto next_node: black[node]) {
                        if (!visited[next_node]) {
                            dfs(next_node, BLACK);
                        }
                    }
                    break;
            }
            break;

        case WHITE:
        case BLACK:
            if (!visited[red[node]]) {
                dfs(red[node], RED);
            }
            break;
    }
}

int main() {
    freopen("dungeon.in", "r", stdin);
    freopen("dungeon.out", "w", stdout);

    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        int x, y;
        for (int i = 0; i < n - 1; i++) {
            scanf("%d %d", &x, &y);
            white[x].push_back(y);
            white[y].push_back(x);
        }
        for (int i = 0; i < n - 1; i++) {
            scanf("%d %d", &x, &y);
            black[x].push_back(y);
            black[y].push_back(x);
        }
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &x, &y);
            red[x] = y;
            red[y] = x;
        }
        for (int i = 1; i <= n; i++) {
            rank_white[i] = white[i].size();
            rank_black[i] = black[i + n].size();
        }
        sort(rank_white + 1, rank_white + n + 1);
        sort(rank_black + 1, rank_black + n + 1);
        bool ok = true;
        for (int i = 1; i <= n; i++) {
            if (rank_white[i] != rank_black[i]) {
                ok = false;
                break;
            }
        }
        if (!ok) {
            printf("-1\n");
            clear_graphs();
            continue;
        }

        dfs(1, RED);
        printf("\n");

        clear_graphs();
    }

    return 0;
}


