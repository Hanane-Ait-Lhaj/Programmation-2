#include <stdlib.h>
#include <stdio.h>
#include <time.h>

char *Allouer(int N){
	char *c;
	int n;
	c=(char*) malloc (n*sizeof(char));
	if(c!=NULL)
		return c;
	}
	
char * ADN_Sequences(char *ADN ,int N){
	srand(time(NULL));
	int n =0;
	//pourcentage :
	int A=0,C=0,G=0,T=0;
	for(int i=0;i<N ;i++){
		n=rand() % 4;

		if(A!=N*0.1 && n==0){
			*(ADN+i)='A';
			A++;
		}
		else if(C!= N*0.1 && n == 1){
			*(ADN+i)='C';
			C++;
		}
		else if(G != N*0.5 && n == 2){
			*(ADN+i)='G';
			G++;
		}
		else if(T != N*0.3 && n == 3){
			*(ADN+i)='T';
			T++;
		}
		else {
			i--;
		}
		
//Methode 2 :
//		switch(n) {
//			case 0:
//				if(A!=N*0.1){
//					*(ADN+i)='A';
//					A++;		
//				}else i--;
//			break;
//			case 1:
//				if(G!=N*0.5){
//					*(ADN+i)='G';
//					G++;
//				}else i--;
//			break;
//			case 2:
//				if(T!=N*0.3){
//					*(ADN+i)='T';
//					T++;
//				}else i--;
//			break;
//			case 3:
//				if(C!=N*0.1){	
//					*(ADN+i)='C';
//					C++;
//				}else i--;
//			break;
//		}
//		
		
	}
	return ADN;
}

int ConvertirEnBase4(char* ADN,int N)
{
	int num = 0;
	int base = 1;
	
	for (int i = N - 1; i >= 0; i--)
	{
		if (*(ADN+i) == 'A')
			num += 0 * base;
		else if (*(ADN+i) == 'T')
			num += 1 * base;
		else if (*(ADN+i) == 'G')
			num += 2 * base;
		else if (*(ADN+i) == 'C')
			num += 3 * base;
		base = base * 4;
	}
	
	return num;
}
//Q4 :
void codons(char *ADN, int N){
	for(int i=0;i<N-2;i++){
		printf("%c",*(ADN+i));
		printf("%c",*(ADN+i+1));
		printf("%c",*(ADN+i+2));
		printf(" ");
	}
}

void codon_stop(char *ADN, int N,int ind){
//	printf("\nles positions de codans stop :\n");
	int pos = 0;
	for(int i=ind;i<N-2;i++){
		if(*(ADN+i)=='T' && *(ADN+i+1)=='A' && *(ADN+i+2) == 'A'){
				pos++;
				printf("\ncodan stop: le position de TAA est %d",i);
				break;
				
		}
		if(*(ADN+i)=='T' && *(ADN+i+1)=='A' && *(ADN+i+2) == 'G'){
				pos++;
				printf("\ncodan stop: le position de TAG est %d",i);
				break;
				
		}
		if(*(ADN+i)=='T' && *(ADN+i+1)=='G' && *(ADN+i+2) == 'A'){
				pos++;
				printf("\ncodan stop: le position de TGA est %d",i);
				break;
		}		
	}
	if(pos==0){
		printf("\ncodan stop introuvable\n");
	}	
}

//Q5 :
void codon_start(char *ADN,int N){
	
	int pos = 0;
	for(int i=0;i<N-2;i++){
		if(*(ADN+i)=='A' && *(ADN+i+1)=='T' && *(ADN+i+2) == 'G'){
				pos++;
				printf("\ncodan start: le position de ATG est %d",i);
				
				codon_stop(ADN,N,i+3);
				
		}
	}
	if(pos==0){
		printf("\ncodan start introuvable\n");
	}

}


void regions_codante(char *ADN, int N){
	
	int reg = 0;
	for(int i=0;i<N-2;i++){
		if(*(ADN+i)=='A' && *(ADN+i+1)=='T' && *(ADN+i+2) == 'G'){
				
			for(int j=i+1;i<N-2;j++){
				
				if(*(ADN+j)=='T' && *(ADN+j+1)=='A' && *(ADN+j+2) == 'A'){
					reg++;
					printf("\nregion : ");
					
					for(int k = i+1;k<j;k++){
						printf("%c",*(ADN+k));
						
					}
					break;
				}
				if(*(ADN+j)=='T' && *(ADN+j+1)=='A' && *(ADN+j+2) == 'G'){
					reg++;
					printf("\nregion : ");
					for(int k = i+3;k<j;k++){
						printf("%c",*(ADN+k));
						
					}
					break;
				}
				if(*(ADN+j)=='T' && *(ADN+j+1)=='G' && *(ADN+j+2) == 'A'){
					reg++;
					printf("\nregion : ");
					for(int k = i+3;k<j;k++){
						printf("%c",*(ADN+k));	
					}
					break;
				}
				if(*(ADN+j)=='A' && *(ADN+j+1)=='T' && *(ADN+j+2) == 'G'){
					i=j;
					continue;
				}
			}
		}
	}
	if(reg == 0){
		printf("les codans regiantes introuvable");
	}
}

int SupprimeDupplications(char *ADN, int N){
	
	for(int i =0 ; i<N-1 ; i++){
		if(*(ADN+i)==*(ADN+i+1)){
			//ecraser les elements et supp le dup
			for(int j=i+1;j<N-1;j++){
				*(ADN+j)=*(ADN+j+1);
			}
			i--;
			N--;

			
		}
	}

	return N;
}

int main()
{
//	int num;
//	char *ADN;
//	int N =1;
//	printf("-----------------------------------------------------");
//	printf("\n------tester le saisie aleatoire du ADN -------------\n");
//	printf("-----------------------------------------------------");
//	
char *ADN;
int N;
	printf("\nEntrer la taille du chaine DNA : ");
	scanf("%d",&N);
	ADN = Allouer(N);

	//Q2 : aleatoire
	ADN = ADN_Sequences(ADN,N);
	for(int i=0;i<N;i++){
		printf("%c",*(ADN+i));
	}
		//Q8 : 
	printf("\n\nla chaine ADN apres suppression des dupplications : ");
	N=SupprimeDupplications(ADN,N);
	printf("\ntaille: %d\n",N);
	for(int i=0;i<N;i++){
		printf("%c",*(ADN+i));
	}
////	//Q3 : 
////	num = ConvertirEnBase4(ADN,N);
////	printf("\nconvertir du ADN en base 4 : %d",num);
//	//Q4 :
//	printf("\nLes condons de la sequence ADN : ");
////Q9:chercher les alagrames d'un mots donne: ATG > AGT-GAT-TAG-GTA-TGA
//	codons(ADN,N);
//int k=0;
//printf("\n");
//	for(int i=0;i<N;i++){
//		printf("%c",*(ADN+i));
//		k++;
//		if(k==3) {
//			printf(" ");
//			k=0;
//		}
//	}


ADN = "ATCTCAATGCTCGGTAATGTCTCATAG";
N=27;
	//Q5 : codon_start(ADN)
	printf("\n\nles postions des codans stop et start dans la chaine : ");
	codon_start(ADN,N);
	
//	//Q5 : codon_stop(ADN)
//	printf("\n\nles postions des codons stop dans la chaine : ");
//	codon_stop(ADN,N,0);
	
	//Q7:
	printf("\n\nles regions codantes:\n");
	regions_codante(ADN, N);	
	



//
//	//Q3 : Exemple
//	char *ADN2 = "ATCG";
//	printf("\n\n-----------------------------------------------------");
//	printf("\n---------tester l'exemple ADN=: ATCG ----------------\n");
//	printf("-----------------------------------------------------");
//	
//	num = ConvertirEnBase4(ADN2,4);
//	printf("\nconvertir du ADN en base 4 : %d",num);
//	//Q4 : les triplets
//	printf("\nLes condons de la sequence ADN : ");
//	codons(ADN2,4);
//	

	return 0;
	
}


