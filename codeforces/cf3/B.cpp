#include <bits/stdc++.h>

using namespace std;

string s;

int calc_p() {
  int p = 0;

  stack<char> st;

  for (int i = 0; i < s.length(); i++) {
    if (!st.empty() && st.top() == s[i]) {
      st.pop();
      p++;
    } else {
      st.push(s[i]);
    }
  }

  return p;
}

int main() {
    //freopen("input", "r", stdin);

    cin >>s;

    int p = calc_p();
  
    if (p % 2 == 0) {
      cout << "No" << "\n";
    } else {
      cout << "Yes" << "\n";
    }

    return 0;
}
