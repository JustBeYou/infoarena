#include <stdio.h>
	
#include <map>
	
 
	
using namespace std;
	
 
	
int N, NR;
	
map <int, int> M;
	
 
	
int main()
	
{
	
	freopen("hashuri.in", "r", stdin);
	
	freopen("hashuri.out", "w", stdout);
	
 
	
	int i, tip, x;
	
 
	
	scanf("%d ", &N);
	
 
	
	for (i = 1; i <= N; i++) 
	
	{
	
		scanf("%d %d ", &tip, &x);
	
 
	
		if (tip == 1 && M.find(x)==M.end()) M[x] = ++NR;
	
		if (tip == 2) M.erase(x);
	
		if (tip == 3) printf("%d\n", M.find(x) != M.end());
	
	}
	
 
	
	return 0;
	
}
