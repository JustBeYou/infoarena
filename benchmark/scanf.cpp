#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);

    char c;
    int s = 0;
    int x = 0;
    while (scanf("%c", &c) == 1) {
        s += c;
        s %= 10;
    }

    return 0;
}
