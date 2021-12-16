#include<stdio.h>

int eleva(int k, int n){
	if(n<=1) return k;
	return k*eleva(k, n-1);
}
int main(void){
	int k, n;
	long unsigned rslt;
	k=2;
	n=5;
	
	rslt=eleva(k, n);
	printf("%lu", rslt);
}
