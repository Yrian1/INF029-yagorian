#include"Bibliotecas/Escola-Bibli.h"
#include<string.h>

int validnome(char* nome){
	if(strlen(nome) > 20){
		return 0;
	}
 	return 1;
}

int validcpf(char* cpf){
	int i=0;
	while(i<11){
		if(cpf[i]<48 || cpf[i]>57){
			return 0;
			}
		i++;
	}
	if(i<11){
		return 0;
	}
	return 1;
}

int validgen(char gen){
	if(gen>92)
		gen-=32;
	if(gen==70 || gen==77 || gen==79){
		return 1;
		}
	return 0;
}
int validnas(struct NASC_DATA *nasdate){
	if(nasdate->dia < 1 || nasdate->dia > 31){
		return 0;
	}
	else if(nasdate->mes < 1 || nasdate->mes > 12){
		return 0;
	}	
	else if(nasdate->ano < 1900 || nasdate->ano > 2021){
		return 0;
	}
	return 1;
		
}

int valcod(char* cod){
	if(strlen(cod)!=SEM_TAM)
		return 0;
return 1;
}
int valdisc(char* discnome){
	if(strlen(discnome)>NOME_TAM)
		return 0;
return 1;
}
int valsem(char* sem){
	if(sem[4]!='.')
		return 0;
return 1;
}
int valprof(char* prof){
	if(strlen(prof)>NOME_TAM)
		return 0;
return 1;
}
