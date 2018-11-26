#include <bits/stdc++.h>

using namespace std;

const int max_n = 10000;

int n, m, p;
int A[max_n], B[max_n];
int C[2 * max_n];
int tail[2 * max_n];
int length;

int find_best_j(int value) {
    int l = -1;
    int r = length;
    int m;
	
    while (l + 1 < r) {
        cout << l << " " << r << " : ";
        m = l + (r - l) / 2;
	
        cout << C[tail[m]] << " <> " << value << endl;
        if (C[tail[m]] < value) {
            l = m;
        } else {
            r = m;
        }
    }

    cout << "stop at r: " << r << " with val " << C[tail[r]] << endl;
    return r;
}

void sqmax() {
    for (int i = 1; i < p; i++) {
        if (C[i] < C[tail[0]]) {
            tail[0] = i;
        } else if (C[i] > C[tail[length]]) {
            tail[++length] = i; 
        } else {
            int j = find_best_j(C[i]);
            tail[j] = i;
        }
    }
}

void merge()
{
    int i = 0, j = 0, k = 0;
    while (k < m + n && i < n && j < m) {
        if (A[i] < B[j]) {
            C[k++] = A[i++];
        } else {
            C[k++] = B[j++];
        }
    }

    for (; i < n; i++) {
        C[k++] = A[i];
    }
    for (; j < m; j++) {
        C[k++] = B[j];
    }

    p = k;
}

int main() {
    freopen("interclasare.in", "r", stdin);
    //freopen("interclasare.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> B[i];
    }

    merge();
    sqmax();

    cout << length + 1<< "\n";
    for (int i = 0; i < p; i++) {
        cout << C[i] << " ";
    }
    cout << "\n";

    return 0;
}
