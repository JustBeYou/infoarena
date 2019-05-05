#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char uchar;
const int nmax = 10001;

int n, m;
short A[nmax], B[nmax];
short tailA[nmax], tailB[nmax];
short solutionA[nmax], solutionB[nmax];
short lengthA, lengthB;

int find_best(short value, int r, short v[], short tail[]) {
      int l = -1;
      int m = 0;

    while (l + 1 < r) {
        m = l + (r - l) / 2;

        if (v[tail[m]] < value) {
            l = m;
        } else {
            r = m;
        }
      }
      return r;
}

short before[nmax];
int last;
void calc(short v[], int dim, short tail[], short &length, short solution[]) {
    memset(before, -1, dim);

    length = 0;
    tail[0] = 0;

    for (int i = 1; i < dim; i++) {
        if (v[i] < v[tail[0]]) {
            tail[0] = i;
        } else if (v[i] > v[tail[length]]) {
            tail[++length] = i;
            before[i] = tail[length - 1];
            last = i;
        } else {
            int j = find_best(v[i], length, v, tail);
            tail[j] = i;
            before[i] = tail[j - 1];
        }
    }

    int idx = length;
    while (before[last] != -1) {
        solution[idx--] = last;
        last = before[last];
    }
    solution[0] = last;
}

int main() {
    freopen("interclasare.in", "r", stdin);
    freopen("interclasare.out", "w", stdout);

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &B[i]);
    }

    calc(A, n, tailA, lengthA, solutionA);
    calc(B, m, tailB, lengthB, solutionB);
    printf("%d\n", lengthA + lengthB + 2);

    int idxA = 0, idxB = 0;
    int solIdxA = 0, solIdxB = 0;
    while (solIdxA <= lengthA && solIdxB <= lengthB) {
        if (idxA != solutionA[solIdxA]) {
            printf("%d ", A[idxA++]);
        } else if (A[idxA] < B[solutionB[solIdxB]]) {
            printf("%d ", A[idxA++]);
            solIdxA++;
        }

        if (idxB != solutionB[solIdxB]) {
            printf("%d ", B[idxB++]);
        } else if (B[idxB] < A[solutionA[solIdxA]]) {
            printf("%d ", B[idxB++]);
            solIdxB++;
        }
    }
    while (idxA < n) {
        printf("%d ", A[idxA++]);
    }
    while (idxB < m) {
        printf("%d ", B[idxB++]);
    }

    printf("\n");

    return 0;
}

