#include <stdlib.h>
#include <stdio.h>

struct Employe{ 
	int Num;
	char Nom[100];
	char Prenom[100];
	char DateAnc[50];
	char Departement[50];
	double base;
	double nbHeures;
};
struct Employe Emp;
        // fonction de recherche
int existeEmp(int Numrech){
	FILE *F;
	F=fopen("Employes.txt","r");
	do{
		fscanf(F,"%d ;%s ;%s ;%s ;%s ;%lf ;%lf \n",&Emp.Num,&Emp.Nom,&Emp.Prenom,&Emp.DateAnc,&Emp.Departement,&Emp.base,&Emp.nbHeures);
		fflush(stdin);
		if (Emp.Num == Numrech){
	 		fclose(F);
    		return 1; //1
    	}
	}while(!feof(F));
	fclose(F);
 	return -1; //-1
}
          ///......procédure d'ajout....//
void AjouterEmploye(){
	FILE *F;
	int num;
	F=fopen("Employes.txt","a");
	printf("\n Entre le numero du nouveau employe :");
	scanf("%d",&num);
	fflush(stdin);
	while (existeEmp(num) == 1){
		printf("\n Ce numero existe deja :");
		printf("\nEntrer le numero d'employe");
		scanf("%d",&num);
	}
	Emp.Num=num;
	printf("\n Entrer le Nom :");
	gets(Emp.Nom);
	fflush (stdin);
	printf("\n Entrer le Prenom :");
	gets(Emp.Prenom);
	fflush (stdin);
	printf("\n Entrer la date d'anciennete : ");
	gets(Emp.DateAnc);
	fflush (stdin);
	printf("\n Entrer la departement : ");
	gets(Emp.Departement);
	fflush (stdin);
	printf("\n Entrer la base : ");
	scanf("%lf",&Emp.base);
	fflush (stdin);
	printf("\n Entrer le nbr d'heures : ");
	scanf("%lf",&Emp.nbHeures);
	fflush(stdin);
	fprintf(F,"%d ;%s ;%s ;%s ;%s ;%lf ;%lf \n",Emp.Num,Emp.Nom,Emp.Prenom,Emp.DateAnc,Emp.Departement,Emp.base,Emp.nbHeures);
	//fflush(stdin);
	fclose(F);
}

//rechercher////

void Recherche(){
	int NumR,trouv=0;
	printf("Entrer le numero d'employe a rechercher\n");
	scanf("%d", &NumR);
	FILE *F;
	F = fopen("Employes.txt", "r");
	do{
		fscanf(F,"%d ;%s ;%s ;%s ;%s ;%lf ;%lf \n",&Emp.Num,&Emp.Nom,&Emp.Prenom,&Emp.DateAnc,&Emp.Departement,&Emp.base,&Emp.nbHeures);
		if(NumR == Emp.Num){
			printf("------ Information Sur l' employe : ------- \n\n");
			printf("Numero\t: %d \n", Emp.Num);
			printf("Nom :\t%s\n", Emp.Nom);
			printf("Prenom:\t %s\n ",Emp.Prenom);
			printf("DateAnciennete:\t%s \n ",Emp.DateAnc);
			printf("Salaire:\t%lf \n ",Emp.base*Emp.nbHeures);
			trouv++;
		}
	}while(!feof(F));
	fclose(F);
	if(trouv==0) printf("introuvable");
	
}

/// procedure de suppression---///
void SupprimerEmploye(){
	char rep;
	int NumRech;
	printf("Entrez Le numero d'employe a supprimer :");
	scanf("%d",&NumRech);
	fflush(stdin);
	if (existeEmp(NumRech)== 1){
		printf("\n Voulez Vous Vraimment Supprimer o/n ?");
		scanf(" %c",&rep);
		fflush(stdin);
		if (rep == 'o' || rep == 'O' ){
			FILE *Fich, *F;
			F=fopen("Employes.txt","r");
			Fich = fopen("TempEmploye.txt", "a");
			do{
				fscanf(F,"%d ;%s ;%s ;%s ;%s ;%lf ;%lf \n",&Emp.Num,&Emp.Nom,&Emp.Prenom,&Emp.DateAnc,&Emp.Departement,&Emp.base,&Emp.nbHeures);
				if(NumRech != Emp.Num){
					fprintf(Fich,"%d ;%s ;%s ;%s ;%s ;%lf ;%lf \n",Emp.Num,Emp.Nom,Emp.Prenom,Emp.DateAnc,Emp.Departement,Emp.base,Emp.nbHeures);
				}
			}while(!feof(F));
			fclose(Fich);
			fclose(F);
			remove("Employes.txt");
			rename("TempEmploye.txt", "Employes.txt");
			printf("Suppression Effectuee ave succees");
			fflush (stdin);
		}
	}else{
		printf("\n Cet employe n'existe pas");
	}
}
void ModifierNbrHeures(){
	FILE *F,*Fich; 
	int num, i;
	char rep='n';
	printf("\n Entre le numéro de l'employe a Modifier : ");
	scanf("%d", &num);
	fflush(stdin);
	if (existeEmp(num) == 1){
		printf("\n Voulez Vous Vraimment Modifier o/n ?");
		scanf("%c",&rep);
		fflush(stdin);
		printf ("%c",rep);
		if(rep == 'o' || rep == 'O'){
			F=fopen("Employes.txt","r");
			Fich=fopen("TempEmployes.txt","a");
			do{
				fscanf(F,"%d ;%s ;%s ;%s ;%s ;%lf ;%lf \n",&Emp.Num,&Emp.Nom,&Emp.Prenom,&Emp.DateAnc,&Emp.Departement,&Emp.base,&Emp.nbHeures);
				if(num==Emp.Num){
					Emp.Num =num;
//					printf("\n Entre le Nouveau Nom : ");
//					gets(Emp.Nom);
//					printf("\n Entre le Nouveau prenom : ");
//					gets(Emp.Prenom); 
//					printf("Entre la nouvelle date d'anciennete : ");
//					gets(Emp.DateAnc);
//					printf("\n Entrer la departement : ");
//					gets(Emp.Departement);
//					printf("\n Entrer la base : ");
//					scanf("%lf",&Emp.base);
					printf("\n Entrer le nouveau nbr d'heures : ");
					scanf("%lf",&Emp.nbHeures);
					printf("\n la modification a Reussi");
				}
				fprintf(Fich,"%d ;%s ;%s ;%s ;%s ;%lf ;%lf \n",Emp.Num,Emp.Nom,Emp.Prenom,Emp.DateAnc,Emp.Departement,Emp.base,Emp.nbHeures);

			}while (!feof(F));
			fclose(F);
			fclose(Fich);
			remove("Employes.txt");
			rename("TempEmployes.txt" ,"Employes.txt");
			printf("\n la modification a Reussi");
		}else{
			printf(" \n la modification a ete annule \n");
		}
	}else{
		printf("le num n'existe pas");
	}
}
void AfficherEmployes(){
	FILE*F;
	F=fopen("Employes.txt","r");
	printf("La liste des employes est : \n \n");
	printf("Numero\t Nom\t Prenom\t DateAnc Depart\t Salaire\n");
	do{
		fscanf(F,"%d ;%s ;%s ;%s ;%s ;%lf ;%lf \n",&Emp.Num,&Emp.Nom,&Emp.Prenom,&Emp.DateAnc,&Emp.Departement,&Emp.base,&Emp.nbHeures);
		fflush(stdin);
		printf("%d\t ", Emp.Num);
		printf("%s\t ", Emp.Nom);
		printf("%s\t ",Emp.Prenom);
		printf("%s\t ", Emp.DateAnc);
		printf("%s\t ", Emp.Departement);
		printf("%lf\n", Emp.base*Emp.nbHeures);
	}while (!feof(F));

	fclose(F);
}

int main(){
	int Choix ; 
	char rep;
	do{
		system("cls");
		printf("---------------menu----------------\n");
		printf("1- Ajouter Un Employe \n");
		printf("2- Rechercher Un Employe \n");
		printf("3- Supprimer Un Employe \n");
		printf("4- Modifier nbr heures Employe \n");
		printf("5- Afficher tous les Employes \n");
		printf("6- Quitter \n \n");
		do{
			printf(" \n -Entre Votre Choix : ");
			scanf("%d", &Choix);
		}while(Choix<1 || Choix>6);
		switch (Choix){
			case 1:
				AjouterEmploye();
			break;
			case 2:
				Recherche();
			break;
			case 3:
				SupprimerEmploye();
			break;
			case 4:
				ModifierNbrHeures();
			break;
			case 5:
				AfficherEmployes();
			break;
			case 6: 
				exit(1);
			break;
	
 		}
		printf(" \n Voulez-vous continuez O/N: ");
		scanf("%s", &rep);
		fflush(stdin);
	}while(rep=='o'||rep=='O');
}
