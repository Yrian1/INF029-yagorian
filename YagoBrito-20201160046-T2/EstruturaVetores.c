#include <stdio.h>
#include <stdlib.h>
#define TAM 10

#include "EstruturaVetores.h"


	Aux_Vet Main_Struct[TAM];

int Mk_Aux_Vet(Aux_Vet *adress,int  pos,int tm){

	if(pos<=0 || pos>10)
		return POSICAO_INVALIDA;
	if(adress->aStruct!=NULL)
		return JA_TEM_ESTRUTURA_AUXILIAR;

	if((adress->aStruct=(int*)calloc(tm, sizeof(int)))==NULL)
			return SEM_ESPACO_DE_MEMORIA;
	adress->tm=tm;
	adress->index=0;

	return SUCESSO;
}

/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'

Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho deve ser maior ou igual a 1
*/
int criarEstruturaAuxiliar(int posicao, int tamanho)
{

    int retorno = 0;
    if(tamanho<1){
	    retorno=TAMANHO_INVALIDO;
    }
    else if((retorno=ehPosicaoValida(posicao))==SUCESSO){
    retorno=Mk_Aux_Vet(&Main_Struct[posicao-1], posicao, tamanho);
    }

    return retorno;
}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int Ins_Num(Aux_Vet *arr, int num){

	if(arr->index>=arr->tm){
		return SEM_ESPACO;
	}
	else if(arr->aStruct==NULL){
		return SEM_ESTRUTURA_AUXILIAR;
	}
			arr->aStruct[arr->index]=num;
			arr->index++;
			return SUCESSO;

}
int inserirNumeroEmEstrutura(int posicao, int valor)
{
    int retorno = 0;

	if(posicao<1||posicao>10){
		retorno=POSICAO_INVALIDA;
	}
	else{
		retorno=Ins_Num(&Main_Struct[posicao-1], valor);
	}

    return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica

Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int Rm_fim(Aux_Vet *arr){
	 if(arr->aStruct==NULL){
		return SEM_ESTRUTURA_AUXILIAR;
	}
	else if(arr->index==0){
		return ESTRUTURA_AUXILIAR_VAZIA;
	}
	else{
		arr->index--;
		return SUCESSO;
	}
}
int excluirNumeroDoFinaldaEstrutura(int posicao)
{
    int retorno = SUCESSO;
    if(posicao<1||posicao>10){
	    retorno=POSICAO_INVALIDA;
    }
    else{
	    retorno=Rm_fim(&Main_Struct[posicao-1]);
    }
    return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar

*/
int Excluir_Num(Aux_Vet *arr, int num){

	int j=0;
	if(arr->aStruct==NULL){
		return SEM_ESTRUTURA_AUXILIAR;
	}
	else if(arr->index==0){
		return ESTRUTURA_AUXILIAR_VAZIA;
	}
	else{
		for(int i=0; i<arr->index; i++){
			if(num==arr->aStruct[i]){
				for(j=i; j<arr->index; j++){
					arr->aStruct[j]=arr->aStruct[j+1];
				}
			arr->index--;
			return SUCESSO;
			}
		}
	return NUMERO_INEXISTENTE;
	}
}
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor){
    int retorno = SUCESSO;
    if(posicao<1||posicao>10){
	    return POSICAO_INVALIDA;
    }
    else{
	    retorno=Excluir_Num(&Main_Struct[posicao-1], valor);
    }
    return retorno;
}

// se posição é um valor válido {entre 1 e 10}
int ehPosicaoValida(int posicao){
    int retorno = 0;
    if (posicao < 1 || posicao > 10)
    {
        retorno = POSICAO_INVALIDA;
    }
    else
        retorno = SUCESSO;

    return retorno;
}
/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int Pass_Arr(Aux_Vet *ax_struct,int *bvet){

    if(ax_struct->aStruct==NULL){
	    return SEM_ESTRUTURA_AUXILIAR;
    }
    else if(ax_struct->index==0){
	    return ESTRUTURA_AUXILIAR_VAZIA;
    }
	for(int i=0; i<ax_struct->index; i++)
		bvet[i]=ax_struct->aStruct[i];
	return SUCESSO;
}
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
	
    int retorno = 0;
    if(posicao>10 || posicao<1){
	    retorno=POSICAO_INVALIDA;
    }
    else{
	    retorno=Pass_Arr(&Main_Struct[posicao-1], vetorAux);
	}
    
    return retorno;
}

/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int Ordem_Strc(Aux_Vet *ax_struct, int *bVet){
	
	if(ax_struct->aStruct==NULL){
		return SEM_ESTRUTURA_AUXILIAR;
    }
    else if(ax_struct->index==0){
	    return ESTRUTURA_AUXILIAR_VAZIA;
    }
	int i, j, aux=0;
	for(i = 0; i<=ax_struct->index; i++){
		bVet[i]=ax_struct->aStruct[i];
	}
	for(i = 0; i<ax_struct->index; i++){
		for(j=i+1; j<ax_struct->index; j++){
			if(bVet[i]>bVet[j]){
				aux=bVet[i];
				bVet[i]=bVet[j];
				bVet[j]=aux;
			}
		}
	}
	//for(i=1; i<=bVet[0]; i++)
	//	printf("%d: %d\n", i, bVet[i]);
	return SUCESSO;
}
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[])
{

    int retorno = 0;
    if((retorno=ehPosicaoValida(posicao))==SUCESSO){
	    retorno=Ordem_Strc(&Main_Struct[posicao-1], vetorAux);
    }

    return retorno;
}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int All_Numbers(Aux_Vet Strc_Main[], int vetorAux[], int *k){
	int i, j;
	*k=0;
	for(i=0; i<TAM; i++){
		if(Strc_Main[i].index>0){
			for(j = 0; j<Strc_Main[i].index; j++){
				vetorAux[*k]=Strc_Main[i].aStruct[j];
				*k+=1;
			}
		}
	}
	if(*k==0)
		return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
	else
		return SUCESSO;
}
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[])
{

    int retorno = 0;
    int k;
	retorno=All_Numbers(Main_Struct, vetorAux, &k);
    return retorno;
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
void ordem(int vetorAux[], int *k){

	int aux;
	for(int i = 0; i<*k; i++){
		for(int j=i+1; j<*k; j++){
			if(vetorAux[i]>vetorAux[j]){
				aux=vetorAux[i];
				vetorAux[i]=vetorAux[j];
				vetorAux[j]=aux;
			}
		}
	}
}
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[])
{

    int retorno = 0;
    int k;
	retorno=All_Numbers(Main_Struct, vetorAux, &k);
	if(retorno==SUCESSO){
		ordem(vetorAux, &k);
	}
    return retorno;
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1

Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int Rlc_Strc(Aux_Vet *arr, int nt){

    if(arr->aStruct==NULL){
	    return SEM_ESTRUTURA_AUXILIAR;
    }
    else if(arr->tm+nt<1){
	    return NOVO_TAMANHO_INVALIDO;
    }
	else if((arr->aStruct=(int *)realloc(arr->aStruct, sizeof(int)*(arr->tm+nt)))==NULL){
		return SEM_ESPACO_DE_MEMORIA;
	}
	else{
		arr->tm+=nt;
		if(nt<0){
			arr->index+=nt;
		}
		return SUCESSO;
	}
}
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho)
{

    int retorno = 0;
    if((retorno=ehPosicaoValida(posicao))==SUCESSO){
	    retorno=Rlc_Strc(&Main_Struct[posicao-1], novoTamanho);
    }
    return retorno;
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.

Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao)
{

    int retorno = 0;
     if(ehPosicaoValida(posicao)!=SUCESSO){
	    retorno=POSICAO_INVALIDA;
    }
    else if(Main_Struct[posicao-1].aStruct==NULL){
	    retorno=SEM_ESTRUTURA_AUXILIAR;
    }
     else if(Main_Struct[posicao-1].index==0){
	    retorno=ESTRUTURA_AUXILIAR_VAZIA;
    }
    else{
	    retorno=Main_Struct[posicao-1].index;
    }

    return retorno;
}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.

Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
/*No *montarListaEncadeadaComCabecote()
{

    return NULL;
}*/

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
/*
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[])
{
}
*/
/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.

Retorno 
    void.
*/
/*
void destruirListaEncadeadaComCabecote(No **inicio)
{
}
*/
/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa 

*/
/*
void inicializar()
{
}
*/
/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa 
para poder liberar todos os espaços de memória das estruturas auxiliares.

*/
/*
void finalizar()
{
}
*/
