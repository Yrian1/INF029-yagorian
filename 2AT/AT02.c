#include<stdio.h>

void main(){
	int result=0, num;
	char option;
	puts("|\tInsira '1' para efetuar uma somatoria;|\n|\tInsira '2' para efetuar uma subtracao;|\n|\tInsira '3' para multiplicar;          |\n|\tInsira '4' para efetuar uma divisao;  |\n|\tInsira '0' para sair                  |\n");
	scanf("%c", &option);
	switch (option){
		case '1':
			puts("Insira quantos numeros desejar somar e 0 para parar\n");
			do{
			scanf("%d", &num);
			fflush(stdin);
			result+=num;
			printf(" O resultado da soma eh: %d\n", result);
			}while(num!=0);
			break;
		case '2':
			puts("insira um numero\n");
			fflush(stdin);
			scanf("%d", &result);
			puts("insira outro numero para subtrair do primeiro\n");
			fflush(stdin);
			scanf("%d", &num);
			result-=num;
			printf("resultado igual a: %d\n", result);
			break;
		case '3':
			puts("insira o primeiro fator da multiplicacao\n");
			fflush(stdin);
			scanf("%d", &num);
			puts("insira o segundo fator para efetuar a multiplicacao\n");
			scanf("%d", &result);
			result*=num;
			printf(" O resultado eh igual a:%d\n", result);
			break;
		case '4':
			puts("Insira o divisor\n");
			fflush(stdin);
			scanf("%d", &num);
			fflush(stdin);
			puts("insira o dividendo\n");
			scanf("%d", &result);
			result/=num;
			printf("O resultado da divisao eh igual a: %d\n", result);
		default:
		break;
	}
	
}
