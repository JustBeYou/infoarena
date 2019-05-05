#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char uchar;
const int nmax = 2000001;
const int smax = 2001;

char A[nmax];
char B[nmax];
int sol_cnt;
int sol[nmax];
int lsp[nmax];

void kmp_query(char *pattern, char *text) {
    int m = strlen(pattern);
    int n = strlen(text);

    for (int i = 1, len = 0; i < m; i++) {
        while (len && pattern[i] != pattern[len]) len = lsp[len - 1];
        if (pattern[i] == pattern[len]) lsp[i] = ++len;
        else lsp[i] = len;
    }

    for (int i = 0, j = 0; i < n; i++) {
        while (j && text[i] != pattern[j]) j = lsp[j - 1];
        if (text[i] == pattern[j]) j++;
        if (j == m) { sol[sol_cnt++] = i - j + 1; j = lsp[j - 1]; }
    }
}

int main() {
    freopen("strmatch.in", "r", stdin);
    freopen("strmatch.out", "w", stdout);

    scanf("%s", A);
    scanf("%s", B);

    kmp_query(A, B);

    printf("%d\n", sol_cnt);
    for (int i = 0; i < min(sol_cnt, 1000); i++) {
        printf("%d ", sol[i]);
    }
    printf("\n");

    return 0;
}

