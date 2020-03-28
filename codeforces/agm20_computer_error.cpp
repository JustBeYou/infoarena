#include <bits/stdc++.h>

using namespace std;

typedef unsigned int uint;

struct cond {
    char op;
    int num;
    bool real;

    bool operator< (const cond& rhs) const {
        return num < rhs.num;
    }

    bool operator== (const cond& rhs) const {
        return num == rhs.num;
    }
};

vector<cond> normalize(vector<cond> A) {
    vector<cond> S(A), N(A.size()); // O(2N)
    sort(S.begin(), S.end()); // O (N * log N)
    for(uint i = 0; i < A.size(); ++i) { // O(N)
        auto found = lower_bound(S.begin(), S.end(), A[i]); // O(log N)
        N[i].num = found - S.begin();

        while (*found == A[i] and found->op == '!') { // O(3)
            ++found;
        }
        N[i].op = found->op;
        N[i].real = found->real;
        found->op = '!';
    }

    sort(N.begin(), N.end()); // O(N * log N)
    return N;
}

void solve(uint m, vector<cond>& conditions) {
    sort(conditions.begin(), conditions.end()); // O(N * log N)

    for (uint i = 0; i < m - 1; i++) { // O(N)
        if (conditions[i].num + 1 < conditions[i + 1].num) {
            conditions.push_back({'#', conditions[i].num + 1, true});
        }
    }
    conditions.push_back({'#', 1000000000 + 1, true});
    conditions.push_back({'#', 0, true});

    auto normalized = normalize(conditions);
    vector<uint> satisf(normalized.size(), 0);

    uint to_add = 0;
    for (uint i = 0; i < normalized.size(); i++) { // O(3 * N)
        satisf[normalized[i].num] += to_add;

        uint old = i;
        while (normalized[old].num == normalized[i].num) {
            switch(normalized[i].op) {
                case '=':
                    if (normalized[i].real) satisf[normalized[i].num]++;
                    else { to_add += 1; }
                    break;
                case '<':
                    if (not normalized[i].real) {
                        satisf[normalized[i].num]++;
                        to_add++;
                    }
                    break;
                case '>':
                    if (normalized[i].real) {
                        to_add++;
                    }
                    break;
                case '#':
                    break;
            }

            i++;

            if (i >= normalized.size()) break;
        }
        i--;
    }

    to_add = 0;
    for (int i = normalized.size() - 1; i >= 0; i--) { // O(3 * N)
        satisf[normalized[i].num] += to_add;

        int old = i;
        while (normalized[old].num == normalized[i].num) {
            switch(normalized[i].op) {
                case '<':
                    if (normalized[i].real) {
                        to_add++;
                    }
                    break;
                case '>':
                    if (not normalized[i].real) {
                        satisf[normalized[i].num]++;
                        to_add++;
                    }
                    break;
                case '#':
                    break;
            }

            i--;

            if (i < 0) break;
        }
        i++;
    }

    //for (auto it: normalized) {
    //    cout << it.op << " " << it.num << " " << (it.real ? "true" : "false") << endl;
    //}

    uint max_satisf = 0;
    for (auto it: satisf) { // O(N)
        max_satisf = max(it, max_satisf);
        //cout << it << " ";
    }
    //cout << endl;

    cout << m - max_satisf << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    freopen("inp.in", "r", stdin);
    
    vector<cond> conditions;
    uint n;
    cin >> n;
    for (uint i = 0; i < n; i++) { // O (N)
        uint m;
        cin >> m;
        if (i == 0) conditions.reserve(m);

        char op; int num; string real;
        for (uint j = 0; j < m; j++) { // O(M)
            cin >> op >> num >> real;
            if (real[0] == 'T') {
                conditions.push_back({op, num, true});
                //cout << op << " " << num << " " << true << endl;
            } else {
                conditions.push_back({op, num, false});
                //cout << op << " " << num << " " << false << endl;
            }
        }

        solve(m, conditions);

        conditions.clear();
    }

    return 0;
}
