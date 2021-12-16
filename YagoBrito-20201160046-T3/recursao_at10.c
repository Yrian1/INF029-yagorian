#include<stdio.h>
//ocorrencias de um numero em outro recursivamente
void srch_num(int k, int n, int *rslt, int val){
	if(n==0 || k==0) return;
	if(n%10==k%10){
		if(k/10!=0){
			srch_num(k/10, n/10, rslt, 1);
		}
		else{
			*rslt+=1;
		}
	}
		if(val) return;

	srch_num(k, n/10, rslt, 0);

}

int main(void){
	int k, n, rslt=0;
	//variaveis a se alterar
	k=62;
	n=67620292;
	srch_num(k, n, &rslt, 0);

	printf("%d\n", rslt);
}
