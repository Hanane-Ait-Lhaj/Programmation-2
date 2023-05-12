#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

void Ecrire_Sequence(char fileName[255],int N){
	FILE *fp;
	fp = fopen(fileName,"w+");
	int nb=0;

	srand(time(NULL));
	if(fp!=NULL){
		for(int i=0; i<N; i++){

			nb = rand() % 4;
			switch(nb){
				case 0:
					fputc('A',fp);//fprintf(fp,"%c",'A');
					break;
				case 1:
					fputc('T',fp);
					break;
				case 2:
					fputc('G',fp);
					break;
				case 3:
					fputc('C',fp);
					break;
			}
		}
		fclose(fp);
	}

	fp=fopen(fileName,"r");
	if(fp!=NULL){
		char c;
		printf("\nADN dans le fichier %s est :\n",fileName);
		while((c=fgetc(fp))!=EOF){
			printf("%c",c);

		}
		printf("\n");
		fclose(fp);
	}
}
void CompteNucleotides(char fileName[]){
	FILE *fp = fopen(fileName,"r");
	int nbA=0,nbT=0,nbG=0,nbC=0;
	char ADN;
	if(fp!=NULL){

		while(!feof(fp)){
			ADN=fgetc(fp); //fscanf(fp,"%c",ADN);
			if(ADN=='A') nbA++;
			if(ADN=='T') nbT++;
			if(ADN=='G') nbG++;
			if(ADN=='C') nbC++;
		}
		fclose(fp);
	}

	printf("\nnbA = %d", nbA);
	printf("\nnbT = %d", nbT);
	printf("\nnbG = %d", nbG);
	printf("\nnbC = %d", nbC);

}
char* BrinCompInv(char fileName[],int N){ //inverser ADN et A-T C-G entre eux
	FILE *fp = fopen(fileName,"r");
	char *invADN;
	if(fp!=NULL){
		int i=0;
		while(!feof(fp)){
			invADN[N-i-1]=fgetc(fp); //fscanf(fp,"%c",ADN);
			i++;
		}
		fclose(fp);
	}

	for(int i=0;i<N;i++){
		switch(invADN[i]){
			case 'A':
				invADN[i]='T';
			break;
			case 'T':
				invADN[i]='A';
			break;
			case 'G':
				invADN[i]='C';
			break;
			case 'C':
				invADN[i]='G';
			break;
		}
	}
	return invADN;
}
void Nbrepetitions(char fileName[],int N,char c){ //A=AAA ; T=TTT; C=CCCC; G=GGGG
	char ADN[N];
	FILE *fp = fopen(fileName,"r");
	int j=0;
	if(fp!=NULL){
		while(!feof(fp)){
			ADN[j]=fgetc(fp);
			j++;
		}
		fclose(fp);
	}
	
	int nbr=0;
	for(int i = 0; i < N; i++){
        
		if(ADN[i]==c){
			nbr++;
			if(c=='A'|| c=='T'){
				if( ADN[i]==c && ADN[i+1]==c && ADN[i+2]==c){
					i+=2;
				}
			}else{
				if( ADN[i]==c && ADN[i+1]==c && ADN[i+2]==c && ADN[i+3]==c){
					i+=3;
				}
			}
		}
	}
	printf("\nLe nbr de repetition de %c est: %d",c,nbr);
}
int main(){
	int N; char fileName[255];
	printf("donner le nom du fichier : ");
	scanf("%s",&fileName);
	strcat(fileName,".txt");
	printf("\ndonner logueur du ADN : ");
	scanf("%d",&N);
	Ecrire_Sequence(fileName, N);
	
	printf("\nle nbrs des caracteres :");
	CompteNucleotides(fileName);
	
	char *br=BrinCompInv(fileName,N);
	printf("\nbrinComplementaire de ADN :%s",br);
	
	char c;
	printf("\nVeuillez saisir un caractere (A,T,C,G) : ");
	scanf(" %c",&c); //espace obligatoire avant %c
	/* The leading whitespace ensures it's the previous newline is ignored */
	Nbrepetitions(fileName,N,c);

	return 0;
}

