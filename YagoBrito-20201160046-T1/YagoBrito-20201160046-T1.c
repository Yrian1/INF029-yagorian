// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome:
//  email:
//  Matrícula:
//  Semestre:

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016

// #################################################

#include <stdio.h>
#include "YagoBrito-20201160046-T1.h" // Substitua pelo seu arquivo de header renomeado
#include <stdlib.h>
#include <string.h>
/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)   
    pode utilizar strlen para pegar o tamanho da string
 */
typedef struct INT_DATA{
	int dia, mes, ano;
}dat_int;

dat_int qbr_cnv_data(char* data){
	dat_int rdate;
	int md=1, td=strlen(data)-1, j, vd[3]={0};
	for(j = 0; j < 3; j++){
		for(;td>=0;td--){
			if(data[td]=='/'){
				md=1;
				td--;
				break;
			}
			vd[j]+=(data[td]-48)*md;
			md*=10;
		}
	}
	rdate.dia=vd[2];
	rdate.mes=vd[1];
	rdate.ano=vd[0];
	return rdate;
}
int Test_Dat(dat_int *ndata){
    	if(ndata->dia<1 || ndata->dia > 31 || ndata->mes < 1 || ndata->mes > 12)
		return 0;
	if((ndata->mes==2 && ndata->dia==29) && ((ndata->ano%4!=0 || ndata->ano%100==0)  && ndata->ano%400!=0))
		return 0;
	else if(ndata->dia ==31 && ((ndata->mes<=7 && ndata->mes%2==0) || ndata->mes%2!=0))
		return 0;

	return 1;
	  }
int q1(char *data)
{
	dat_int ndata=qbr_cnv_data(data);
    int datavalida = 1;
    datavalida=Test_Dat(&ndata);

	if (datavalida)
		return 1;
	else
		return 0;
}

/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. Além disso, a função tem três parâmetros qtdDias, qtdMeses e qtdAnos. Esses três parâmetros devem ser utilizados para guardar os resultados dos cálculos. Na chamada da função deve passar o valor -1 para os três
 @saida
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
 */
int q2(char *datainicial, char *datafinal, int *qtdDias, int *qtdMeses, int *qtdAnos)
{

	dat_int inidat, findat;

	inidat = qbr_cnv_data(datainicial);

	findat = qbr_cnv_data(datafinal);

	int nDias, nAnos, nMeses;

	if(Test_Dat(&inidat)==0){
		return 2;
	}
	if(Test_Dat(&findat)==0){
		return 3;
	}
	if(inidat.ano > findat.ano){
		return 4;
	}	
		else if(inidat.ano==findat.ano){
			if(inidat.mes>findat.mes){
				return 4;
			}
				else if(inidat.mes==findat.mes){
					if(inidat.dia>findat.dia){
						return 4;
					}
			}
		}
	nDias=findat.dia-inidat.dia;
	nMeses=findat.mes-inidat.mes;
	nAnos=findat.ano-inidat.ano;

	if(nDias<0){
		nMeses-=1;
		if(findat.mes==3){
			if(((findat.ano%4==0 && findat.ano%100!=0)  || findat.ano%400==0)){
				nDias+=29;
			}
			else{
				nDias+=28;
			}
		}
		else if((inidat.mes<=7 && inidat.mes%2!=0) || (inidat.mes>7 &&inidat.mes%2==0)){

			nDias+=30;
		}
		else{
			nDias+=31;
		}
	}
	
	if(nMeses<0){
		nAnos-=1;
		nMeses+=12;
	}
		
    *qtdDias = nDias;
    *qtdAnos = nAnos;
    *qtdMeses = nMeses;

    //coloque o retorno correto
    return 1;
}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive)
{
    int qtdOcorrencias = 0, ICS = 32;
	if((!isCaseSensitive) && c>=97)
		c-=ICS;
	for(int i = 0; texto[i] != '\0'; i++){
		if(texto[i]>=97 && !(isCaseSensitive))
			texto[i]-=ICS;
		if(c==texto[i])
				qtdOcorrencias++;
	}
    return qtdOcorrencias;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;

 */
int q4(char *strTexto, char *strBusca, int posicoes[30])
{
    int qtdOcorrencias = 0, tb=0, v=0, p=0;
	tb=strlen(strBusca)-1;

	for(int i =0; strTexto[i+tb]!='\0'; i++){
		if(strBusca[v]!=strTexto[i]){
			v=0;
			continue;
		}
			if(v==tb){
				posicoes[p]=i-v+1;
				posicoes[p+1]=i+1;
				p+=2;
				qtdOcorrencias++;
				v=0;
				continue;
			}
		v++;
		}
	
    return qtdOcorrencias;
}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num)
{

	int mun=0, dm=10;
	while(num!=0){
		mun+=num%dm;
		mun*=dm;
		num/=dm;
	}
	mun/=dm;
	num=mun;
    return num;
}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca)
{
    int qtdOcorrencias=0, tb=10;
    for(; numerobusca/tb>0; tb*=10);
    
    while(numerobase>=numerobusca){
	if(numerobase%tb==numerobusca){
		qtdOcorrencias++;
	}
	numerobase/=10;
    }
    return qtdOcorrencias;
}
