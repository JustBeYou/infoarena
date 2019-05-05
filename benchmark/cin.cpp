#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);

    char c;
    int s = 0;
    while (cin >> c) {
        s += c;
        s %= 10;
    }

    return 0;
}
