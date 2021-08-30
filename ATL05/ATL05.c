#include<stdio.h>
#define TAM 4
//Atividade numero 5 da list
//Aluno: Yago rian | Pro: Renato Novais | 2021
struct mSeq{
int a, b, c, d;
};
struct mSeq ler4numeros();
int main(void){
	struct mSeq seq;
	seq=ler4numeros();
	printf("voce inseriu: %d, %d, %d, %d", seq.a, seq.b, seq.c, seq.d);
}
struct mSeq ler4numeros(){
	struct mSeq sqnum;
	puts("insira 4 numeros");
	scanf("%d %d %d %d", &sqnum.a, &sqnum.b, &sqnum.c, &sqnum.d);
	return sqnum;
}
