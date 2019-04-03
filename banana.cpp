#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char uchar;
const int nmax = 16001;

const uint modulo = (2 << 17) - 1;
struct point_t {
    uint x, y, id;
};

vector<point_t> H[modulo];

uint hash_point(point_t &p) {
    return ((p.x << 4) * 13 + 97 * (p.y >> 4)) % modulo;
}

vector<point_t>::iterator find_point(point_t &p) {
    uint idx = hash_point(p);
    for (auto it = H[idx].begin(); it != H[idx].end(); ++it) {
        if (p.x == it->x && p.y == it->y) return it;
    }
    return H[idx].end();
}

inline bool check_point(point_t &p) {
    uint idx = hash_point(p);
    return find_point(p) != H[idx].end();
}

void insert_point(point_t &p) {
    if (check_point(p)) return ;
    uint idx = hash_point(p);
    H[idx].push_back(p);
}

uint roots[nmax], ranks[nmax];


uint find_root(uint x) {
    uint R;
    for (R = x; R != roots[R]; R = roots[R]) ;

    uint y = x;
    uint tmp;
    while (y != roots[y]) {
        tmp = roots[y];
        roots[y] = R;
        y = tmp;
    }

    return R;

}

void unite(uint x, uint y) {
    x = find_root(x);
    y = find_root(y);

    if (ranks[x] > ranks[y]) {
        ranks[x] += ranks[y];
        roots[y] = x;
    } else {
        ranks[y] += ranks[x];
        roots[x] = y;
    }
}

uint N, K;
uint bananas_idx;
point_t bananas[nmax];
uint cnt[nmax];

int xdir[] = {1, -1, 0, 0};
int ydir[] = {0, 0, 1, -1};

int main() {
    freopen("banana.in", "r", stdin);
    freopen("banana.out", "w", stdout);

    scanf("%u %u", &N, &K);
    for (uint i = 0, x, y; i < N; i++) {
        scanf("%u %u", &x, &y);
        bananas[bananas_idx].x = x;
        bananas[bananas_idx].y = y;
        bananas[bananas_idx].id = i;
        insert_point(bananas[bananas_idx]);
        bananas_idx++;
        roots[i] = i;
        ranks[i] = 1;
    }

    for (uint i = 0; i < N; i++) {
        point_t new_point;
        for (uint j = 0; j < 4; j++) {
            new_point.x = bananas[i].x + xdir[j];
            new_point.y = bananas[i].y + ydir[j];

            if (check_point(new_point)) {
                auto tmp = *find_point(new_point);
                //printf("%d (%d, %d) -> %d (%d, %d)\n", i, bananas[i].x, bananas[i].y, tmp.id, tmp.x, tmp.y);
                unite(bananas[i].id, tmp.id);
            }
        }
    }

    for (uint i = 0; i < N; i++) {
        cnt[roots[i]]++;
    }
    sort(cnt, cnt+N, greater<uint>());

    ull sol = 0;
    for (uint i = 0; i < K; i++) {
        sol += cnt[i];
    }

    printf("%llu\n", sol);

    return 0;
}


