#include <stdlib.h>
#include <stdio.h>

int * Allouer(int taille){
	int *T = (int *) malloc(taille * sizeof(int));
	return T;
}

void remplir(int *T,int *taille,int bit){
//			(*taille)++;
//			T=(int *)realloc(T,(*taille)*sizeof(int));
			*(T+(*taille)-1) = bit;
}
void saisie (int *n,int *b)
{
	printf("donner un entier\n");
	scanf("%d",n);
	do{
		printf("donner une base\n");
		scanf("%d",b);
	}while(*b<2||*b>10);
}
void convertir(int n, int b,){
	if (n/b == 0){
		remplir(T,&taille,n%b);
		
	}else{
		convertir(n/b,b,T,taille);
		remplir(T,&taille,n%b);
	}
}

void Affichage(int *T , int taille){
	int i;
	for(i=0;i<taille; i++){
		printf("T[%d]=%d|",i,*(T+i));	
	}
}
int main(){
	int n,b,taille=8;
	saisie(&n,&b);
	int *T = convertir(n,b,T,taille);
	
	printf("\nla convertion de %d en %d est : \t",n,b);
	Affichage(T,taille);
return 0;
}
