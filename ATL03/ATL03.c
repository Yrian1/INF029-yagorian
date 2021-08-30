#include<stdio.h>
#include<math.h>
//atividade da numero 3 da lista de funcoes 
//Aluno: Yago Rian | Prof roberto novais | 2021
unsigned int fat(int n);
int main(void){
	int n;
	unsigned int result;
	puts("Insira um numero para calcularmos o fatorial caso possivel");
	scanf("%d", &n);
	result=fat(n);
	if(result==0){
		puts("nao eh possivel calcular o fatorial o numero e muito grande");
		return 0;
	}
	printf("o fatorial eh: %u\n", result);
}
	unsigned int fat(int n){
	unsigned int ftr=n;
	//Eu uso o Max para verificar se sera possivel calcular o fatorial
	//ele eh definido 2 elevado a 32 que e o maior de um inteiro sem sinal que a arquitetura do meu processador permite 
	//que sao 32 bits
	unsigned int Max= pow(2,32)/2;
	for(int i = 1; i < n-2; i++){
		ftr*=n-i;
		if(ftr>Max){
		return 0;
		}
	}
	if(ftr>2){
		return ftr*2;
	}
	return ftr;

}
