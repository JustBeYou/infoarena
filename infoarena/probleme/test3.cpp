#include <iostream>
	
#include <fstream>
	
#include <algorithm>
	
#include <vector>
	
#include <string>
	
 
	
using namespace std;
	
 
	
int main()
	
{
	
    ifstream in("strmatch.in");
	
    ofstream out("strmatch.out");
	
    
	
    string A;
	
    string B;
	
    getline(in, A);
	
    getline(in, B);
	
    
	
    int n = 0;
	
    size_t lenB = B.size();
	
    size_t lenA = A.size();
	
    vector<int> pos;
	
    
	
    if (lenA != lenB) {
	
        for (size_t i = 0; i < lenB; i++) {
	
            if (!B.compare(i, lenA, A)) {
	
                n++;
	
                pos.push_back(i);
	
            }
	
        }
	
    } else {
	
        if (!B.compare(A)) {
	
            n++;
	
            pos.push_back(0);
	
        }
	
    }
	
    
	
    out << n << "\n";
	
    for (int i = 0; i < n && i < 1000; i++) {
	
        out << pos[i] << " ";
	
    }
	
    out << "\n";
	
    
	
    in.close();
	
    out.close();
	
    return 0;
	
}
