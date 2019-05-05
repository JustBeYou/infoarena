#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char uchar;
const int nmax = 1e5 + 5;

int n, k;
int v[nmax];
int frq[nmax];
int fst[nmax];
int lst[nmax];

int main() {
    freopen("input", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> n >> k;
    for (int i = 1; i <= k ; i++ ){ 
        cin >> v[i];
        frq[v[i]]++;
        if (fst[v[i]] == 0) fst[v[i]] = i;
    }
    for (int i = k; i >= 1; i--) {
        if (lst[v[i]]==0)lst[v[i]]=i;
    }
    unsigned long long solution = 0;
    for (int i = 1; i <= n; i++) if (frq[i]==0)solution++;
    for (int i = 1; i < n; i++) {
        if (frq[i] >= 2 && frq[i + 1] >= 2) continue;

    }

    cout << solution << "\n";


    return 0;
}
