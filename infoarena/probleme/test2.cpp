#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char uchar;
const int nmax = 101;
uint v[nmax];

int main() {
    freopen("test2.in", "r", stdin);
    //freopen(".out", "w", stdout);

    ull a, b;
    cin >> a >> b;
    ull s = a + b;
    ull p = a * b;

    ull lcm = -1;
    ull sol_k = 0;
    for (int k = 0; k < 1000000; k++) {
        if (s + p * k)
    }

    return 0;
}

