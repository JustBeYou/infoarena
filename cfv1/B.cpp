#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
const int nmax = 10000;

int main() {
  //freopen("input", "r", stdin);

  int t;
  int n;
  string s;
  cin>>t;
  for (int i = 0; i < t; i++) {
    cin >> n;
    cin >> s;
  
    if (n == 1){
      cout << "0\n";
      continue;
    }

    if (s[0] == '>' || s[n - 1] == '<') {
      cout << "0\n";
      continue;
    }

    int la=99999;
    int rb=0;
    for (int j = 0; j < n; j++) {
      if (s[j]=='>')la=min(la, j);
      if (s[j]=='<')rb=max(rb, j);
    }
    int sol = min(la, n-rb-1);

    int k = 9999999;
    for (int j = 0; j < n - 1; j++) {
      int tmp=j+1;
      if (s[j]=='<'){
        while (s[tmp++] != '>' && tmp < n) ;
        if (tmp < n) k = min(k, tmp - j);
      }
    }

    sol = min(k, sol);
    cout << sol << "\n";
  }

  return 0;
}
