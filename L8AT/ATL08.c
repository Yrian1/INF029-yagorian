#include<stdio.h>
#include "Library-ATL08.h"

struct Client{
	char nome[21];
	char cpf[11];
	char gen;
	struct Datnas nasdate;
};
cli cadcli();

int main(void){
	cli client;
	client = cadcli();
	puts("Cadastro realizado");
	puts("Dados:");
	printf("nome: %s.\n", client.nome);
	printf("cpf: ");
	for(int i = 0; i < 11; i++)
		printf("%c", client.cpf[i]);
	printf(".\n");
	//printf("cpf: %s.\n", client.cpf);
	printf("genero: %c.\n", client.gen);
	printf("Data de nascimento:%d/%d/%d.\n", client.nasdate.dia, client.nasdate.mes, client.nasdate.ano);
}
cli cadcli(){
	cli client;

	Cadnome(client.nome);
	Cadcpf(client.cpf);
	getchar();
	client.gen = Cadgen();
	client.nasdate = caddatnas();

return client;
}
