#include<stdio.h>
typedef struct Client{
	char nome[21];
	char cpf[12];
	char gen;
	struct Datnas{
		int dia;
		int mes;
		int ano;
	}datnas;
}cli;
cli cadcli();

void Cadnome(char* clinome);
void Cadcpf(char* clicpf);
char Cadgen();
struct Datnas caddatnas();

int main(void){
	cli client;
	client = cadcli();
	puts("Cadastro realizado");
	puts("Dados:");
	printf("nome: %s;\ncpf: %s;\ngenero:%c;\nData de nascimento:%d/%d/%d;\n", client.nome, client.cpf, client.gen, client.datnas.dia, client.datnas.mes, client.datnas.ano);
}
cli cadcli(){
	cli client;

	Cadnome(client.nome);
	Cadcpf(client.cpf);
	getchar();
	client.gen = Cadgen();
	client.datnas = caddatnas();

return client;
}

void Cadnome(char* clinome){
	puts("insira nome");
	fgets(clinome, 21, stdin);
		fflush(stdin);
		for(int i=0; i<21; i++)
			if(clinome[i]=='\n')
				clinome[i]='\0';
}
void Cadcpf(char* clicpf){
	puts("insira cpf, so numeros");
	fgets(clicpf, 12, stdin);
		fflush(stdin);

}
char Cadgen(){
	char gen;
	puts("insira o genero, masculino='m', feminino='f', outros='o'");
	scanf("%c", &gen);
		fflush(stdin);
	return gen;
}

struct Datnas caddatnas(){
	struct Datnas datnas;
	puts("insira data de nascimento no formato:dd/mm/aaaa");
	scanf("%d/%d/%d", &datnas.dia, &datnas.mes, &datnas.ano);
		fflush(stdin);
	return datnas;
}
