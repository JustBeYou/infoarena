#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
unordered_map<uint, bool> v;
uint A, B, C, D, E;
uint n, m;
uint sol;

void calc() {
    uint r1 = A;
    uint r2 = B;
    uint aux = 0;

    if (v[A]) {
        sol++;
        v[A] = false;
    }
    if (v[B]) {
        sol++;
        v[B] = false;
    }

    for (int i = 3; i <= m; i++) {
        aux = r2;
        r2 = (C * r2 + D * r1) % E;
        r1 = aux;

        if (v[r2]) {
            sol++;
            v[r2] = false;
        }
    }
}

int main() {
    freopen("muzica.in", "r", stdin);
    //freopen("muzica.out", "w", stdout);

    scanf("%d%d%d%d%d%d%d", &n, &m, &A, &B, &C, &D, &E);
    for (int i =0,x;i<n;i++){
        scanf("%d", &x);
        v[x] =true;
    }

    calc();
    printf("%d\n", sol);

    return 0;
}


