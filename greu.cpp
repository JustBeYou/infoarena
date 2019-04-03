	
#include <fstream>
	
#include <cstring>
	
std::ifstream cin("grea.in");
	
std::ofstream cout("grea.out");
	
using namespace std;
	
#define maxn 250002
	
 
	
char v[2][maxn];
	
int n,k;
	
 
	
int main()
	
{
	
	cin>>n>>k;
	
	cin>>v[0];
	
	cin>>v[1];
	
	int poz=0,linie=0,pas=0,aux;
	
	while(poz<(n-1)){
	
		aux=k;
	
		while(poz+aux>(n-1))aux--;
	
		while(v[linie^1][poz+aux]==1){
	
			if(v[linie][poz+1]==0)
	
				poz++,pas++;
	
			else
	
				aux--;
	
		}
	
		if(poz+aux==n){
	
			pas++;
	
			break;
	
		}
	
		poz+=aux;
	
		pas++;
	
		linie^=1;
	
	}
	
	cout<<pas;
	
}
