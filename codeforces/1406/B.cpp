#include <bits/stdc++.h>

using namespace std;

typedef unsigned int uint;
typedef unsigned long long ull;
typedef long long ll;

const uint maxn = 100005;
ll v[maxn];

template <typename T>
void printarray(T v[], uint n) {
    for (uint i = 0; i < n; i ++) {
        cout << v[i] << " ";
    }
    cout << endl;
}


int main() {
    //freopen("input.in", "r", stdin);

    uint t;
    cin >> t;
    while(t--) {
        int k = 5;
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) cin >> v[i];
        sort(v, v + n);
        ll prod = 1LL;
        if (v[n-1] == 0 && k % 2) {
            cout << "0\n";
            continue;
        }

        if (v[n-1] <= 0 && k % 2) {
            for (int i = n - 1; i >= (n - k); i--) {
                prod *= v[i];
            }
            cout << prod << "\n";
            continue;
        }

        int i =0 , j = n - 1;
        if (k % 2) {
            prod *= v[j];
            j--;
            k--;
        }

        k /= 2;
        for (int itr = 0; itr < k; itr++) {
            ll leftprod = v[i] * v[i+1];
            ll rightprod = v[j] * v[j-1];

            if (leftprod > rightprod) {
                prod *= leftprod;
                i += 2;
            }
            else {
                prod *= rightprod;
                j -=2;
            }

        }

        cout << prod << "\n";
    }

    return 0;
}