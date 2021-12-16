#include<stdio.h>
//inverter numeros recursivamente
void rvrs_num(int num, int *inum){
	if(num<10){
		*inum+=num;
		return;
	}
	*inum+=num%10;	
	*inum*=10;
	rvrs_num(num/10, inum);
}

int main(void){
	int num, inum=0;
	//alterar aqui o valor a ser invertido
	num=3921;
	rvrs_num(num, &inum);

	printf("%d\n", inum);

}
