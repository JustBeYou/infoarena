	
#include <iostream>
	
#include <vector>
	
#include <algorithm>
	
using namespace std;
	
int matrix[301][301];

void gen(int N) {	
	vector<int> v;
	
 
	
	
	for (int i = 1; i <= N; ++i)
	
		v.push_back(i);
	
  int m = 0;
	do {

    m = 0;
		for (int i = 0; i < N - 1; ++i)
      if (v[i] < v[i + 1]) m++;
   
    matrix[N][m]++;


	} while (next_permutation(v.begin(), v.end()));
	
}
	
int main () {	
 
  for (int i = 1; i <= 8; i++) {
    gen(i);
  }

  for (int i = 0; i <= 8; i++) {
    for (int j = 0; j <= 8; j++) {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
}
