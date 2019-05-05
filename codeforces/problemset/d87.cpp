#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char uchar;
const int nmax = 200005;
const int vmax = 1000005;

uint v[nmax];

struct query {
    int left;
    int right;
    int idx;
};
query queries[nmax];
ull solution[nmax];

struct element {
    uint freq;
    ull sum;
};
element table[vmax];
ull current_sol;

int n, t;
int bucket;

struct cmp {
    bool operator() (const query& A, const query& B) {
        if ((A.left / bucket) == (B.left / bucket)) {
            return A.right < B.right;
        }
        return (A.left / bucket) < (B.left / bucket);
    }
};

void show() {
    for (int i = 1; i <= t; i++) {
        cout << queries[i].left << " " << queries[i].right << " " << queries[i].idx << endl;
    }
}

int main() {
    //freopen("input", "r", stdin);
    //freopen(".out", "w", stdout);

    scanf("%d %d", &n, &t);
    for (int i = 1; i <= n; i++) {
        scanf("%u", &v[i]);
    }
    bucket = floor(sqrt(n)) + 1;

    for (int i = 1, x, y; i <= t; i++) {
        scanf("%d %d", &x, &y);
        queries[i].left = x;
        queries[i].right = y;
        queries[i].idx = i;
    }
    sort(queries + 1, queries + t + 1, cmp());

    int current_left = 1;
    int current_right = 1;

    table[v[1]].freq = 1;
    table[v[1]].sum = 1ULL * v[1];
    current_sol = 1ULL * v[1];

    for (int i = 1; i <= t; i ++) {
        while (current_left < queries[i].left) {
            /// delete
            current_sol -= 1ULL * table[v[current_left]].sum;
            table[v[current_left]].freq -= 1;
            table[v[current_left]].sum = 1ULL * v[current_left] * table[v[current_left]].freq * table[v[current_left]].freq;
            current_sol += 1ULL * table[v[current_left]].sum;

            current_left++;
        }

        while (current_left > queries[i].left) {
            current_left--;

            /// insert
            current_sol -= 1ULL * table[v[current_left]].sum;
            table[v[current_left]].freq += 1;
            table[v[current_left]].sum = 1ULL * v[current_left] * table[v[current_left]].freq * table[v[current_left]].freq;
            current_sol += 1ULL * table[v[current_left]].sum;
        }

        while (current_right > queries[i].right) {
            /// delete
            current_sol -= 1ULL * table[v[current_right]].sum;
            table[v[current_right]].freq -= 1;
            table[v[current_right]].sum = 1ULL * v[current_right] * table[v[current_right]].freq * table[v[current_right]].freq;
            current_sol += 1ULL * table[v[current_right]].sum;

            current_right--;
        }

        while (current_right < queries[i].right) {
            current_right++;

            /// insert
            current_sol -= 1ULL * table[v[current_right]].sum;
            table[v[current_right]].freq += 1;
            table[v[current_right]].sum = 1ULL * v[current_right] * table[v[current_right]].freq * table[v[current_right]].freq;
            current_sol += 1ULL * table[v[current_right]].sum;
        }

        solution[queries[i].idx] = current_sol;
    }

    for (int i = 1; i <= t; i++) {
        printf("%llu\n", solution[i]);
    }

    return 0;
}

