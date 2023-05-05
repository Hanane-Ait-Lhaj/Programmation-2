#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Salaire{
	double base;
	double nbHeurs;
}Salaire;

typedef struct Date{
	int jour;
	int mois;
	int annee;
}Date;

typedef struct Employe {
	char Nom[20];
	char Prenom[20];
	Salaire salaire;
	char departement[10];
	Date date;
}Emp;


Employe * Saisir(Emp *T, int N){
	T=(Emp *)malloc (N*sizeof(Emp));
	Emp E;
	for(int i=0;i<N;i++){
		printf("Employe N:%d\n",i+1);
		printf("entrer nom :");
		scanf("%s",&E.Nom);
		printf("entrer prenom :");
		scanf("%s",&E.Prenom);		
		printf("entrer dep :");
		scanf("%s",&E.departement);	
		printf("entrer la base salaire :");
		scanf("%lf",&E.salaire.base);
		printf("entrer nombre des heures :");
		scanf("%lf",&E.salaire.nbHeurs);
		printf("entrer date de recrutement (DD MM YYYY) : ");
		scanf("%d %d %d",&E.date.jour,&E.date.mois,&E.date.annee);
		T[i] = E;
	}
	return T;	
}

void InfoEmploye(Emp *T,int N){
	for(int i=0;i<N;i++){
		printf("\nEmploye %d",i+1);
		printf("\n nom : ");
		printf("%s",T[i].Nom);
		printf("\n prenom :");
		printf("%s",T[i].Prenom);		
		printf("\n dep :");
		printf("%s",T[i].departement);
		printf("\n la salaire :");
		double sal = T[i].salaire.base * T[i].salaire.nbHeurs;
		printf("%.2f",sal);
		printf("\n date de recrutement:  ");
		printf("%d-%d-%d",T[i].date.jour,T[i].date.mois,T[i].date.annee);	
	}
}

void salaire (Emp *T,int N){
	int somme;
	for (int i=0;i<N;i++){
		somme += T[i].salaire.base * T[i].salaire.nbHeurs ;
	}
	int Moyenne = somme / N;
	int salaire;
	for (int i=0;i<N;i++){
	  salaire =  T[i].salaire.base * T[i].salaire.nbHeurs ;
	  if (salaire > Moyenne){
	  	printf("\nEmploye %d",i+1);
		printf("\nnom : ");
		puts(T[i].Nom);
		printf("prenom :");
		puts(T[i].Prenom);	
		printf(" dep :");
		printf("%s",T[i].departement);
		printf("\n la salaire :");
		double sal = T[i].salaire.base * T[i].salaire.nbHeurs;
		printf("%.2f",sal);
		printf("\ndate de recrutement : ");
		printf("%d-%d-%d \n",T[i].date.jour,T[i].date.mois,T[i].date.annee);
	  }
	}
}

void RechercheEmp (Emp *T,int N,char depart[10]){
	int trouv=0;
	for (int i=0;i<N;i++){
	  if (strcmp(T[i].departement,depart)==0){
	  		printf("\nEmploye %d :",i+1);
			printf("\n nom : ");
			puts(T[i].Nom);
			printf(" prenom :");
			puts(T[i].Prenom);	
			trouv++;	
		}
	}
	if(trouv==0){
		
		printf("Employe introuvable");
	}
	printf("---------------------------------");
}

void date_de_recrutement(Emp* employes, int n) {
    int i, j;
    Emp temp;

    for (i = 1; i < n; i++) {
        temp = employes[i];
        j = i - 1;
        while (j >= 0 && (employes[j].date.annee > temp.date.annee || 
			(employes[j].date.annee == temp.date.annee && 
				(employes[j].date.mois > temp.date.mois ||
				(employes[j].date.mois == temp.date.mois &&
                  (employes[j].date.jour > temp.date.jour)))))){
            employes[j + 1] = employes[j];
            j--;
        }
        employes[j + 1] = temp;
    }
}



int main (){
	int N;
	printf("--------------------------------------------");
	printf("\n------------Saisir les employes :-------\n");
	printf("\nEntrez le nombre des employes:");
	scanf("%d",&N);
	printf("\n-------------------------------------------\n");
	Emp *T;
	printf("\n Saisir les informations des employes: \n");
	T= Saisir(T,N);
	InfoEmploye(T, N);
	printf("\n------------------------------------------------------\n");
	printf("\n \n Les employes dont le salaire est supperieur a la moyenne :");
	salaire(T,N);
	printf("\n -------------------------------------------------------");
	char dep[10];
	printf("\nDonnez le departement :");
	scanf("%s",&dep);
	printf("\n La liste des employes est:\n");
	RechercheEmp (T, N, dep);
	printf("\n ---------------------------------------------------------");
	printf("\n La date d'Anciennete :\n");
	date_de_recrutement(T,N);
	  // Affiche la liste triée d'employés
    for (int i = 0; i < N; i++) {
        printf("%s %s - Date de recrutement : %d/%d/%d\n", T[i].Prenom, T[i].Nom, T[i].date.jour,
               T[i].date.mois, T[i].date.annee);
    }
    return 0;
	
}
