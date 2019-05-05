#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
const int nmax = 30001;

struct node_t {
    uint best_place;
    uint lazy;
};
node_t arbint[nmax * 4 + 66];
uint n;

uint pos, val;
void update(uint idx, uint left, uint right) {
    if (left == right) {
        arbint[idx].best_place = val;
        return ;
    }

    uint mid = (left + right) / 2;
    if (pos <= mid) update(2 * idx + 1, left, mid);
    else            update(2 * idx + 2, mid + 1, right);

    arbint[idx].best_place = min(arbint[2 * idx + 1].best_place, arbint[2 * idx + 2].best_place);

}

void show() {
    for (uint i =0;i<n*4;i++){
        cout << arbint[i]<<" ";
    }cout <<endl;
}

int main() {
    freopen("schi.in", "r", stdin);
    //freopen(".out", "w", stdout);

    for (uint i =0;i<nmax*4+66;i++) {
        arbint[i].best_place=nmax+5;
        arbint[i].lazy=0;
    }

    scanf("%u", &n);
    for (uint i = 0, x; i < n; i++) {
        scanf("%u", &x);
        pos = i;
        val = x;
    }
    show();

    for (uint i = 0; i < n; i++) {
        break;
    }

    return 0;
}


