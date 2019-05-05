#include <fstream>

#include <vector>

#include <cstring>



using namespace std;



const int MAXN = 20;

const int MAXX = 262150;

const int INF = 1000000000;



int N, M, Sol;

vector <int> A[MAXN];

int C[MAXX][MAXN];

int Cost[MAXN][MAXN];



int calc(int conf, int last)

{

	if (C[conf][last] == -1)

	{

		C[conf][last] = INF;



		for (size_t i = 0; i < A[last].size(); ++i) // parcurg nodurile care arata spre ultimul nod din lant

			if (conf & (1 << A[last][i]))  // le aleg doar pe cele care apartin lantului

			{

				if (A[last][i] == 0 && conf != (1<<(last)) + 1) continue; // nodul 1 trebuie sa il scot ultimul



				C[conf][last] = min(C[conf][last], calc(conf ^ (1<<last), A[last][i]) + Cost[A[last][i]][last]);

			}

	}



	return C[conf][last];

}



int main()

{

	ifstream fin("hamilton.in");

	ofstream fout("hamilton.out");



	Sol = INF;



	fin >> N >> M;



	for (int i = 0; i < N; ++i)

		for (int j = 0; j < N; ++j) Cost[i][j] = INF;



	for (int i = 1; i <= M; ++i)

	{

		int x, y;



		fin >> x >> y;

		A[x].push_back(y);

		fin >> Cost[y][x];

	}



	memset(C, -1, sizeof(C));

	C[1][0] = 0;



	for (size_t i = 0; i < A[0].size(); ++i)

		Sol = min(Sol, calc((1<<N)-1, A[0][i]) + Cost[A[0][i]][0]);



	if (Sol == INF) fout << "Nu exista solutie" << endl;

	else fout << Sol << endl;



	return 0;

}
