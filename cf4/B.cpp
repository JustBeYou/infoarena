#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int max_n = 100000;

struct cmp {
    bool operator() (const pair<ll, ll>& lhs, const pair<ll, ll>& rhs) const {
     if (lhs.first == rhs.first) {
        return lhs.second < rhs.second;
     }
      return lhs.first > rhs.first;
    }
};

ll nums[max_n];
ll sums[max_n];
ll parts[max_n];
int main() {
    freopen("input", "r", stdin);

    ll n, m, k;
    cin >> n >> m >> k;
    for (ll i =0;i<n;i++) {
    cin>>nums[i];
    }

    ll i =1;
    ll j = 0;
    while (i<k) {
      set<pair<ll,ll>,cmp> s;
  
      ll l;
      for (l = j; (n - (l + 1)) / (k - i) >= m; l++) {
        s.insert(make_pair(nums[l], l));
      }

      ll max_pos = 0;
      ll cnt = 0;
      ll sum = 0;
      for (auto &it: s) {
        max_pos = max(max_pos, it.second);
        sum += it.first;

        if (++cnt == m) {
          break;
        }
      }
      sums[i] = sum;
      parts[i] = max_pos;

      // ---------------------
      j = max_pos + 1;
      i++;
    }

    ll solution = 0;
    for (ll i = 1; i < k; i++) {
      solution += sums[i];
    }

    set<pair<ll,ll>,cmp> s;
    for (ll i = j; i < n; i++) {
      s.insert(make_pair(nums[i], i));
    }
    ll cnt = 0;
    for (auto &it: s) {
      solution += it.first;
      if (++cnt == m)break;
    }

   cout << solution << "\n"; 
    for (ll i = 1; i < k; i++) {
      cout << parts[i] + 1<< " ";
    }
    cout << "\n";

    return 0;
}
