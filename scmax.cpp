#include <bits/stdc++.h>

using namespace std;

const int max_n = 100000;
int n;
vector<int> v(max_n);
vector<int> before(max_n);
vector<int> tail(max_n);
vector<int> solution(max_n);
int length, last_position;

	
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

int main() {
    freopen("scmax.in", "r", stdin);
    freopen("scmax.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        tail[i] = 0;
        before[i] = -1;
    }
    
    for (int i = 1; i < n; i++) {
        if (v[i] < v[tail[0]]) {
            tail[0] = i;
        } else if (v[i] > v[tail[length]]) {
            tail[++length] = i;
            before[i] = tail[length - 1];
            last_position = i;
        } else {
            int pos = find_best_j(v[i]);
            tail[pos] = i;
            before[i] = tail[pos - 1];
        }
    }
    cout << length + 1 << "\n";

    int solution_length = length + 1;
    while (before[last_position] != -1) {
        solution[length--] = v[last_position];
        last_position = before[last_position];
    }
    solution[0] = v[last_position];

    for (int i = 0; i < solution_length; i++) {
        cout << solution[i] << " ";
    }
    cout << "\n";

    return 0;
}
