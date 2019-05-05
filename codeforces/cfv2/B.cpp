#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
const int nmax = 100001;

char cpy[nmax];
int main() {
  //freopen("input", "r", stdin);
  string s;
  cin >> s;

  int apos = -1;
  int to_add = 0;
  int len = 0;
  int pos=0;
  for (auto c: s) {
    if (c != 'a') cpy[len++] = c;
    else { to_add++;apos=pos;}
    pos++;
  }

  if (len % 2 == 1) {
    cout << ":(\n";
    return 0;
  }

  int half = len / 2;
  for (int i = 0; i < half; i++) {
    if (cpy[i] != cpy[i + half]) {
      cout << ":(\n";
      return 0;
    }
  }
  
  if (apos >= half + to_add) {
    cout << ":(\n";
    return 0;
  }
  for (int i = 0; i < half + to_add; i++) {
    cout << s[i];
  }
  cout << "\n";

  return 0;
}
