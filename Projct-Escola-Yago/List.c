#include<stdio.h>
#include<stdlib.h>

void Print_Txt(char* file){
	char ch;
	FILE* FF;

	FF=fopen(file, "r");

	if(FF!=NULL){
		while(!feof(FF)){
			ch=fgetc(FF);
			printf("%c", ch);
				}
	}
	else{
	puts("problemas tecnicos");
	}

	fclose(FF);
	return;
}
