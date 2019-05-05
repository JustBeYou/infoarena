#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
const int nmax = 100000;

struct node {
    int max_left;
    int max_right;
    int sum_total;
    int max_sum;
    bool touch_left; // true if the right max sum seq touches the left bound
    bool touch_right; // same, but for left
};
node arbint[nmax * 4 + 66];
int v[nmax];

uint n, m;

void build(uint _node, uint _left, uint _right) {
    if (_left == _right) {
        arbint[_node].max_left = arbint[_node].max_right = arbint[_node].sum_total = arbint[_node].max_sum = v[_left];
        arbint[_node].touch_left = arbint[_node].touch_right = true;
        return ;
    }

    uint mid = (_left + _right) / 2;
    uint left_node = 2 * _node + 1;
    uint right_node = 2 * _node + 2;


    build(left_node, _left, mid);
    build(right_node, mid + 1, _right);

    arbint[_node].sum_total = arbint[left_node].sum_total + arbint[right_node].sum_total;
    // test left touching on sum max right
    if (arbint[right_node].touch_left) {

    } else {

    }

    // test right touching on sum max left
    if (arbint[left_node].touch_right) {

    } else {

    }
}

int result;
uint seg_left, seg_right;
void prep_query(uint a, uint b) {
    result = 0;
    seg_left = a;
    seg_right = b;
}

void query(uint _node, uint _left, uint _right) {

}

void show() {
    for (int i=0;i<n*4;i++){
        cout << arbint[i].sum_total<<" ";
    }cout<<endl;
    for (int i=0;i<n*4;i++){
        cout << arbint[i].max_sum<<" ";
    }cout<<endl;
}

int main() {
    freopen("sequencequery.in", "r", stdin);
    //freopen(".out", "w", stdout);

    scanf("%u%u", &n, &m);
    for (uint i=0; i<n;i++) {
        scanf("%d", &v[i]);
    }

    build(0, 0, n - 1);
    show();
    cout << arbint[0].max_left << " " << arbint[0].max_right << "\n";

    uint x, y;
    for (uint i=0;i<m;i++){
        scanf("%u %u", &x, &y);
        prep_query(x - 1, y - 1);
        query(0, 0, n - 1);
        printf("%d\n", result);
    }

    return 0;
}


