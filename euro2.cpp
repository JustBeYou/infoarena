#include <bits/stdc++.h>

using namespace std;

const int max_n = 10000;

int n;
vector<int> v(max_n);
vector<int> tail(max_n);
vector<int> length_asc(max_n);
vector<int> length_dsc(max_n);
vector<int> tailof(max_n);
vector<int> headof(max_n);
int solution;
int length;

int find_best_j(int value) {
    int l = -1;
    int r = length;
    int m;
	
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

void find_asc_seqs() {
    length = 0;
    tail[0] = 0;

    for (int i = 0; i < n; i++) {
        if (v[i] < v[tail[0]]) {
            tail[0] = i;
        } else if (v[i] > v[tail[length]]) {
            tail[++length] = i;
        } else {
            int pos = find_best_j(v[i]);
            tail[pos] = i;
        }

        length_asc[i] = length;
        tailof[i] = tail[length];
    }
}

void find_dsc_seqs() {
    length = 0;
    tail[0] = n - 1;

    for (int i = n - 2; i >= 0; i--) {
        if (v[i] < v[tail[0]]) {
            tail[0] = i;
        } else if (v[i] > v[tail[length]]) {
            tail[++length] = i;
        } else {
            int pos = find_best_j(v[i]);
            tail[pos] = i;
        }

        length_dsc[i] = length;
        headof[i] = tail[length];
    }
}

int main() {
    freopen("euro2.in", "r", stdin);
    freopen("euro2.out", "w", stdout);

    cin >> n;
    double tmp1;
    int tmp2;
    for (int i = 0; i < n; i++) {
        cin >> tmp1;
        tmp2 = static_cast<int>(tmp1 * 10000);
        v[i] = tmp2;
    }

    find_asc_seqs();
    find_dsc_seqs();
   
    solution = 0;
    for (int i = 0; i < n - 1; i++) {
        if (length_asc[i] >= 1      &&
            tail[i] < headof[i + 1] && 
            v[tailof[i]] > v[headof[i + 1]]) {
            solution = max(solution, length_asc[i] + length_dsc[i + 1]);
        }
    }

    cout << solution + 2 << "\n";

    return 0;
}
