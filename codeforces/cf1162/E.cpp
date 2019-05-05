#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char uchar;
const int nmax = 101;
uint v[nmax];

int n;

int main() {
    //freopen("input", "r", stdin);
    //freopen(".out", "w", stdout);

    cin>>n;
    int s = 0;
    for (int i = 0, x; i < n; i++){
    cin>>x;
    s^=x;
    }
    if (s==0) cout << "Bob\n";
    else cout << "Alice\n";

    return 0;
}

