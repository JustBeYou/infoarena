#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
const int modulo = 666013;
vector<int> Hash[modulo];

vector<int>::iterator find_value(int x) {
    int idx = x % modulo;
    for (auto it = Hash[idx].begin(); it != Hash[idx].end(); ++it) {
        if ((*it) == x) return it;
    }
    return Hash[idx].end();
}

bool check_value(int x) {
    return find_value(x) != Hash[x % modulo].end();
}

void insert_value(int x) {
    int idx = x % modulo;

    if (find_value(x) == Hash[idx].end())
        Hash[idx].push_back(x);
}

void delete_value(int x) {
    int idx = x % modulo;

    for (auto it = Hash[idx].begin(); it != Hash[idx].end(); ++it) {
        if ((*it) == x) {
            Hash[idx].erase(it);
            break;
        }
    }
}

int main() {
    freopen("hashuri.in", "r", stdin);
    freopen("hashuri.out", "w", stdout);

    int n;
    scanf("%d", &n);
    for (int i = 0, op, x;i < n;i++) {
        scanf("%d %d", &op, &x);
        if (op == 1) insert_value(x);
        else if (op == 2) delete_value(x);
        else printf("%d\n", check_value(x));
    }

    return 0;
}
