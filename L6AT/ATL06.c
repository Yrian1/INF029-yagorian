#include<stdio.h>
#include<string.h>

char* Ler3letras();
int main(void){
	char l3[3];
	strcpy(l3, Ler3letras());
	for(int i=0;i<3;i++)
		printf("%c\n", l3[i]);
}

char* Ler3letras(){
	static char ll3[3];
	puts("insira 3 letras de uma vez");
	for(int i=0; i<3; i++){
		fflush(stdin);
		scanf("%c", &ll3[i]);
		fflush(stdin);
		}
	return ll3;
}
