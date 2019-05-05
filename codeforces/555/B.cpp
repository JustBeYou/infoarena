#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
const int nmax = 10000;

unordered_map<int, int> M;
char a[300005];
int k[20];
int main() {
  //freopen("input", "r", stdin);

  int n;
  scanf("%d\n", &n);
  scanf("%s\n", a);
  
  for (int i = 1, x; i <= 9; i++) {
    scanf("%d", &x);
    k[i]=x;
    if (x >= i) M[i] = x;
  }

  for (int i = 0; i < n; i++) {
    if (M[a[i] - '0'] && M[a[i]-'0']>(a[i]-'0')) {
      while (M[a[i] - '0'] && i < n) {
        a[i] = (char)(M[a[i] - '0'] + '0');
        i++;
      }
      break;
    }
  }

  printf("%s\n", a);
  

  return 0;
}
