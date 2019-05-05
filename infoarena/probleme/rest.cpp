#include <bits/stdc++.h>

using namespace std;

//typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
typedef uint ull;
const int nmax = 250002;

ull arbint[nmax * 4 + 66];
ull powers[nmax];
uint v[nmax];
uint n, p, b, m;

void precalc() {
    powers[0] = 1;
    for (int i = 1; i <= n; i++) {
        powers[i] = powers[i - 1] * b % p;
    }
}

// hacky :p
ull my_pow(ull base, ull power) {
    return powers[power];
}

void build(uint node, uint left, uint right) {
    if (left == right) {
        arbint[node] = v[left];
        return ;
    }

    uint mid = (left + right) / 2;
    build(2 * node + 1, left, mid);
    build(2 * node + 2, mid + 1, right);

    arbint[node] = (arbint[2 * node + 1] * my_pow(b, right - mid) + arbint[2 * node + 2]) % p;
}

void update(uint val, uint pos, uint node, uint left, uint right) {
    if (left == right) {
        arbint[node] = val;
        return ;
    }

    uint mid = (left + right) / 2;
    if (pos <= mid) update(val, pos, 2 * node + 1, left, mid);
    else            update(val, pos, 2 * node + 2, mid + 1, right);

    arbint[node] = (arbint[2 * node + 1] * my_pow(b, right - mid) + arbint[2 * node + 2]) % p;
}

ull result = 0;
void query(uint A, uint B, uint node, uint left, uint right) {
    if (A <= left && B >= right) {
        uint mid = B - right;
        result += arbint[node] * my_pow(b, mid);
        result %= p;
        return ;
    }

    uint mid = (left + right) / 2;
    if (A <= mid) query(A, B, 2 * node + 1, left, mid);
    if (B >  mid) query(A, B, 2 * node + 2, mid + 1, right);
}

int main() {
    freopen("rest.in", "r", stdin);
    freopen("rest.out", "w", stdout);

    scanf("%u %u %u", &n, &b, &p);
    precalc();
    for (uint i = 0; i < n; i++) {
        scanf("%u", &v[i]);
    }
    scanf("%u", &m);

    build(0, 0, n - 1);


    for (uint i = 0; i < m; i++) {
        uint a, x, y;
        scanf("%u %u %u", &a, &x, &y);

        if (a == 1) {
            update(y, x - 1, 0, 0, n - 1);
        } else {
            result = 0;
            query(x - 1, y - 1, 0, 0, n - 1);
            printf("%llu\n", result);
        }
    }

    return 0;
}


