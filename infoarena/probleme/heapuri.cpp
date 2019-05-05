#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char uchar;
const int nmax = 200000 + 100;
const int modulo = (1 << 17) - 1;

/// chronological order
int order_size;
int order[nmax];

/// hash table implementation
struct hash_node_t {
    // keys
    int val_key;
    int time_key;

    // value
    int value;
};

inline int hash_func(hash_node_t &h) {
    //return ((h.val_key << 4) * 13 + 97 * (h.time_key >> 4)) % modulo;
    return h.val_key % modulo;
}
inline int hash_idx(int val_key, int time_key) {
    hash_node_t tmp;
    tmp.val_key  = val_key;
    tmp.time_key = time_key;
    return hash_func(tmp);
}

typedef vector<hash_node_t> hash_table_t;
typedef vector<hash_node_t>::iterator hash_table_iter_t;
hash_table_t hash_table[modulo];

hash_table_iter_t hash_search(int val_key, int time_key) {
    int idx = hash_idx(val_key, time_key);

    for (hash_table_iter_t it = hash_table[idx].begin(); it != hash_table[idx].end(); ++it) {
        if (it->val_key == val_key && it->time_key == time_key) return it;
    }

    return hash_table[idx].end();
}

void hash_insert(int val_key, int time_key, int value) {
    int idx = hash_idx(val_key, time_key);
    hash_table[idx].push_back({val_key, time_key, value});
}

void hash_delete(int val_key, int time_key) {
    int idx = hash_idx(val_key, time_key);
    hash_table_iter_t it = hash_search(val_key, time_key);
    if (it == hash_table[idx].end()) return ;

    hash_table[idx].erase(it);
}

void hash_change(int val_key, int time_key, int value) {
    int idx = hash_idx(val_key, time_key);
    hash_table_iter_t it = hash_search(val_key, time_key);
    if (it == hash_table[idx].end()) return ;

    it->value = value;
}

/// heap implementation
struct heap_node_t {
    int value;
    int time_key;
};

int heap_size;
heap_node_t heap[nmax];
inline int left(int x)   { return 2 * x + 1; }
inline int right(int x)  { return 2 * x + 2; }
inline int parent(int x) { return x % 2 == 0 ? x / 2 - 1 : x / 2; }

/// min heap
inline bool check_property(int x, int y) {
    return heap[x].value <= heap[y].value;
}

void push_up(int i) {
    cout << i << endl;
    if (i == 0) return ;

    int parent_idx = parent(i);
    if (!check_property(parent_idx, i)) {
        printf ("%d %d\n", heap[parent_idx].value, heap[parent_idx].time_key);
        printf ("%d %d\n", heap[i].value, heap[i].time_key);
        hash_table_iter_t iter1 = hash_search(heap[parent_idx].value, heap[parent_idx].time_key);
        printf("%d %d\n", iter1->val_key, iter1->time_key, iter1->value);
        hash_table_iter_t iter2 = hash_search(heap[i].value, heap[i].time_key);
        printf("%d %d\n", iter2->val_key, iter2->time_key, iter2->value);
        iter1->value = i;
        iter2->value = parent_idx;

        swap(heap[parent_idx], heap[i]);
        push_up(parent_idx);
    }
}

void heap_insert(int x) {
    heap[heap_size].time_key = order_size;
    heap[heap_size++].value = x;
    printf ("HASH Add %d %d %d\n", x, order_size, heap_size - 1);

    push_up(heap_size - 1);

    order[order_size++] = x;
    hash_insert(x, order_size - 1, heap_size - 1);
}

void push_down(int i) {
    if (i >= heap_size) return ;

    int best = -1;
    if (left(i) < heap_size && check_property(left(i), right(i))) {
        best = left(i);
    } else if (right(i) < heap_size) {
        best = right(i);
    }

    if (best == -1) return ;
    if (!check_property(i, best)) {
        hash_table_iter_t iter1 = hash_search(heap[best].value, heap[best].time_key);
        hash_table_iter_t iter2 = hash_search(heap[i].value, heap[i].time_key);
        iter1->value = i;
        iter2->value = best;

        swap(heap[i], heap[best]);
        push_down(best);
    }
}

void heap_delete(int x) {
    hash_delete(heap[x].value, heap[x].time_key);
    hash_table_iter_t it = hash_search(heap[heap_size - 1].value, heap[heap_size - 1].time_key);
    it->value = x;

    heap[x].value = heap[--heap_size].value;
    heap[x].time_key = heap[heap_size].time_key;
    push_down(x);
}

int get_heap_min() {
    return heap[0].value;
}

/// helpers
int get_heap_index(int x) {
    int time_key = x;
    int val_key = order[x];
    hash_table_iter_t tmp = hash_search(val_key, time_key);

    return tmp->value;
}

void show(){
for(int i=0;i<heap_size;i++)cout<<heap[i].value<<" ";cout<<endl;
}

int main() {
    freopen("heapuri.in", "r", stdin);
    //freopen("heapuri.out", "w", stdout);

    int n;
    scanf("%d", &n);
    while (n--) {
        int op, x;
        scanf("%d", &op);

        if (op == 1) {
            scanf("%d", &x);
            printf("INSERT %d\n", x);
            heap_insert(x);
        } else if (op == 2) {
            scanf("%d", &x);
            int idx = get_heap_index(x - 1);
            printf("DELETE NODE %d\n", idx);
            heap_delete(idx);
        } else if (op == 3) {
            printf("MIN: %d\n", get_heap_min());
        }
        show();
    }

    return 0;
}


