#include<stdio.h>
//somatorio de n recursivo
int sumn(int n){
	if(n<0) return 0;
	return n+sumn(n-1);
	
}
int main(void){
	int n, rslt;
	n=7;
	rslt=sumn(n);

	printf("%d\n", rslt);

}
