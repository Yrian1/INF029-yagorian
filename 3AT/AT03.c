#include<stdio.h>
#include"baskh.h"
//Projeto usando multiplos arquivos em C
int main(void){
int a, b ,c;
int find=0, guess=0, hint, try;
a = b = c = 0;

puts("insira 3 numeros\n");
scanf("%d %d %d", &a, &b, &c);
guess=SOLVE(a, b, c);
puts(" Agora iremos comecar um jogo de advinhacao\n Siga inserindo numeros ate acertar;\n voce ira receber dicas");
do{
	scanf("%d", &try);
	hint=try-guess;
	if (hint==0){
		puts("parabens! voce acertou");
		find=1;
	}
	else{
		if(hint<0){
			hint*=-1;
		}

		if(hint==1){
			puts("Muito quente!");
			}
			else if(hint==2 || hint==3){
				puts("Quente");
			}
				else if(hint==4 || hint==5){
					puts("morno");
				}
					else if(hint>4 && hint<=8){
						puts("morninho");
					}
						else if(hint>8){
							puts("Para o outro lado");
						}
	}
}while(find==0);
}
