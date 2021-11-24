#include<stdlib.h>
#ifndef Lib_Pointers_h
#define Lib_Pointers_h

#define TAM 10
enum { TODAS_ESTRUTURAS_AUXILIARES_VAZIAS = -11, NOVO_TAMANHO_INVALIDO, NUMERO_INEXISTENTE,
       ESTRUTURA_AUXILIAR_VAZIA, TAMANHO_INVALIDO, SEM_ESPACO_DE_MEMORIA, POSICAO_INVALIDA,
       JA_TEM_ESTRUTURA_AUXILIAR, SEM_ESTRUTURA_AUXILIAR, SEM_ESPACO, SUCESSO };

//funcoes de menu
void Main_Menu(); 
void Menu_Ins_Num(int **mvet);
void Menu_List_Strc(int **mvet);
void Menu_List_All(int **mvet);
void Print_Hash_Line();
void Menu_Rlc_Strc(int **mvet);

//funcoes de vetor
int Mk_Aux_Vet(int **adress, int pos, int tm);
void inivet(int ***mvet);
int Ins_Num(int *arr, int num);
int List_Strc(int *aVet);
void List_All(int **mVet);
int Rlc_Strc(int **aVet);
#endif
