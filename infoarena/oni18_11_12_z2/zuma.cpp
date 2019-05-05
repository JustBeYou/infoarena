#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char uchar;
const int nmax = 600;
uint v[nmax];

int n, k;
string line;
struct elem {
    char c;
    int sz;
} zuma[nmax];
int elems;

void tokenize() {
    int sz = 1;
    for (int i = 0; i < n - 1; i++) {
        if (line[i] == line[i + 1]) {
            sz++;
        } else {
            zuma[elems++] = {line[i], sz};
            sz = 1;
        }
    }
    zuma[elems++] = {line[n - 1], sz};
}

void show() {
    for (int i = 0; i < elems; i++) {
        cout << zuma[i].c << " " << zuma[i].sz << endl;
    }
}

void solve() {
    bool ok = true;
    for (int i = 0; i < elems; i++) {
        if (zuma[i].sz < k) {
            ok = false;
            break;
        }
    }
    if (ok) {
        printf("0\n");
        return ;
    }


}

int main() {
    freopen("zuma.in", "r", stdin);
    freopen("zuma.out", "w", stdout);

    cin >> n >> k;
    getline(cin, line);
    getline(cin, line);

    tokenize();
    show();
    solve();

    return 0;
}
