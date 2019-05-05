#include <cstdio>

#include <cmath>

#include <algorithm>

#include <vector>

#include <cstring>



const int MAX_N = 100000;

const int MAX_M = 100000;

const int MAX_VAL = 100000;

const int BUCKET_SIZE = 5;



int bucket(int index) {

  return index / BUCKET_SIZE;

}



struct Query {

  int left;

  int right;

  int index;



  bool operator <(const Query &other) const {

    return bucket(this->left) < bucket(other.left) || (bucket(this->left) == bucket(other.left) && this->right < other.right);

  }

};



int n;

int a[6 + MAX_N];

int freq[6 + MAX_VAL];

int ansQuery[5 + MAX_M];

std::vector<Query> nush_ce_gresesc;

std::vector<Query> queries[5 + BUCKET_SIZE];



void addFreq(int left, int right, int &ans) {

    printf("add from %d to %d\n", left, right);
  for (int i = left; i <= right; i++) {

    freq[a[i]]++;

    if (freq[ans] < freq[a[i]])

      ans = a[i];

    else if (freq[ans] == freq[a[i]] && a[i] < ans)

      ans = a[i];

  }

}



void removeFreq(int left, int right) {
    printf("remove from %d to %d\n", left, right);

  for (int i = left; i <= right; i++)

    freq[a[i]]--;

}



void solve(int bucket) {

  memset(freq, 0, sizeof(freq));

  int rightBucket = (bucket + 1) * BUCKET_SIZE - 1;

  int lastRight = rightBucket;

  int sol = 0;

  for (auto query : queries[bucket]) {

    int left, right, index;

    left = query.left;

    right = query.right;

    index = query.index;

    printf("solving query %d - %d\n", left, right);

    addFreq(lastRight + 1, right, sol);

    printf("ans (1) %d [%d]\n", sol, freq[sol]);

    int ans = sol;

    addFreq(left, rightBucket, ans);

    ansQuery[index] = ans;

    printf("ans (2) %d [%d]\n", ans, freq[ans]);

    removeFreq(left, rightBucket);

    lastRight = right;

    printf("\n");
  }

}



int main() {

  freopen("rangemode.in", "r", stdin);

  //freopen("rangemode.out", "w", stdout);



  int m;

  scanf("%d%d", &n, &m);

  for (int i = 1; i <= n; i++)

    scanf("%d", &a[i]);

  for (int i = 1; i <= m; i++) {

    int left, right;

    scanf("%d%d", &left, &right);

    if (bucket(left) == bucket(right)) {
        printf("fast solving %d - %d\n", left, right);

      addFreq(left, right, ansQuery[i]);

      removeFreq(left, right);

    } else {

      nush_ce_gresesc.push_back({left, right, i});

    }

  }

  printf("\n\n");
  std::sort(nush_ce_gresesc.begin(), nush_ce_gresesc.end());

  for (auto it : nush_ce_gresesc)

    queries[bucket(it.left)].push_back(it);

  for (int i = 0; i < BUCKET_SIZE; i++){
    printf("BUCKET %d\n", i);
    solve(i);
    printf("\n\n");
    }

  for (int i = 1; i <= m; i++)

    printf("%d\n", ansQuery[i]);

  return 0;

}
