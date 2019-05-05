#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char uchar;
const int nmax = 1000010;
char result[nmax];
char ciur[nmax];
char ciur_sol[nmax];
int n;

int main() {
    freopen("ciurulet.in", "r", stdin);
    freopen("ciurulet.out", "w", stdout);

    scanf("%d", &n);
    scanf("%s", &result[2]);
    memset(ciur, '1', n + 6);
    memset(ciur_sol, '1', n + 6);

    for (int i = 2; i <= n; i++) {

        if (result[i] == '0' && ciur[i] == '1') {
            ciur_sol[i] = '0';
            continue;
        }

        ciur_sol[i] = '1';
        for (int j = 2 * i; j <= n; j += i) {
            if (result[j] == '1') {
                ciur_sol[i] = '0';
                break;
            }
        }

        if (ciur_sol[i] == '1') {
            for (int j = 2 * i; j <= n; j += i) {
                ciur[j] = '0';
            }
        }
    }
    ciur_sol[n + 1] = 0;

    int sol = 0;
    for (int i = 2; i <= n; i++) if (ciur_sol[i] == '1') sol++;
    printf("%d\n%s\n", sol, &ciur_sol[2]);

    return 0;
}


