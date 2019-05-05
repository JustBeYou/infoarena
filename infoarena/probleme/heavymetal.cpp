#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
const int nmax = 100005;
struct interval {
    uint start;
    uint finish;
};
struct comp {
    bool operator()(const interval &left, const interval &right) {
        if (left.finish == right.finish)
            return left.start < right.start;
        return left.finish < right.finish;
    }
};

interval v[nmax];
uint n;

int main() {
    freopen("heavymetal.in", "r", stdin);
    //freopen(".out", "w", stdout);

    scanf("%u", &n);
    interval tmp;
    for (uint i = 0; i < n; i++) {
        scanf("%u %u", &tmp.start, &tmp.finish);
        v[i] = tmp;
    }

    sort(v, v + n, comp());

    for (uint i = 0;i<n;i++){
    cout<<v[i].start <<" "<<v[i].finish<<endl;
    }



    return 0;
}


