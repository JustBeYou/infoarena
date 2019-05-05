#include <bits/stdc++.h>

using namespace std;
#define VAL_PI 3.14159265358979323846
int main() {
    //freopen("input", "r", stdin);
    double n, r;
    cin >> n >> r;

     cout << fixed << setprecision(10) << r*(sin(VAL_PI/n)/(1-sin(VAL_PI/n)));
    return 0;
}
