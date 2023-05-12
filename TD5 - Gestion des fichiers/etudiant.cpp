#include <stdlib.h>
#include <stdio.h>

struct Etudiant{
	int Num;
	char Nom[100];
	char Prenom[100];
	char Filiere[50];
};
struct Etudiant Etud;
        // fonction de recherche
int rech(int Numrech){
	FILE *F;
	F=fopen("Etudiants.txt","r");
	do{
		fscanf(F,"%d ;%s ;%s ;%s \n",&Etud.Num,&Etud.Nom,&Etud.Prenom,&Etud.Filiere);
		fflush(stdin);
		if (Etud.Num == Numrech){
	 		fclose(F);
    		return 1;
    	}
	}while(!feof(F));
	fclose(F);
 	return -1;
}
          ///......procédure d'ajout....//
void AjouterEtudiant(){
	FILE *F;
	int num;
	F=fopen("Etudiants.txt","a");
	printf("\n Entre le numero du nouveau étudiant :");
	scanf("%d",&num);
	fflush(stdin);
	while (rech(num) == 1){
		printf("\n Ce numero existe deja :");
		printf("\nEntrer le numero d'etudiant");
		scanf("%d",&num);
	}
	Etud.Num=num;
	printf("\n Entrer le Nom :");
	gets(Etud.Nom);
	fflush (stdin);
	printf("\n Entrer le Prenom :");
	gets(Etud.Prenom);
	fflush (stdin);
	printf("\n Entrer la filiere : ");
	gets(Etud.Filiere);
	fflush(stdin);
	fprintf(F,"%d ;%s ;%s ;%s \n",Etud.Num,Etud.Nom,Etud.Prenom, Etud.Filiere);
	//fflush(stdin);
	fclose(F);
}

//rechercher////

void Recherche(){
	int NumR;
	printf("Entrer le numero d'etudiant a rechercher\n");
	scanf("%d", &NumR);
	FILE *F;
	F = fopen("Etudiants.txt", "r");
	do{
		fscanf(F,"%d ;%s ;%s ;%s \n",&Etud.Num,&Etud.Nom,&Etud.Prenom,&Etud.Filiere);
		if(NumR == Etud.Num){
			printf("------ Information Sur l' etudiant : ------- \n\n");
			printf("Numero\t: %d \n", Etud.Num);
			printf("Nom :\t%s\n", Etud.Nom);
			printf("Prenom:\t %s\n ",Etud.Prenom);
			printf("Filiere:\t%s \n ",Etud.Filiere);
		}
	}while(!feof(F));
	fclose(F);
}

/// procedure de suppression---///
void SupprimerEtudiant(){
	char rep;
	int NumRech;
	printf("Entrez Le numero d'etudiant a supprimer :");
	scanf("%d",&NumRech);
	fflush(stdin);
	if (rech(NumRech)== 1){
		printf("\n Voulez Vous Vraimment Supprimer o/n ?");
		scanf("%c",&rep);
		fflush(stdin);
		if (rep == 'o' || rep == 'O' ){
			FILE *Fich,*F;
			F=fopen("Etudiants.txt","r");
			Fich = fopen("TempEtudiant.txt", "a");
			do{
				fscanf(F,"%d ;%s ;%s ;%s \n",&Etud.Num,&Etud.Nom,&Etud.Prenom,&Etud.Filiere);
				if(NumRech != Etud.Num){
					fprintf(Fich,"%d ;%s ;%s ;%s \n",Etud.Num,Etud.Nom,Etud.Prenom,Etud.Filiere);
				}
			}while(!feof(F));
			fclose(Fich);
			fclose(F);
			remove("Etudiants.txt");
			rename("TempEtudiant.txt", "Etudiants.txt");
			printf("Suppression Effectuee ave succees");
		}
	}else{
		printf("\n Cet etudient n'existe pas");
	}
}
void ModifierEtudiant(){
	FILE *F,*Fich; 
	int num, i;
	char rep='n';
	printf("\n Entre le numéro de l'etudiant a Modifier : ");
	scanf("%d", &num);
	fflush(stdin);
	if (rech(num) == 1){
		printf("\n Voulez Vous Vraimment Modifier o/n ?");
		scanf("%c",&rep);
		fflush(stdin);
		printf ("%c",rep);
		if(rep == 'o' || rep == 'O'){
			F=fopen("Etudiants.txt","r");
			Fich=fopen("TempEtudiants.txt","a");
			do{
				fscanf(F,"%d ;%s ;%s ;%s \n",&Etud.Num,&Etud.Nom,&Etud.Prenom,&Etud.Filiere);
				if(num==Etud.Num){
					Etud.Num =num;
					printf("\n Entre le Nouveau Nom : ");
					gets(Etud.Nom);
					printf("\n Entre le Nouveau prenom : ");
					gets(Etud.Prenom); 
					printf("Entre la nouvelle filiere : ");
					gets(Etud.Filiere);
					printf("\n la modification a Reussi");
				}
				fprintf(Fich,"%d ;%s ;%s ;%s \n",Etud.Num,Etud.Nom,Etud.Prenom,Etud. Filiere);

			}while (!feof(F));
			fclose(F);
			fclose(Fich);
			remove("Etudiants.txt");
			rename("TempEtudiants.txt" ,"Etudiants.txt");
			printf("\n la modification a Reussi");
		}else{
			printf(" \n la modification a ete annule \n");
		}
	}else{
		printf("le num n'existe pas");
	}
}
void AfficherEtudiants(){
	FILE*F;
	F=fopen("Etudiants.txt","r");
	printf("La liste des etudiants est : \n \n");
	printf("Numero\t Nom \t Prenom\t Filiere\n");
	do{
		fscanf(F,"%d ;%s ;%s ;%s \n",&Etud.Num,&Etud.Nom,&Etud.Prenom, &Etud. Filiere);
		fflush(stdin);
		printf("%d\t", Etud.Num);
		printf("%s\t", Etud.Nom);
		printf(" %s\t ",Etud.Prenom);
		printf("%s\n", Etud.Filiere);
	}while (!feof(F));

	fclose(F);
}

int main(){
	int Choix ; 
	char rep;
	do{
		system("cls");
		printf(" menu\n");
		printf("1- Ajouter Un Etudiant \n");
		printf("2- Rechercher Un Etudiant \n");
		printf("3- Supprimer Un Etudiant ");
		printf("4- Modifier Un Etudiant \n");
		printf("5- Afficher tous les Etudiants \n ");
		printf("6- Quitter \n \n");
		do{
			printf(" \n -Entre Votre Choix : ");
			scanf("%d", &Choix);
		}while(Choix<1 || Choix>6);
		switch (Choix){
			case 1:
				AjouterEtudiant();
			break;
			case 2:
				Recherche();
			break;
			case 3:
				SupprimerEtudiant();
			break;
			case 4:
				ModifierEtudiant();
			break;
			case 5:
				AfficherEtudiants();
			break;
			case 6: break;
 		}
		printf(" \n Voulez-vous continuez O/N: ");
		scanf("%s", &rep);
		fflush(stdin);
	}while(rep=='o'||rep=='O');
	
	return 0;
}
