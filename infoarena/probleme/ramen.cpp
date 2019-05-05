#include <bits/stdc++.h>

using namespace std;

const int max_n = 100000;

vector<pair<int, int>> orders(max_n);
set<int> times;
vector<pair<int, int>> solution(max_n);

int main() {
    freopen("ramen.in", "r", stdin);
    freopen("ramen.out", "w", stdout);

    int n, d;
    cin >> n >> d;

    for (int i = 0; i < n; i++) {
        // time, seat
        // sort by seat
        cin >> orders[i].second >> orders[i].first;

        // insert the time + prep time into the set
        times.insert(orders[i].second + d);
    }

    // sort the orders
    sort(orders.begin(), orders.begin() + n);
    
    set<int>::iterator it;
    for (int i = 0; i < n; i++) {
        // search for the first order that could fit
        it = times.upper_bound(orders[i].second - orders[i].first - 1);

        // add into the solution
        solution[i].first = orders[i].second;
        solution[i].second = orders[i].first + *it;
        times.erase(it);
    }
    
    // sort solution by ordering time
    sort(solution.begin(), solution.begin() + n);
    for (int i = 0; i < n; i++) {
        cout << solution[i].second << "\n";
    }

    return 0;
}
