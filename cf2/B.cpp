#include <bits/stdc++.h>

using namespace std;

const int max_n = 2 * 100000;
int n,k;
char v[max_n];
int freq[300];

int main() {
    freopen("input", "r", stdin);

    cin >> n >> k;
    for (int i=0;i<n;i++) {
    cin>>v[i];
    }

    
    if (k != 1) {
    int c_len = 0;
    for (int i =1;i<n;i++) {
      if (v[i] == v[i - 1]) {
        if (c_len == 0) {
          c_len = 2;
        } else {
          c_len++;
        }
      }

      if (c_len == k) {
        c_len = 0;
        freq[v[i]]++;
        i++;
      }
    }
    }

    if (k == 1) {
      for (int i =0; i < n;i++) {
        freq[v[i]]++;
      }
    }
    
    int sol = 0;
    for (int i = 'a'; i<='z';i++) {
      sol = max(sol, freq[i]);
    }

    cout <<sol <<"\n";

    return 0;
}
