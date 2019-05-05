#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
const int nmax = 2 * 100005;

int a[nmax];
int b[nmax];
int c[nmax];
int n;

int main() {
 //freopen("input", "r", stdin);
  
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);    
  }

  for (int i = 0; i < n; i++) {
    scanf("%d", &b[i]);
  }

  multiset<int> s(b, b + n);

  for (int i = 0; i < n; i++) {
    if (a[i] == 0) {
      auto it = s.lower_bound(0);
      c[i] = (a[i] + *it) % n;
      s.erase(it);
    } else {

      int complement = (n - a[i]);
      auto it = s.lower_bound(complement); 
      if (it == s.end()) {
        it = s.lower_bound(0);
      }

      c[i] = (a[i] + *it) % n;
      s.erase(it);
    }
    
    printf("%d ", c[i]);
  }
  printf("\n");

  return 0;
}
