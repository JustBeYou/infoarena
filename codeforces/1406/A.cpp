#include <bits/stdc++.h>

using namespace std;

typedef unsigned int uint;

int main() {
    freopen("input.in", "r", stdin);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<uint> v(n + 1);
        vector<uint> freq(101, 0);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            freq[v[i]]++;
        }

        uint a = 0, b = 0;
        for (int i = 0; i <= 100; i++) {
            if (freq[i] == 0) {
                a = i;
                break;
            }
            freq[i]--;
        }
        for (int i = 0; i <= 100; i++) {
            if (freq[i] == 0) {
                b = i;
                break;
            }
            freq[i]--;
        }

        cout << a + b << "\n";
    }

    return 0;
}