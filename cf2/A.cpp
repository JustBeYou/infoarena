#include <bits/stdc++.h>

using namespace std;


const int max_n = 1001;
int n;
int v[max_n];

int main() {
    freopen("input", "r", stdin);


    int max_num = 0;
    cin >> n;
    for (int i = 0; i< n;i++) {
      cin >> v[i];
      max_num = max(v[i], max_num);
    }

    int best_t = 0;
    int best_cost = INT_MAX;
 for (int t = 1; t < max_num + 1; t++) {
   int cost = 0;

   for (int i =0;i<n;i++){
    if (int(abs(v[i] - t)) > 1) {
      if (v[i] > t) {
        cost += v[i] - t - 1;

      } else {
       cost += t - v[i] - 1;
      }
    }
   }

    if (cost < best_cost) {
      best_cost = cost;
      best_t = t;
    }

 }

 cout << best_t << " " << best_cost << "\n";

    return 0;
}
