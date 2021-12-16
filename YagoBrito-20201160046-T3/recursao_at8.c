#include<stdio.h>

int domdc(int y, int x){

	if(y==0) return x;
	return domdc(x, y%x);
}

int main(void){
	int x, y, mdc;
	x=70;
	y=21;
	mdc=domdc(y,x);

	printf("%d\n", mdc);
}
