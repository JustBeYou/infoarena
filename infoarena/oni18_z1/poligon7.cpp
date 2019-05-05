#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char uchar;
const int nmax = 2001;

struct point {
    long long x, y;
};

int task;
int t;
int n;
point poly[nmax];

inline long long pow2(long long x) {
    return x * x;
}

inline double dist(point p1, point p2) {
    return sqrt(pow2(p1.x - p2.x) + pow2(p1.y - p2.y));
}

double edges[nmax][nmax];
void build_graph() {
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            edges[i][j] = edges[j][i] = dist(poly[i], poly[j]);
        }
    }
}

int roots[nmax];
int ranks[nmax];
void build_disjoint() {
    for (int i = 1; i <= n; i++) {
        roots[i] = 0;
        ranks[i] = 0;
    }
}

int get_root(int x) {
    int t = x, y;
    while (roots[x] != 0) x = roots[x];

    while (roots[t] != 0) {
        y = roots[t];
        roots[t] = x;
        ranks[t] = 0;
        t = y;
    }

    return x;
}

bool check_set(int x, int y) {
    return get_root(x) == get_root(y);
}

void unite(int x, int y) {
    x = get_root(x);
    y = get_root(y);

    if (ranks[x] > ranks[y]) {
        roots[y] = x;
        ranks[x] += ranks[y];
    } else {
        roots[x] = y;
        ranks[y] += ranks[x];
    }
}

double cost;
vector<int> apm[nmax];
set<int> nodes;
void build_apm() {
    cost = 0;
    nodes.clear();
    for (auto &v: apm) {
        v.clear();
    }

    nodes.insert(1);
    for (int i = 0; i < n - 1; i++) {

        double min_val = 1e9;
        int edge_x, edge_y;
        for (auto x: nodes) {
            for (int y = 1; y <= n; y++) {
                if (x == y) continue;

                if (edges[x][y] < min_val && !check_set(x, y)) {
                    edge_x = x;
                    edge_y = y;
                    min_val = edges[x][y];
                }
            }
        }

        nodes.insert(edge_x);
        nodes.insert(edge_y);
        cost += min_val;
        apm[edge_x].push_back(edge_y);
        apm[edge_y].push_back(edge_x);
        unite(edge_x, edge_y);
    }
}

bitset<nmax> visited;
void dfs(int i) {
    visited[i] = true;
    for (auto node: apm[i]) {
        if (!visited[node]) {
            dfs(node);
            printf("%d %d\n", node, i);
        }
    }


}

void solve(bool show_moves)  {
    build_graph();
    build_disjoint();
    build_apm();

    if (show_moves) {
        visited.reset();
        dfs(1);
    } else {
        printf("%.12lf\n", cost);
    }
}

int main() {
    freopen("poligon7.in", "r", stdin);
    freopen("poligon7.out", "w", stdout);

    scanf("%d", &task);
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%lld %lld", &(poly[i].x), &(poly[i].y));
        }

        if (task == 1) {
            solve(false);
        } else {
            solve(true);
        }
    }

    return 0;
}


