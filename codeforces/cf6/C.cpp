#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
const int nmax = 3 * 100000+5;
uint S[nmax];
int n;
unordered_map<uint,uint> freq;
ull sol;

int main() {
  //freopen("input", "r", stdin);

  uint tmp;
  cin >> n;
  for (int i= 1;i<=n;i++) {
    cin >>tmp;
    S[i] = S[i - 1] ^ tmp;
  }

  for (int i = 1; i<=n-1;i+=2) {
 
    freq[S[i - 1]]++;

    sol += freq[S[i + 1]];
  }
  freq.clear();
  for (int i = 2; i <=n-1;i+=2){
 
    freq[S[i-1]]++;

    sol += freq[S[i + 1]];
  }

  cout << sol << "\n";

  return 0;
}
