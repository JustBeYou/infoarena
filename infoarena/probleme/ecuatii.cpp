#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
const int nmax = 5;
int a[nmax];

const int mars_prime = (1 << 17) - 1;
inline int my_hash(int x) {
    x = abs(x);
    //return (x >> 17) + (x & ((1 << 17) - 1));
    return x % mars_prime;
}


struct node {
    int key;
    int value;
};
vector<node> H[mars_prime];

vector<node>::iterator find_key(int key) {
    int idx = my_hash(key);
    for (auto it = H[idx].begin(); it != H[idx].end(); ++it) {
        if (it->key == key) return it;
    }
    return H[idx].end();
}

void add(int key, int val) {
    int idx = my_hash(key);
    auto it = find_key(key);

    if (it == H[idx].end()) {
        H[idx].push_back({key, val});
    } else {
        it->value += val;
    }
}

int key_count(int key) {
    int idx = my_hash(key);
    auto it = find_key(key);
    if (it != H[idx].end()) return it->value;
    return 0;
}

inline int cube(int x) {
    return x * x * x;
}

int main() {
    freopen("eqs.in", "r", stdin);
    freopen("eqs.out", "w", stdout);

    for (int i = 0; i < 5; i++)
        scanf("%d", &a[i]);

    for (int i = -50; i < 51; i++) {
        if (i == 0) continue;
        for (int j = -50; j < 51; j++) {
            if (j == 0) continue;
            add(cube(i) * a[0] + cube(j) * a[1], 1);
        }
    }

    ull sol = 0;
    for (int i = -50; i < 51; i++) {
        if (i == 0) continue;
        for (int j = -50; j < 51; j++) {
            if (j == 0) continue;
            for (int k = -50; k < 51; k++) {
                if (k == 0) continue;
                sol += key_count(-(cube(i) * a[2] + cube(j) * a[3] + cube(k) * a[4]));
            }
        }
    }

    printf("%llu\n", sol);

    return 0;
}

