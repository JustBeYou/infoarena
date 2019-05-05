#include <bits/stdc++.h>

using namespace std;

const int n_max = 100000;
int a[n_max], c[n_max], d[n_max], t[n_max];
int sol[n_max];
int n, m;

struct cmp
{
    inline bool operator() (const int &fst, const int &snd)
    {
        if (c[fst] == c[snd]) {
          return fst < snd;
        }
        return c[fst] < c[snd];
    }
};
set<int, cmp> a_srt;

int main() {
  //freopen("input", "r", stdin);
  //freopen(".out", "w", stdout);

  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) cin >> c[i];
  for (int i = 0; i < n; i++) a_srt.insert(i);

  for (int i = 0; i < m; i++) {
    cin >> t[i] >> d[i];
    t[i]--;
  }

  for (int i = 0; i < m; i++) {
    if (a[t[i]] == 0) break;

    if (a[t[i]] >= d[i]) {
       sol[i]+= d[i] * c[t[i]];
       a[t[i]] -= d[i];
      d[i] = 0;

       if (a[t[i]] == 0) a_srt.erase(t[i]);
    } else {
      sol[i]+= a[t[i]] * c[t[i]];
      d[i] -= a[t[i]];
      a[t[i]] = 0;
      a_srt.erase(t[i]);

      if (a_srt.empty()) {
        sol[i] = 0;
        break;
      }

      for (auto it = a_srt.cbegin(); it != a_srt.cend(); ) {
        if (a[*it] >= d[i]) {
          sol[i] += d[i] * c[*it];
          a[*it] -= d[i];
          d[i] = 0;

          if (a[*it] == 0) a_srt.erase(it);
          break;
        } else {
          sol[i]+= a[*it] * c[*it];
          d[i] -= a[*it];
          a[*it] = 0;
          it = a_srt.erase(it);
        }
      }

      if (d[i]) { sol[i] = 0;  break; }
    }
  }
  
  for (int i = 0; i < m; i++) {
    cout << sol[i] << "\n";
  }

  return 0;
}
