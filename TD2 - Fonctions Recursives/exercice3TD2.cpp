#include <stdio.h>
#include <stdlib.h>
 
void FacteursPremiersV1(int n, int i,int N,int *T){

	if (n%i != 0){
		n=n/i;
			N++;
			T=(int*)realloc(T,N * sizeof(int));
			*(T+i) = n/i;
			printf("%d",*(T+i));
			i++;
			FacteursPremiersV1(n/i,i,N,T);
	}else{
			N++;
			T=(int*)realloc(T,N * sizeof(int));
			*(T+i) = n;
			printf("%d",*(T+i));
		FacteursPremiersV1(n/i,i,N,T);
	}

	
}
bool estPremier(int n){
	for(int i=2;i<n;i++){
		if (n%i == 0) 
			return false;
	 	else 
		 	return true;
	}
	 
}

int louestprimenumber(int n){
	for (int i=2;i<=n ; i++){
		if(estPremier(i)&&(n%i)==0)
			return i;
	}
	
} 
void facteursPremiersV2(int n, int *T, int *taille){
	int t = *taille;
	if(n==1)
		return;
	T =(int *)realloc(T,++t * sizeof(int));
	*(T+t-1)=louestprimenumber(n);
	facteursPremiersV2(n/(*T+t-1),T,taille);
}


 
int main()
{
//	int *T = (int *)malloc(sizeof(int));
	int taille = 1;
	int n;
	printf("entrer nb :");
	scanf("%d",&n);
	int N=1;
	int *T=(int *)malloc (N*sizeof (int));
	FacteursPremiersV1(n, 1,1,T);
//	facteursPremiersV2(n,T, &taille);
}

