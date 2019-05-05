#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char uchar;
const int nmax = 101;

const int modulo = (1 << 17) - 1;
struct node {
    int key;
    int val;
};
int total;
vector<int> existing;
vector<node> Hash[modulo];

void add(int key, int val) {
    int idx = key % modulo;

    for (auto &elem: Hash[idx]) {
        if (elem.key == key) {
            elem.val += val;
            return ;
        }
    }

    total++;
    if (Hash[idx].empty()) {
        existing.push_back(idx);
    }
    Hash[idx].push_back({key, val});
}

int main() {
    freopen("pariuri.in", "r", stdin);
    freopen("pariuri.out", "w", stdout);

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int m;
        scanf("%d", &m);
        for (int j = 0; j < m; j++) {
            int timp, bani;
            scanf("%d %d", &timp, &bani);
            add(timp, bani);
        }
    }

    printf("%d\n", total);
    for (auto idx: existing) {
        for (auto elem: Hash[idx]) {
            printf("%d %d ", elem.key, elem.val);
        }
    }
    printf("\n");

    return 0;
}

