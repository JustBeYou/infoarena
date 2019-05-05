#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char uchar;
const int nmax = 101;
uint v[nmax];

char a[70][70];

int xdir[] = {0, 1, -1, 0, 0};
int ydir[] = {0, 0, 0, -1, 1};
int n;

inline bool check(int x, int y) {
    return x >= 0&&y>=0&& x < n && y < n;
}

int main() {
  //freopen("input", "r", stdin);
  //freopen(".out", "w", stdout);

  cin >> n;
  string line;
  getline(cin, line);
  for (int i = 0; i < n; i++) {
    getline(cin, line);
    for (int j = 0; j < n; j++) {
      a[i][j] = line[j];
    }
  }

  for (int i=0;i<n;i++){
    for (int j=0;j<n;j++){
      bool ok = true;
      for (int k = 0; k < 5; k++) {
        if (check(i+xdir[k], j+ydir[k]) && a[i+xdir[k]][j+ydir[k]] == '#') {
          ok=false;
          break;
        }
      }

      if (ok) {
        for (int k = 0; k <5;k++) {
          a[i+xdir[k]][j+ydir[k]]='#';
        }
      }
    }
  }

  bool ok=true;
  for (int i =0;i<n;i++){
    for (int j =0; j<n;j++) {
      if (a[i][j]=='.'){
        ok=false;
        i = n+1;j=n+1;
      }
    }
  }

  if(ok)cout<<"YES\n";
  else cout << "NO\n";
  return 0;
}

