#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char uchar;
const int nmax = 5001;

int n, t;
vector<int> G[nmax];
int white_gr[nmax];
int black_gr[nmax];
bitset<nmax> visited;
bitset<nmax> black;
ull sol;

void init_graph() {
    for (int i = 1; i < nmax; i++) {
        G[i].reserve(nmax / 2);
    }
}
void clear_graph() {
    sol =0;
    for (int i = 1; i <= n; i++) {
        G[i].clear();
        white_gr[i] = 0;
        black_gr[i] = 0;
    }
    //visited.reset();
    black.reset();
}

void dfs(int i) {
    visited[i] = true;

    for (auto j: G[i]) {
        if (!visited[j]) {
            dfs(j);
        }
    }

    if (white_gr[i] >= 3 || black_gr[i] >= 2) {
        black[i] = true;
        for (auto j: G[i]) {
            white_gr[j]--;
            black_gr[j]++;
        }
    }
}

ull cnt = 0;
void dfs_black(int i) {
    visited[i] = false;

    for (auto j: G[i]) {
        if (black[j] && visited[j]) {
            dfs_black(j);
        }
    }

    cnt += white_gr[i];
}

void dfs_white(int i) {
    visited[i] = false;
    for (auto j: G[i]) {
        if (!black[j] && visited[j]) {
            sol += 1;
            dfs_white(j);
        }
    }
}

void show() {
        for (int i=1;i<=n;i++){
        cout << i << " black: " << black[i] << " " << " " <<white_gr[i] << " " << black_gr[i] << endl;
        }cout<<endl;
}

int main() {
    freopen("tricolor.in", "r", stdin);
    freopen("tricolor.out", "w", stdout);

    init_graph();

    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);

        for (int i = 0, x, y; i < n - 1; i++) {
            scanf("%d %d", &x, &y);
            G[x].push_back(y);
            G[y].push_back(x);
        }
        for (int i = 1; i <= n; i++) {
            white_gr[i] = G[i].size();
        }
        //show();

        dfs(1);
        //show();


        for (int i = 1; i <= n; i++) {
            if (!visited[i]) continue;

            cnt = 0;
            if (black[i]) {
                dfs_black(i);
                sol += cnt * (cnt - 1) / 2;
            } else {
                dfs_white(i);
            }
        }
        printf("%llu\n", sol);

        clear_graph();
    }

    return 0;
}


