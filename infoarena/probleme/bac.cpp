#include <iostream>
#include <fstream>

using namespace std;

int frecv[100 + 1];
int main() {
	ifstream f("bac.txt");

	while (!f.eof()) {
		int x;
		f >> x;
		frecv[x]++;
	}

	int grad_n_max = 0;
	int grad_n = 0;
	for (int i = 0; i < 101; i++) {
		if (frecv[i] == 0) {
			grad_n_max = max(grad_n_max, grad_n);
			grad_n = 0;
		} else {
			grad_n += frecv[i];
		}
	}
	grad_n_max = max(grad_n_max, grad_n);

	cout << grad_n_max << endl;
	return 0;
}
