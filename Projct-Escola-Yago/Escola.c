#include<stdlib.h>
#include<stdio.h>
#include"Bibliotecas/Escola-Bibli.h"
#include"Bibliotecas/List.h"

#define MAX_LINE 40

void Hashtag_Line();

int main(void){
	char file[25];
	int opt1, opt2;

	Hashtag_Line();
	puts("Bem vindo ao Projeto Escola");
	do{
		printf(" Escolha uma opcao\nCadastrar(1)\nListar(2)\nsair(0)\n");
		scanf("%d", &opt1);
		Hashtag_Line();
		switch (opt1){
			case 1:
				printf("Cadastrar Aluno(1)\nCadastrar Professor(2)\nCadastrar disciplina(3)\nsair(0)\n");
				scanf("%d", &opt2);
				Hashtag_Line();
				switch (opt2){
					case 1:
						cadtr(opt2);
						break;
					case 2:
						cadtr(opt2);
						break;
					case 3:
						disc_cad();
						break;
					case 0:
						puts("Encerrando o programa");
						Hashtag_Line();
						return 1;
						break;
					}
				break;
			case 2:
				printf("Listar Alunos(1)\nListar Professores(2)\nListar Disciplinas(3)Sair(0)");
				scanf("%d", &opt2);
				Hashtag_Line();
				switch (opt2){
					case 1:
						strcpy(file, "Dados/Alunos.txt");
						Print_Txt(file);
						break;
					case 2:
						strcpy(file, "Dados/Professores.txt");
						Print_Txt(file);
						break;
					case 3:
						strcpy(file, "Dados/Disciplinas.txt");
						Print_Txt(file);
						break;
					case 0:
					puts("Encerrando o programa");
					Hashtag_Line();
					return 1;
					break;
				}
			break;
			case 0:
			puts("Encerrando o programa");
			Hashtag_Line();
			return 1;
			break;
		}
	Hashtag_Line();
	puts("Deseja voltar ao menu principal?\n(9)Voltar\n(0)Sair\n");
	scanf("%d", &opt1);
	Hashtag_Line();
	}while(opt1!=0);
	puts("Encerrando programa");
	return 1;
}
void Hashtag_Line(){
	
	for(int i = 0; i < MAX_LINE; i++)
		printf("#");
	printf("\n");
}
