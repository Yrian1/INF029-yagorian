#include<stdio.h>
//fatorial recursivo
long long dofat(int fat){
	if(fat<=0) return 1;
	return fat*dofat(fat-1);
}
int main(void){
	long long fat;
	fat=9;
	fat=dofat(fat);
	printf("%lld\n", fat);
}
