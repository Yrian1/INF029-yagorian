#include<stdio.h>

int mult(int n1, int n2){
	if(n2<=1) return n1;
	return n1+mult(n1, n2-1);
}
int main(void){
	int n1, n2, rslt;
	n1=3;
	n2=7;
	rslt=mult(n1, n2);

	printf("%d\n", rslt);
}
