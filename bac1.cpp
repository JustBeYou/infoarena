#include <iostream>
 
using namespace std;
int ordonat(int n, int v[101], int k1, int k2){
int test=1, i;
for(i=k1;i<=k2-1;i++){ // aici testeaza daca sunt crescatoare el din [k1,k2]
    if(v[i] > v[i+1])
        test=0;
}
return test;
}
int main()
{
    int n, v[101], sir_curent=1, sir_max=0;
    int i,j,k1,k2;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>v[i];}
    for(i=1;i<=n-1;i++)
    {
        j = i+1;
        while(ordonat(n,v,i,j)){ // de fiecare data cand sirul e crescator ii mai adauga un termen
            sir_curent++;
            j++;
        }
        cout << i << " " << j - 1 << " " << sir_curent << endl;
        if(sir_curent > sir_max){
            k1=i;                       // testeaza daca e sirul de lungime maxima si ii modifica maximele
            k2=j-1;
            sir_max= sir_curent;
        }
        sir_curent=1;
    }
    cout<< endl << k1 << " " << k2;
    return 0;
}
