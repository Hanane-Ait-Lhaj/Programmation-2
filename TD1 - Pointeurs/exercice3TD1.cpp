#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int ** AllouerMatrice (int n){
    
    int **T =(int **) malloc (n * sizeof (int*));	
    for(int i=0;i<n;i++){
    	int N=i+1;
    	*(T+i)= (int*) malloc (N * sizeof (int));
	}
	return T;
}
int ** Remplir (int **P, int n){
	
	for (int i=0;i<n;i++){
		for (int j=0;j<=i;j++){
			if (j==0 || j==i){
				*(*(P+i)+j)=1;
			}else{
				*(*(P+i)+j)= *(*(P+i-1)+j) + *(*(P+i-1)+(j-1));	
			}
		}
	}
	return P;
}


void AfficherMatrice (int **M , int n){
	int i,j;
	printf("\n");
	for(i=0;i<n; i++){
		//triangle isocèle
		for(int esp=1;esp<=n-i;esp++){
			printf("  ");
		} 
		//
		for (j=0;j<=i;j++){
		
			printf("%3d ",*(*(M+i)+j));
		}
		
		printf ("\n");
	}
}

int main() {
	int **M,n;
	
	printf("donner la taille du matrice : ");
	scanf("%d",&n);
	
	M = AllouerMatrice(n);
	printf("la matrice apres le remplissage :");
	M = Remplir(M, n);
	
	printf("\nAffichage du matrice:");
	AfficherMatrice(M,n);
	return 0;
}
