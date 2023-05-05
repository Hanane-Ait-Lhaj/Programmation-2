#include <stdio.h>
#include <stdlib.h>

int *Allouer(int taille);
void Saisir(int *T,int taille);
void Affiche(int *T,int taille);
void insereValeurs(int *T,int *taille,int ind,int N);
int SupprimeDuplications(int *T, int n);

int main(){
	int *T, taille,ind,N; 
	//N : nombre des elements qu'on va ajouter
	//ind : l'indice où on va ajouter ces elements
	
	printf(" Veuillez saisir la taille du tableau : ");
	scanf("%d",&taille);
	T=Allouer(taille);
	
	printf("\nRemplissage du tableau :\n");
	Saisir(T,taille);
	
	printf("\nAffichage des elements du tableau :");
	Affiche(T,taille);
	
	printf("\nEntrer le nombre des elements pour l'inserer dans le tableau : ");
	scanf("%d",&N);
	printf("\nEntrer l'indice : ");
	scanf("%d",&ind);
	insereValeurs(T,&taille,ind,N);
	
	printf("\nAffichage des elements du tableau :");
	Affiche(T,taille);
	
	printf("\nSuppression les éléments en multiples dans le tableau :\n");
	taille = SupprimeDuplications(T,taille);
	
	printf("\nAffichage des elements du tableau :");
	Affiche(T,taille);
	return 0;
}

int * Allouer(int taille){
	int *T = (int *) malloc(taille * sizeof(int));
	return T;
}
void Saisir(int *T,int taille){
	for(int i=0;i<taille;i++){
		printf("l'element T[%d] : ",i);
		scanf("%d",T+i);  //T[i] <==> T+i
	}
}

void Affiche(int *T,int taille){
	int i;
	for(i=0;i<taille;i++){
		printf(" T[%d]=%d |",i,*(T+i));
	}
}
void insereValeurs(int *T,int *taille,int ind,int N){
	int i,j,val; // val : valeur insere
	if(ind<0 || ind >= *taille){
	printf("insertion imposible");	
	}else{
		for(j=1;j<=N;j++){
			printf("Entrer la valeur %d :\t",j);
			scanf("%d",&val);		
			
			//modifier la taille du tab
			(*taille)++;
			T=(int *)realloc(T,(*taille)*sizeof(int));

			//ecraser les elements
			for(i=(*taille)-1;i>=ind-1;i--){
				*(T+i+1)=*(T+i); //<==>T[i+1]=T[i]
			}
			
			*(T+ind)=val; //stocker la val dans T[ind]
		}
		
	}
	
}
int SupprimeDuplications(int *T, int taille){
	
 	for( int i = 0; i < taille-1; i++){
 		for (int j=1; j < taille; j++){
 		
		 	if (*(T+i) == *(T+j)){
    			for (int K=j ;K < taille-1 ; K++) {  //ecraser les elements
					*(T+K)=*(T+K+1);
    			}
    			taille--; //decrementer la taille chaque fois il y a des elements double
				T = (int *) realloc (T, taille * sizeof (int));
			 }
			  
		}
	}
	return taille;
}















//void SupprimeDup(int n , int **T){
//	int k = 0,j;
//	for (int i=0 ; i<n ;i++){
//		for (j=0;j<i;j++){
//			if (*(T[i])== *(T)[j])
//				break;
//		}
//		if (i==j)
//			*(T)[k++]= *(T)[i];
//    }
//	*T =(int *)realloc (*T, sizeof (int)*k);
//}




