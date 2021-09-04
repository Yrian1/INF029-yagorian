#include<stdio.h>
//crio uma struct do tipo Plv que guarda uma string
typedef struct Plv{
	char word[50];
}plv;

void Ler3palavras(plv* wrd);
int main(void){
	//crio um vetor do tipo struct Plv 
	plv words[3];
	//passando o vetor de struct Plv por parametro
	Ler3palavras(words);
	for(int i = 0; i < 3; i++){
		puts(words[i].word);
	}
}
void Ler3palavras(plv* wrd){
	for(int i = 0; i < 3; i++){
		scanf("%s", wrd[i].word);
	}
}
