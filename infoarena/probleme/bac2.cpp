#include <bits/stdc++.h>
using namespace std;

int main() {
  ifstream iFile("input");
  while (true) {
    int x;
    iFile >> x;
    if( iFile.eof() ) break;
    cout << x << endl;
  }
  return 0;
}
