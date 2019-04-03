#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
const int nmax = 150;
int freq[nmax];
ull sum, sol;
int n;

int main() {
  //freopen("input", "r", stdin);

  cin >> n;
  for (int i = 0, x;i < n;i++) {
    cin >> x;
    freq[x]++;
    sum+=x;
  }
  
  sol=sum;
  for (int a = 1; a < 101; a++) {
    for (int b = 1; b < 101; b++) {
      if ((a==b && freq[a]>1) || (a!=b && freq[a]&&freq[b])) {
        for (int d = 2; d <= a; d++) {
          if (a % d == 0) {
            sol = min(sol, sum - a - b + a / d + b * d);         
          }
        }
      }
    }
  }

  cout << sol << "\n";
  
  return 0;
}
