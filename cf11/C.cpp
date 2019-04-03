#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
const int nmax = 10000;

int A[501][501];
int B[501][501];
unordered_map<int, pair<int, int>> AM;
unordered_map<int, pair<int, int>> BM;
int main() {
  //freopen("input", "r", stdin);

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      scanf("%d", &A[i][j]);
  }

  for (int i = 0;i < n; i++) {
    for (int j = 0; j < m ; j++) {
    scanf("%d", &B[i][j]);
    }
  }

 
  int D = 1;
  for (int i = 0; i < m; i++) {
    for (int j = 0, k = i; j < n && k >= 0; j++, k--) {
      if (AM[A[j][k]].first != D) {
        AM[A[j][k]].first = D;
        AM[A[j][k]].second = 1;
      } else {
        AM[A[j][k]].second++;
      }

      if (BM[B[j][k]].first != D) {
        BM[B[j][k]].first = D;
        BM[B[j][k]].second = 1;
      } else {
        BM[B[j][k]].second++;
      }    
    }

    for (int j = 0, k = i; j < n && k >= 0; j++, k--) {
      if (AM[A[j][k]].first != BM[A[j][k]].first || AM[A[j][k]].second != BM[A[j][k]].second) {
        cout << "NO\n";
        return 0;
      }
    }

    D++;
  }

  for (int i = 1; i < n; i++) {
    for (int j = i, k = m - 1; j < n && k >= 0; j++,  k--) {
     if (AM[A[j][k]].first != D) {
        AM[A[j][k]].first = D;
        AM[A[j][k]].second = 1;
      } else {
        AM[A[j][k]].second++;
      }

      if (BM[B[j][k]].first != D) {
        BM[B[j][k]].first = D;
        BM[B[j][k]].second = 1;
      } else {
        BM[B[j][k]].second++;
      }    
    
    }

    for (int j = i, k = m - 1; j < n && k >= 0; j++,  k--) {
        if (AM[A[j][k]].first != BM[A[j][k]].first || AM[A[j][k]].second != BM[A[j][k]].second) {
        cout << "NO\n";
        return 0;
      }    
    }
    D++;
  }


  cout << "YES\n";
  return 0;
}
