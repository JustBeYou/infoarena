#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char uchar;
const int nmax = 100001; // max number of elements in the vector
const int smax = 20006; // maximum sum of two elements

bitset<smax+5> sieve;
vector<uint> primes;
void build_sieve() {
    sieve.set();
    for (int i = 2; i <= (int) sqrt(smax); i++) {
        if (sieve[i]) {
            primes.push_back((uint) i);
            for (int j = 2, lim = smax / i; j <= lim; j++) {
                sieve[i * j] = false;
            }
        }
    }
}

uint v[nmax];
uint sums[smax];
int main() {
    //freopen("prim007.in", "r", stdin);
    //freopen("prim007.out", "w", stdout);
    build_sieve();
    ull sol = 0;
    uint n;
    scanf("%u",&n);
    for (uint i = 0; i < n; i++) {
        scanf("%u", &v[i]);
    }

    for (uint i = 0; i < n; i++) {
        for (uint j = 0; j < primes.size(); j++) {
            if (v[i] < primes[j]) sums[primes[j] - v[i]]++;
        }
        sol += sums[v[i]];
    }
    printf("%llu\n", sol);
    return 0;
}


