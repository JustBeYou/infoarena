	
#include <bits/stdc++.h>
	
 
	
using namespace std;
	
 
	
const int max_n = 100000;
	
int n;
	
 
	
struct nums {
	
  int n;
	
  int orig;
	
  int p2;
	
  int p3;
	
 
	
  bool operator<(nums &rhs) {
	
    if (p2 == rhs.p2) return p3 > rhs.p3;
	
    return p2 < rhs.p2;
	
  }
	
};
	
nums v[max_n];
	
 
	
bool solvable = true;
	
 
	
int main() {
	
  freopen("calorifer.in", "r", stdin);
	
  freopen("calorifer.out", "w", stdout);
	
 
	
  cin >> n;
	
  for (int i=0;i<n;i++){
	
    cin>>v[i].n;
	
    v[i].orig = v[i].n;
	
 
	
    while (v[i].n % 2 == 0) {
	
      v[i].p2++;
	
      v[i].n /= 2;
	
    }
	
 
	
    while (v[i].n % 3 == 0) {
	
      v[i].p3++;
	
      v[i].n /= 3;
	
    }
	
 
	
 
	
    if (i > 0 && v[i].n != v[i -1].n) {
	
      solvable = false;
	
      break;
	
    }
	
  }
	
 
	
  if (!solvable) {
	
    cout << "-1\n";
	
    return 0;
	
  }
	
 
	
  sort(v, v+n);
	
  //for (int i=0;i<n;i++){ 
	
  //  cout << v[i].orig <<" "<< v[i].p3 << " "<<v[i].p2 << " "<<v[i].n<<endl;
	
  //}
	
 
	
  for (int i = n-1; i>=0;i--) {
	
    cout << v[i].orig << " ";
	
  }
	
  cout << "\n";
	
 
	
  return 0;
	
}
