#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int EstParfait (int n,int i,int somme){
	if (i==n)
	return (somme);
	if ((n%i)==0)
	return EstParfait(n,i+1,somme+i);
	else
	return EstParfait (n,i+1,somme);
}

int Parfait (int n,int i){
	if (i==1){
		return 1;
	}else if (n%i ==0){
		return(i+Parfait(n,i-1));
	}else{
		return Parfait(n,i-1);
	}

}

void Allouer(int n){
	int N=1,*T;
	int i,j=0;
	T=(int*)malloc (N*sizeof(int));
	for(i=2;i<=n;i++){
		if(Parfait(i,i/2)==i){
			N++;
			T=(int *)realloc(T,N*sizeof(int));
			*(T+j)=i;
			printf("%d\t",*(T+j));
			j++;
		}
	}
}

int main() {
	int n,i;
	printf("enter le nombre entier : ");
	scanf("%d",&n);
	Allouer(n);
	printf("enter i: ");
	scanf("%d",&i);
	printf("parfait : ");
	printf("%d",Parfait(n,i));
	return 0;
}
