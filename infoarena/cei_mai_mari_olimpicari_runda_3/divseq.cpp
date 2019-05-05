#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char uchar;
const int nmax = 250001;
ull v[nmax];
int n;
ull max_val;

int main() {
    freopen("divseq.in", "r", stdin);
    freopen("divseq.out", "w", stdout);

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%llu", &v[i]);
        max_val = max(max_val, v[i]);
    }
    int limit = (int)log2(max_val) + 1;

    ull sol = 0;
    for (int i = 0; i < n; i++) {

        ull v_min = v[i];
        ull v_max = v[i];

        int last_good = i;
        for (int j = i + 1; j < n && j <= i + limit; j++) {
            if (v[j] == 1 ||
                (v_min % v[j] == 0) ||
                (v[j] % v_max == 0)) {

                v_min = min(v_min, v[j]);
                v_max = max(v_max, v[j]);
                last_good = j;
                //cout << "min - max " << v_min << " " << v_max << endl;
                //cout << i << " " << j << endl;
            } else {
                bool ok = true;
                for (int k = i; k < j; k++) {
                    if ((max(v[j], v[k])) % (min(v[j], v[k])) != 0) {
                        ok = false;
                        break;
                    }
                }

                if (!ok) break;
                last_good = j;
                v_min = min(v_min, v[j]);
                v_max = max(v_max, v[j]);
            }
        }
        //cout << i << " " << last_good << endl;
        sol += last_good - i + 1;
    }
    printf("%llu\n", sol);

    return 0;
}


