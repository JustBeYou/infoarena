#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char uchar;
const int pmax = 22;
const int smax = 1 << pmax;

int n;
bool win[smax];
int pows[pmax + 1];

void printbin(int x) {
    bitset<sizeof(x) * 8> a(x);
    cout << a << endl;
}

int main() {
    freopen("coins.in", "r", stdin);
    freopen("coins.out", "w", stdout);

    for (int i = 0; i < pmax; i++) {
        pows[i] = 1 << i;
    }
    for (int i = 0, j = 0; i < pmax; i++) {
        j ^= 1 << i;
        //printbin(j);
        win[j] = true;
    }

    //cout <<endl;
    for (int i = 1; i < (1 << pmax); i++) {
        //cout << "i: "; printbin(i);
        int last0 = -1;
        for (int j = 0; j < pmax; j++) {
            if (pows[j] & i) {
                if (last0 != -1) {
                    //printbin(i ^ pows[last0] ^ pows[j]);
                    win[i] |= !win[i ^ pows[last0] ^ pows[j]];
                }
            } else {
                last0 = j;
            }
        }
    }

    int n;
    scanf("%d", &n);

    int sol = 0;
    for (int i = 0; i < n; i++) {
        int start = 0;
        int coins = 0;
        for (int j = 0, x; j < pmax; j++) {
            scanf("%d", &x);
            if (x) coins++;
            start ^= x << j;
        }
        if (win[start]) sol += coins;
    }
    printf("%d\n", sol);

    return 0;
}

