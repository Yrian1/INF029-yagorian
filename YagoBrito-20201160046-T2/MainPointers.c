#include<stdio.h>
#include<stdlib.h>
#include"Lib_Pointers.h"

int main(void){
	int **mvet;
	int opt, rtrn, tm, pos;
	inivet(&mvet);
	do{
		Main_Menu();
		scanf("%d", &opt);
		switch(opt){
			case 1:
				Menu_Ins_Num(mvet);
				//printf("%d\n", mvet[0][0]);
				break;
			case 2:
				Menu_List_Strc(mvet);
				break;
			case 3:
				Menu_List_All(mvet);
				break;
			case 4:
				Menu_Rlc_Strc(mvet);
				break;
			default:
				return 0;
			break;

		}
	}while(opt);
}
