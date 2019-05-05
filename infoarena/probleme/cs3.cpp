#include <iostream>

using namespace std;

typedef unsigned long long ull;
ull N, X, Y;

int main() {
  freopen("input","r", stdin);
  scanf("%llu%llu%llu", &N, &X, &Y);
    
    ull left = 1;
    ull right = X - 1;
    ull mid;
    while (left <= right) {
        mid = (left + right) / 2;
        
        ull R = Y - mid;
        double D = (double) R / (N - 1);
        cout << left << " " << mid << " " << right << endl;
        cout << R << " " << D << endl;

        if (D > (double) X - 1) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    ull R = Y - mid;
    double D = (double) R / (N - 1);
    if (D > (double) X - 1) mid--;
    printf("%llu\n", mid);
    
    return 0;
}
