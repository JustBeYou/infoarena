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
    //freopen("input", "r", stdin);
    //freopen(".out", "w", stdout);

    int n, m, r;
    cin >> n >> m >> r;
    
    int a = INT_MAX;
    for (int i = 0, x; i < n; i++) {
      cin >> x;
      a=min(a, x);
    }
    int b= INT_MIN;
    for (int i = 0, x; i < m; i++) {
      cin >> x;
      b=max(b, x);
    }

    if (a < b) {
      int rsp = (r / a) * b + (r - (r/a)*a);
      cout << rsp <<"\n";
    } else {
      cout << r << "\n";
    }

    return 0;
}

