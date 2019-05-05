#include <bits/stdc++.h>

using namespace std;

const int max_n = 100000;
int k, n;
string s;

int calc(int start, int end) {
    int res = 0;

    for (int i = end, j = 0; i >= start; i--, j++) {
        res += (s[i] == '1' ? 1 : 0) << j;
    }
    return res;
}

int main() {
    freopen("blis.in", "r", stdin);
    freopen("blis.out", "w", stdout);

    cin >> k;
    getline(cin, s);
    cin >> s;
    n = s.size();

    int max_num = calc(0, k - 1);
    for (int i = k, tmp; i < n; i++) {
        tmp = calc(i - k + 1, i);
        max_num = max(tmp, max_num);
    }

    cout << max_num << "\n";
    cout << 0 << "\n";

    return 0;
}
