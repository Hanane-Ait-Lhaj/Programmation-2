#include <stdio.h>
#include <stdlib.h>

//pas repeter un chiffre donnee : ex2

int ** Allouer(int n){
	int **T =(int **)malloc (n*sizeof (int *));
	for (int i=0 ; i<n; i++)
		*(T+i)=(int *) malloc (n*sizeof (int ));
	return T;
}

void saisirM(int **T ,int L){
	int i,j;
	for (i=0;i<L;i++){
	  for(j=0;j<L;j++){
	  	scanf ("%d",*(T+i)+j);
	  }	
	}
}

void AfficherMatrice(int **T,int L){
	for(int i=0;i<L;i++){
		for(int j=0;j<L;j++){
			printf("T[%d][%d]=%d",i,j,*(*(T+i)+j));
			printf("\n");
		}
	}
}
int carreeMagique (int ** T,int L){
	int sum =0,sumdiag1=0,sumdiag2=0;
	for(int i=0;i<L;i++)
		sum+=*(*T+0)+i;
	for(int i=0;i<L;i++){
		int sum_col=0;
		int sum_ligne=0;
		for (int j=0;j<L;j++){
   			sum_ligne += *(*(T+i)+j);
   			sum_col += *(*(T+j)+i);
		}
    	if (sum_ligne != sum || sum_col!= sum)
    		return 0;   //not magic
	}
  	for (int i=0;i<L ;i++){
  		for (int j=0;j<L;j++){
	  		if (i == j)
	  			sumdiag1 += *(*(T+i)+j);}
  	}  
    if (sumdiag1 != sum)
    	return 0;
    return 1; //magic
}
int main(){
	int **T, taille;
	
	printf(" Veuillez saisir la taille du matrice : ");
	scanf("%d",&taille);
	T=Allouer(taille);
	return 0;
}

