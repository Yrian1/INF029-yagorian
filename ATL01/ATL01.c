#include<stdio.h>
int fsoma(int a, int b);
int main(void){
	int a, b, soma;
	puts("insira dois numeros para efetuar a soma");
	fflush(stdin);
	scanf("%d %d", &a, &b);
	soma=fsoma(a, b);
	printf("o resultado eh: %d\n", soma);
}

int fsoma(int a, int b){
return a+b;
}
