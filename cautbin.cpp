#include <bits/stdc++.h>
	
 
	
using namespace std;
	
const int NMAX = 100005;
	
 
	
ifstream fin("cautbin.in");
	
ofstream fout("cautbin.out");
	
 
	
int N, M, cer, val, Z;
	
unsigned int v[NMAX];
	
 
	
int read(){
	
    fin >> N;
	
    for(int i=1; i<N; i++){
	
        fin >> v[i];
	
        //cout << v[i] << ' ';
	
    }
	
}
	
 
	
int Search_0(int x, int y){
	
    int m;
	
    while (x <= y) {
	
        m = (x + y) / 2;
	
        if (v[m] <= val)
	
            x = m + 1;
	
        else
	
            y = m - 1;
	
    }
	
    m = (x + y) / 2;
	
    if(v[m] > val)
	
        m--;
	
    if(v[m] == val)
	
        return m;
	
    return -1;
	
}
	
 
	
int Search_1(int x, int y){
	
    int m;
	
    while(x < y){
	
        m = (x + y) / 2;
	
        if(v[m] <= val)
	
            x = m + 1;
	
        else
	
            y = m;
	
    }
	
    m = (x + y) / 2;
	
    if(v[m] > val)
	
        m--;
	
    return m;
	
}
	
 
	
int Search_2(int x, int y){
	
    int m;
	
    while(x < y){
	
        m = (x + y) / 2;
	
        if(v[m] < val)
	
            x = m + 1;
	
        else
	
            y = m;
	
    }
	
    m = (x + y) / 2;
	
	
    if(v[m] < val)
	
        m++;
	
    return m;
	
}
	
 
	
int main(){
	
 
	
    read();
	
    fin >> M;
	
    //cout << M;
	
    for(int j=0; j<M; j++){
	
        fin >> cer >> val;
	
        if(cer == 0){
	
            fout << Search_0(1, N) << endl;
	
        } else if(cer == 1){
	
            fout << Search_1(1, N) << endl;
	
        } else if(cer == 2){
	
            fout << Search_2(1, N) << endl;
	
        }
	
    }
	
 
	
    return 0;
	
}
