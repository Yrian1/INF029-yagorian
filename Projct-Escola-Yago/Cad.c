#include<stdio.h>
#include<stdlib.h>
#include"Bibliotecas/Escola-Bibli.h"
#include"Bibliotecas/Valid.h"
#include<string.h>
void cadtr(int opt){
	Dados_Cad cadastro;
	char confirm;

	srcmat(&cadastro.matricula, opt);
	cadname(cadastro.nome);
	cadcpf(cadastro.cpf);
	cadgen(&cadastro.gen);
	caddata(&cadastro.Nasc_Data);
	puts("Deseja confirmar o cadastro. (s)confirma.");
	scanf(" %c", &confirm);
	if(confirm!='s'){
		puts("Cadastro cancelado");
		return;
	}
	fcad(&cadastro, opt);
return;
} 
void fcad(Dados_Cad *cadastro, int opt){

	FILE *FA;
		if(opt==1){
		FA=fopen("Dados/Alunos.txt", "a");
		}
		else if(opt==2){
		FA=fopen("Dados/Professores.txt", "a");
		}
		if(FA==NULL){
			puts("Problemas tecnicos");
			return;
		}
		fprintf(FA, "MATRICULA %d\n", cadastro->matricula);
		fprintf(FA, "NOME %s\n", cadastro->nome);
		fputs("CPF ", FA);
		for(int i = 0; i < CPF_TAM; i++)
			fprintf(FA, "%c", cadastro->cpf[i]);
		fputs("\n", FA);
		fprintf(FA, "GEN %c\n", cadastro->gen);
		fprintf(FA, "DATNAS %d/", cadastro->Nasc_Data.dia);
		fprintf(FA, "%d/", cadastro->Nasc_Data.mes);
		fprintf(FA, "%d\n", cadastro->Nasc_Data.ano);
		

fclose(FA);

}

void cadname(char *nome){
	int valid=0;
	puts("Insira nome com ate 20 caracteres");
	while(!valid){
	scanf(" %[^\n]s", nome);
	valid = validnome(nome);
	if(!valid){
		puts("insira um nome como solicitado");
		}	
	}
}
void cadcpf(char *cpf){
	int valid=0;
	puts("Insira o cpf. So numeros");
	while(!valid){
	scanf(" %s", cpf);
	valid = validcpf(cpf);
	if(!valid)
		puts("Voce inseriu um Cpf invalido tente novamente.");
	}	
}
void cadgen(char *gen){
	int valid=0;
	puts("Insira o genero.(M)Masculino, (F) Feminino ou (O)Outros");
	while(!valid){
	scanf(" %c", gen);
	valid = validgen(*gen);
	if(!valid)
		puts("Voce inseriu um genero invalido tente novamente.");
	}	
}
void caddata(struct NASC_DATA *Nasc_Data){
	int valid=0;
	puts("Insira a data de nascimento.EX: DD/MM/AAAA");
	while(!valid){
	scanf(" %d/%d/%d", &Nasc_Data->dia, &Nasc_Data->mes, &Nasc_Data->ano);
	valid = validnas(Nasc_Data);
	if(!valid)
		puts("Voce inseriu uma data de nascimento invalida tente novamente.");
	}	
}

void srcmat(int *matricula, int opt){
	char mat[9];
	int count=1;
	FILE *FA;
	if(opt==1){
	FA=fopen("Dados/Alunos.txt", "r");
	}
	else if(opt==2){
	FA=fopen("Dados/Professores.txt", "r");
	}
	if(FA){
		while(!feof(FA)){
			fscanf(FA, "%s ", mat);
			if(strcmp(mat, "MATRICULA")==0)
				count++;
		}
	}
	
	fclose(FA);
	*matricula=20210000+count;
}
void disc_cad(){
	Disc_Dados disciplina;

	cod_disc(disciplina.cod);
	nome_disc(disciplina.disc_nome);
	sem_disc(disciplina.sem);
	prof_disc(disciplina.prof);

	Cad_disc(&disciplina);
}
void Cad_disc(Disc_Dados *disciplina){
	FILE *FD;
	FD=fopen("Dados/Disciplinas.txt", "a");
	if(FD!=NULL){
		fprintf(FD, "COD %s\n", disciplina->cod);
		fprintf(FD, "NOME %s\n", disciplina->disc_nome);
		fprintf(FD, "NOME %s\n", disciplina->sem);
		fprintf(FD, "NOME %s\n", disciplina->prof);
	}
	fclose(FD);
}
void cod_disc(char *cod){
	int valid=0;
	puts("Insira codigo da disciplina com 6 caracteres. Ex:COD145");
	while(valid==0){
		scanf("%s", cod);
		valid=valcod(cod);
		if(valid==0)
			puts("Insira um codigo como solicitado");
	}

}
void nome_disc(char* discnome){
	int valid=0;
	puts("Insira nome da disciplina com ate 20 caracteres");
	while(valid==0){
		scanf("%s", discnome);
		valid=valdisc(discnome);
		if(valid==0)
			puts("Insira um nome da disciplina como solicitado");
	}
	
}
void sem_disc(char* sem){
	int valid=0;
	puts("Insira o semestre da disciplina com 5 caracteres. Ex:2021.1");
	while(valid==0){
		scanf("%s", sem);
		valid=valsem(sem);
		if(valid==0)
			puts("Insira o semestre como solicitado");
	}
}
void prof_disc(char* prof){
	int valid=0;
	puts("Insira o nome do professor da disciplina com ate 20 caracteres");
	while(valid==0){
		scanf("%s", prof);
		valid=valprof(prof);
		if(valid==0)
			puts("Insira o nome do professor como solicitado");
	}
}
