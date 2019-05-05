#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char uchar;

const int nmax = 100001;
const int BUCKET_SZ = static_cast<int>(sqrt(nmax)) + 1;
//const int BUCKET_SZ = 3;
const int BUCKETS = nmax / BUCKET_SZ + 1;

inline int bucket(int x) {
    return x / BUCKET_SZ;
}

int v[nmax];

int freq[nmax];
void reset() {
    memset(freq, 0, nmax * sizeof(freq[0]));
}

void add_freq(int left, int right, int &best) {
    //printf("add from %d to %d\n", left, right);
    for (int i = left; i <= right; i++) {
        freq[v[i]]++;

        if (freq[v[i]] > freq[v[best]]) {
            best = i;
        } else if (freq[v[i]] == freq[v[best]] && v[i] < v[best]) {
            best = i;
        }
    }
}

void remove_freq(int left, int right) {
    //printf("remove from %d to %d\n", left, right);
    for (int i = left; i <= right; i++) {
        freq[v[i]]--;
    }
}

struct query_t {
    int left, right;
    int id;
};
struct cmp {
    bool operator() (const query_t& A, const query_t& B) {
        if (bucket(A.left) == bucket(B.left)) return A.right < B.right;
        return bucket(A.left) < bucket(B.left);
    }
};

int sol[nmax];
vector<query_t> queries;
vector<query_t> sorted_queries[BUCKETS];

void solve_queries(int bucket_id) {
    reset();

    int right_border = (bucket_id + 1) * BUCKET_SZ - 1;
    int old_right = right_border;
    int best = right_border + 1;

    for (auto query: sorted_queries[bucket_id]) {
        //printf("solving  %d - %d\n", query.left, query.right);
        add_freq(old_right + 1, query.right, best);
        int tmp_ans = best;
        add_freq(query.left, right_border, tmp_ans);
        sol[query.id] = v[tmp_ans];
        remove_freq(query.left, right_border);
        old_right = query.right;
    }
}

int main() {
    freopen("rangemode.in", "r", stdin);
    freopen("rangemode.out", "w", stdout);

    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    for (int i = 0, l, r; i < m; i++) {
        scanf("%d %d", &l, &r);
        l--;
        r--;

        if (bucket(l) == bucket(r)) {
            int best = l;
            add_freq(l, r, best);
            remove_freq(l, r);
            sol[i] = v[best];
        } else {
            queries.push_back({l, r, i});
        }
    }
    sort(queries.begin(), queries.end(), cmp());
    for (auto &q: queries) {
        sorted_queries[bucket(q.left)].push_back(q);
    }

    for (int i = 0; i < n / BUCKET_SZ; i++) {
        solve_queries(i);
    }

    for (int i = 0; i < m; i++) {
        printf("%d\n", sol[i]);
    }

    return 0;
}

