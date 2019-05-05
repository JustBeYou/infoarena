#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
uint v[1<<20+1];
ull sol;
int n, l, u;
unordered_map<uint, uint> freq;

ull solve(int sz) {
    freq.clear();
    ull ret = 0;
    int start = 0;
    int dist;

    for (int i = 0; i < n;i++) {
        freq[v[i]]++;

        if (freq.size() <= sz) {
            dist = i - start + 1;
            ret += dist;
        } else {
            while (freq.size() > sz) {
                freq[v[start++]]--;
                if (freq[v[start - 1]] == 0) freq.erase(v[start - 1]);
            }
            dist = i - start + 1;
            ret += dist;
        }
    }

    return ret;
}

int main() {
    freopen("secv5.in", "r", stdin);
    freopen("secv5.out", "w", stdout);

    scanf("%d%d%d", &n,&l,&u);

    for (int i =0;i<n;i++) {
        scanf("%u", &v[i]);
    }

    sol = solve(u) - solve(l - 1);
    printf("%llu\n", sol);

    return 0;
}
