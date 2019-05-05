#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char uchar;
const int nmax = 101;

pair<int, int> sol[200001];
int csol = 0;
int cap[4];
int cont[4];
int m;

void make_move(int src, int dest) {
    if (cont[src] + cont[dest] >= cap[dest]) {
        cont[src] -= cap[dest] - cont[dest];
        cont[dest] = cap[dest];
    } else {
        cont[dest] += cont[src];
        cont[src] = 0;
    }
    sol[csol++] = make_pair(src, dest);
}

int main() {
    freopen("comoara.in", "r", stdin);
    freopen("comoara.out", "w", stdout);

    cin >> cap[1] >> cap[2] >> cap[3] >> m;
    cont[3] = cap[3];

    while (cont[1] != m && cont[2] != m && cont[3] != m) {
        if (cont[2] != cap[2]) {
            make_move(3, 1);
            make_move(1, 2);
        } else {
            make_move(2, 3);
            make_move(1, 2);
        }
    }

    printf("%d\n", csol);
    for (int i = 0; i < csol; i++) {
        printf("%d %d\n", sol[i].first, sol[i].second);
    }


    return 0;
}


