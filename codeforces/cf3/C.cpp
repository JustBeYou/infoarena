#include <bits/stdc++.h>

using namespace std;

string s;
bool matrix[5][5];

void put_it(char c) {
  for (int i = 1; i < 5; i++) {
    for (int j = 1; j < 5; j++) {
      if (c == '0') {
        if (matrix[i][j] == false &&
            matrix[i + 1][j] == false) {
          matrix[i][j] = matrix[i + 1][j] = true;
          cout << i << " " << j << "\n";
          i = j = 5;
        }
      } else if (c == '1') {
        if (matrix[i][j] == false &&
            matrix[i][j + 1] == false) {
          matrix[i][j] = matrix[i][j+1] = true;
          cout << i << " " << j << "\n"; 
          i = j = 5;
        }
      }
    }
  }
}

void delete_it() {
  for (int i = 1; i < 5;i++) {
    bool not_free = true;

    for (int j = 1; j < 5; j++){
      not_free = not_free && matrix[i][j];
    }

    if (not_free) {
      for (int j = 1; j < 5; j++) {
        matrix[i][j] = false;
      }
    }
  }
}

void show() {
  for (int i = 1; i < 5; i++) {
    for (int j = 1; j < 5; j++) {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
}

int main() {
    //freopen("input", "r", stdin);

    cin >> s;
    // 0 - vertical
    // 1 - horizontal
    for (int i = 0; i < s.length(); i++) {
      put_it(s[i]);
      //show();
      delete_it();
      //show();
    }

    return 0;
}
