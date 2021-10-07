#include<stdlib.h>
#define CPF_TAM 11
#define NOME_TAM 20
#define SEM_TAM 5
#define DISC_TAM 6
#pragma once
struct NASC_DATA{
		int dia;
		int mes;
		int ano;
	};

typedef struct DADOS_CAD{
	int matricula;
	char nome[NOME_TAM];
	char cpf[CPF_TAM];
	char gen;
	struct NASC_DATA Nasc_Data;
}Dados_Cad;

typedef  struct DISC_DADOS{
	char cod[DISC_TAM];
	char disc_nome[NOME_TAM];
	char sem[SEM_TAM];
	char prof[NOME_TAM];
}Disc_Dados;

void fcad(Dados_Cad *cadastro, int opt);
void cadtr(int opt);
void cadname(char *nome);
void cadcpf(char *cpf);
void cadgen(char *gen);
void caddata(struct NASC_DATA *Nasc_Data);
void srcmat(int *matricula, int opt);


void disc_cad();
void Cad_disc(Disc_Dados *disciplina);
void cod_disc(char *cod);
void nome_disc(char *discnome);
void sem_disc(char *sem);
void prof_disc(char *prof);
