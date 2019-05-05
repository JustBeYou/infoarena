#include<stdio.h>
	
#define LL long long
	
 
	
 
	
LL N,M;
	
 
	
LL getphi(LL nr)
	
{
	
	LL cur = nr;
	
	for(LL i = 2;i * i <= nr; ++i)
	
	{
	
		if (nr % i == 0)
	
		{
	
			while(nr % i == 0)nr /= i;
	
			cur = (cur / i) * (i - 1);
	
		}
	
	}
	
        if (nr != 1) cur = cur / nr * (nr - 1);
	
	return cur;
	
}
	
 
	
int main()
	
{
	
	freopen("inversmodular.in","r",stdin);
	
	freopen("inversmodular.out","w",stdout);
	
	scanf("%lld %lld\n",&N,&M);
	
        LL put = getphi(M) - 1;
	
	LL nr = N;
	
	LL crt = 1;
	
    for(LL p = 1;p <= put;p <<= 1)
	
    {
	
	 	if (p & put) crt = (crt * nr) % M;
	
	  	nr = (nr * nr) % M;
	
	}
	
	printf("%lld\n",crt);
	
	return 0;
	
}
	
 
