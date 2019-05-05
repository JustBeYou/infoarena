#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char uchar;
const int nmax = 200501;

vector<int> G[nmax];
int n, m;

int cnt;
int tree[nmax];
int in[nmax], out[nmax];

void dfs(int node, int root) {
    tree[cnt] = node;
    in[node] = cnt++;
    for (auto next_node: G[node]) {
        if (next_node != root) {
            dfs(next_node, node);
        }
    }
    out[node] = cnt;
}

// sum of red nodes
int seg_tree[6 * nmax + 66];

int target_elem;
void update(int node, int left, int right) {
    if (left == right) {
        seg_tree[node] = !seg_tree[node];
        return ;
    }

    int mid = (left + right) / 2;
    if (target_elem <= mid) {
        update(2 * node + 1, left, mid);
    } else {
        update(2 * node + 2, mid + 1, right);
    }

    seg_tree[node] = seg_tree[2 * node + 1] + seg_tree[2 * node + 2];
}

int target_left, target_right;
int result;
void query(int node, int left, int right) {
    //printf("QUERY %d %d %d\n", node, left, right);

    if (left == right && target_left <= left && left <= target_right && seg_tree[node] == 1
        && out[tree[left]] > target_right) {
        if (result == -1) result = left;
        result = min(result, left);
        return ;
    }

    int mid = (left + right) / 2;
    if (target_left <= left && right <= target_right) {
        if (seg_tree[2 * node + 1] > 0) {
            query(2 * node + 1, left, mid);
        }
        if (seg_tree[2 * node + 2] > 0) {
            query(2 * node + 2, mid + 1, right);
        }
    } else {
        if (target_left <= mid && seg_tree[2 * node + 1] > 0) {
            query(2 * node + 1, left, mid);
        }
        if (target_right > mid && seg_tree[2 * node + 2] > 0) {
            query(2 * node + 2, mid + 1, right);
        }
    }
}

void show() {
    for (int i = 1; i <= n; i++) {
        printf("i: %d - %d -> %d\n", i, in[i], out[i]);
    } cout << endl;
    /*for (int i = 0; i < cnt; i++) {
        cout << tree[i] << " ";
    }cout<<endl;*/
    for (int i = 0; i < cnt * 2; i++) {
        cout << seg_tree[i] << " ";
    }cout<<endl;
}

int main() {
    freopen("confuzie.in", "r", stdin);
    freopen("confuzie.out", "w", stdout);

    scanf("%d %d", &n, &m);
    for (int i = 0, x, y; i < n - 1; i++) {
        scanf("%d %d", &x, &y);
        G[x].push_back(y);
        G[y].push_back(x);
    }
    in[0] = out[0] = -1;
    dfs(1, 0);

    for (int i = 0, op, x, y; i < m; i++) {
        scanf("%d", &op);
        if (op == 0) {
            scanf("%d", &x);
            target_elem = in[x];
            update(0, 0, n - 1);
        } else if (op == 1) {
            scanf("%d %d", &x, &y);
            target_left = in[x];
            target_right = in[y];
            //show();
            //printf("QUERY NODES %d, %d -> %d, %d\n", x, y, in[x], in[y]);
            if (target_left > target_right) {
                swap(target_left, target_right);
            }
            result = -1;
            query(0, 0, n - 1);
            if (result == -1) printf("-1\n");
            else printf("%d\n", tree[result]);
        }
        //show();
    }

    return 0;
}


