#include <bits/stdc++.h>
	
 
	
using namespace std;
	
 
	
void euclid(int a, int b, int &d, int &x, int &y)
	
{
    if (!b) {
        d = a;
        x = 1;
        y = 0;
    } else {
        int x0, y0;
        euclid(b, a % b, d, x0, y0);
        x =  y0;
        y =  x0 - y0 * (a / b);
    }
}
	
 
	
int main() {
	
    freopen("euclid3.in", "r", stdin);
	
    //freopen("euclid3.out", "w", stdout);
	
 
	
    int n;
	
    cin >> n;
	
    for (int i = 0; i < n; i++) {
	
        int a, b, c, d, x, y;
	
        cin >> a >> b >> c;
	
        euclid(a, b, d, x, y);
	
        cout << x << " " << y << " -> "; 
	
        if (c % d) {
	
            cout << 0 << " " << 0 << "\n";
	
        } else {
	
            cout << x * (c / d) << " " << y * (c / d) << "\n";
	
        }
	
    }
	
 
	
    return 0;
	
}
