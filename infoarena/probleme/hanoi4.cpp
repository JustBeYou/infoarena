#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char uchar;
const int nmax = 1010;
ll T[nmax];
ll n;

inline ll pow2(ll N) {
    return 1LL << N;
}

inline ll hanoi3(ll N){
    return pow2(N) - 1;
}

void build(ll N) {
    T[1] = 1;
    T[2] = 3;
    T[3] = 5;

    for (ll i = 4; i <= N; i++) {
        T[i] = 2 * T[i - 2] + hanoi3(2);

        for (ll k = 3; pow2(k) <= T[i]; k++) {
            T[i] = min(T[i], 2 * T[i - k] + hanoi3(k));
        }
    }
}

ull hanoi4(ull N) {
    return T[N];
}

int main() {
    freopen("hanoi4.in", "r", stdin);
    freopen("hanoi4.out", "w", stdout);

    scanf("%lld", &n);
    build(n);
    ll sol = hanoi4(n);
    printf("%lld\n", sol);

    return 0;
}


