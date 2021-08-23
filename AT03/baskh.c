#include<math.h>
#include<stdio.h>
#include"baskh.h"


int SOLVE(int a, int b, int c){
int guess, delt;
float r1, r2;

delt=b*b-4*a*c;
	if(delt>=0){
		r1=(-b+sqrt(delt))/2*a;
		r2=(-b-sqrt(delt))/2*a;
		}
		else {
			r1=(-b+(delt*delt))/2*a;
			r2=(-b-(delt*delt))/2*a;
			}
guess=ceil(r1+r2);
	if (guess<0){
		guess*=-1;
	}
return guess;
}
