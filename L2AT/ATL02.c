#include<stdio.h>
//2 exercicio de funcao: subtrair 3 numeros
//Aluno: Yago Rian | Prof: Roberto Novais | 2021
int fsub(int a, int b, int c);
int main(void){

	int a, b, c, result;

	puts("insira 3 valores para efetuar a subtracao");

	scanf("%d %d %d", &a, &b, &c);

	result=fsub( a, b, c);

	printf(" O resultado da subtracao eh: %d\n", result);
}
int fsub(int a, int b, int c){
return a-b-c;
}
