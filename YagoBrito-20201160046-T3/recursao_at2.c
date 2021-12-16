#include<stdio.h>
#include<stdlib.h>

//fibonacci recursivo
void dofibo(int fibo, int *fib, int count){
	if(count>fibo) return;
	fib[count]=fib[count-1]+fib[count-2];
	dofibo(fibo, fib, count+1);

}

int main(void){
	int fibo, *fib;
	//alterar oo valor de fibo para o resultado desejado
	fibo=12;

	fib=malloc(sizeof(int)*fibo);
	fib[0]=0;
	fib[1]=fib[2]=1;

	dofibo(fibo, fib, 3);
	printf("%d\n", fib[fibo-1]);

}
