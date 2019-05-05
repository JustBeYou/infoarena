#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char uchar;
const int nmax = 3 * 200005;
int v[nmax];
int n;

bool prime[nmax];
void calc() {
  prime[0]=prime[1] =false;

  memset(prime, true, 2 * n + 10);
  int k = 2 * n + 10;
  for (int i = 2; i <= sqrt(2 * n + 10); i++) {
    if (!prime[i]) continue;
    for (int j = 2, lim = k / i; j <= lim; j++) {
      prime[i * j] = false;
    }
  }
}

int main() {
  //freopen("input", "r", stdin);
  //freopen(".out", "w", stdout);

  scanf("%d", &n);
  calc();

  int cnt[3];
  cnt[2] = 0;
  cnt[1] = 0;
  for (int i = 0; i < n ; i++) {
    scanf("%d", &v[i]);
    cnt[v[i]]++;
  }

  if (cnt[2] == 0) { 
    for (int i = 0; i < n; i++) {
      printf("1 ");
    }
    printf("\n");
    return 0;
  } else if (cnt[1] == 0) {
    for (int i = 0; i < n; i++) {
      printf("2 ");
    }
    printf("\n");
    return 0;
  }

  printf("2 1 ");
  cnt[2]--;
  cnt[1]--;
  for (int i = 2; i < n; i++) {
    if (cnt[1] % 2 == 0 && cnt[1] != 0) {
      printf("1 1 ");
      i++;
      cnt[1] -= 2;
    } else if (cnt[2] != 0) {
      printf("2 ");
      cnt[2]--;
    } else {
      printf("1 ");
      cnt[1]--;
    }
  }

  return 0;
}

