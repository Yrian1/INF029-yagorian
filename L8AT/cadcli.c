#include<stdio.h>
#include "Library-ATL08.h"

void Cadnome(char* clinome){
	int valid=0, i;
	char a;
	puts("insira nome");
	do{
		
	for(i = 0 ; i < 21 ; i++)
			clinome[i]='\0';
		scanf(" %[^\n]s", clinome);
		valid=validnome(clinome);
	}while(valid!=1);
	while((getchar()) != '\n');
}
void Cadcpf(char* clicpf){
	int valid=0;
	clicpf[10]='\0';
        puts("insira cpf, so numeros");
	do{
		scanf(" %s", clicpf);
		valid=validcpf(clicpf);
	}while(valid!=1);
//	while((getchar()) != '\n');
}
char Cadgen(){
	int valid=0;
	char gen;
        puts("insira o genero, masculino='M', feminino='F', outros='O'");
	do{
        //scanf(" %c", &gen);
	gen=getchar();
	valid=validgen(gen);
	}while(valid!=1);
	while((getchar()) != '\n');
	return gen;
}

struct Datnas caddatnas(){
	int valid=0;
	struct Datnas nasdate;
        puts("insira data de nascimento no formato:dd/mm/aaaa");
	do{
        scanf("%d/%d/%d", &nasdate.dia, &nasdate.mes, &nasdate.ano);
	valid=validnas(nasdate);
	}while(valid!=1);
        return nasdate;
}
