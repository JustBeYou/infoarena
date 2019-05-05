#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char uchar;
const int nmax = 10501;

int n;
int top[3];
int stacks[3][nmax];

int get_top(int idx) {
    return stacks[idx][top[idx]];
}

// n-th from top
int get_nth(int idx, int nth) {
    return stacks[idx][top[idx] - nth + 1];
}

int pop(int idx) {
    int tmp = stacks[idx][top[idx]];
    stacks[idx][top[idx]] = 0;
    top[idx]--;
    return tmp;
}

void push(int idx, int val) {
    stacks[idx][++top[idx]] =  val;
}

void show() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j <= top[i]; j++) {
            cout << stacks[i][j] << " ";
        }
        cout << endl;
    }
}

vector<pair<int, int>> moves;

inline bool need_swap(int first, int second, bool asc) {
    if (asc) return first < second;
    return first > second;
}

void merge_sort(int idx, int cnt, bool asc) {
    if (cnt == 1) return ;
    int half_idx = (idx + 1) % 3;
    int other_half_idx = (idx + 2) % 3;

    if (cnt == 2) {
        int first = get_nth(idx, 1);
        int second = get_nth(idx, 2);
        if (need_swap(first, second, asc)) {
            pop(idx);
            pop(idx);
            push(idx, first);
            push(idx, second);

            moves.push_back({idx, half_idx});
            moves.push_back({idx, other_half_idx});
            moves.push_back({half_idx, idx});
            moves.push_back({other_half_idx, idx});
        }

        return ;
    }

    int half = cnt / 2;
    int other_half = cnt - half;

    int tmp;
    for (int i = 0; i < half; i++) {
        tmp = pop(idx);
        push(half_idx, tmp);
        moves.push_back({idx, half_idx});
    }

    for (int i = 0; i < other_half; i++) {
        tmp = pop(idx);
        push(other_half_idx, tmp);
        moves.push_back({idx, other_half_idx});
    }

    merge_sort(half_idx, half, !asc);
    merge_sort(other_half_idx, other_half, !asc);

    while (half && other_half) {
        if (asc) {

            if (get_top(half_idx) < get_top(other_half_idx)) {
                push(idx, pop(half_idx));
                half--;

                moves.push_back({half_idx, idx});
            } else {
                push(idx, pop(other_half_idx));
                other_half--;

                moves.push_back({other_half_idx, idx});
            }

        } else {

            if (get_top(half_idx) > get_top(other_half_idx)) {
                push(idx, pop(half_idx));
                half--;

                moves.push_back({half_idx, idx});
            } else {
                push(idx, pop(other_half_idx));
                other_half--;

                moves.push_back({other_half_idx, idx});
            }

        }
    }

    while (half--) {
        push(idx, pop(half_idx));

        moves.push_back({half_idx, idx});
    }

    while (other_half--) {
        push(idx, pop(other_half_idx));

        moves.push_back({other_half_idx, idx});
    }
}

int main() {
    freopen("aranjare3.in", "r", stdin);
    freopen("aranjare3.out", "w", stdout);

    scanf("%d", &n);
    for (int i = 0, x; i < n; i++) {
        scanf("%d", &x);
        push(0, x);
    }

    merge_sort(0, n, true);
    //show();

    printf("%d %d\n", 2, moves.size());
    for (auto p: moves) {
        printf("%d %d\n", p.first, p.second);
    }

    return 0;
}


