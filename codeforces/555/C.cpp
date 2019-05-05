#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
const int nmax = 10000;

int v[2 * 100005];
vector<char> sol;
int main() {
  //freopen("input", "r", stdin);

  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i ++) {
    scanf("%d", &v[i]);
  }

  int first = 0;
  int last = n - 1;
  int head = -1;

  while (first <= last) {
    int elem1 = v[first];
    int elem2 = v[last];

    if (elem1 == elem2 && first != last){
      if (elem1 > head) {
        int cnt = 0;
        while (first < last && elem1 == elem2 && elem1 > head) {
          head = elem1;
          cnt++;
          //sol.push_back('?');

          elem1 = v[++first];
          elem2 = v[--last];
        }
        if (first == last) {
          if (v[first] > head) {
            cnt++;
          }
          for (int w = 0; w < cnt ; w++) {
            sol.push_back('L');
          }
          break;
        } else if (first > last) {
          for (int w = 0; w < cnt ; w++) {
            sol.push_back('L');
          } 
       break;
      }

        int head1 = head;
        int cnt1 = 0;
        while (first < n && v[first] > head1) {
            cnt1++;
            head1 = v[first];
            first++;
        }

        int head2 = head;
        int cnt2 = 0;
        while (last >= 0 && v[last] > head2) {
          cnt2++;
          head2 = v[last];
          last--;
        }

        if (cnt1 > cnt2) {
          for (int w = 0; w < cnt + cnt1; w++) {
            sol.push_back('L');
          }
          break;
        } else {
          for (int w = 0; w < cnt + cnt2; w++) {
            sol.push_back('R');
          }
        }
      } else {
        break;
      }

    } else if (elem1 < elem2) {
      if (elem1 > head) {
        head = elem1;
        sol.push_back('L');
        first++;
      } else if (elem2 > head) {
       head = elem2;
        sol.push_back('R');
        last--;
      } else {
        break;
      }
    } else {
      if (elem2 > head) {
        head = elem2;
        sol.push_back('R');
        last--;
      } else if (elem1 > head) {
     
     head = elem1;
        sol.push_back('L');
        first++;
      } else {
        break;
      }
    }
  }
  printf("%d\n", sol.size());
  for (auto c: sol) {
    printf("%c", c);
  }
  puts("");

  return 0;
}
