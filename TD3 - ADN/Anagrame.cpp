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
	
void Anagrame(char *ADN, int N){


		for(int j=N;j<=0;j++){
			for(int l=j;l<N;l++){
						
//				printf("%c",*(ADN+i));
				printf("%c",*(ADN+j));
				printf("%c ",*(ADN+l));}}

	
	
}

int main()
{
	int num;
	char *ADN;
	int N =1;
	printf("-----------------------------------------------------");
	printf("\n------tester le saisie aleatoire du ADN -------------\n");
	printf("-----------------------------------------------------");

//	printf("\nEntrer la taille du chaine DNA : ");
//	scanf("%d",&N);
//	ADN = Allouer(N);
	
//	printf("\nEntrer la chaine de caracteres : ");
//	scanf("%d",ADN);
//	
	ADN = "ATC";
	Anagrame(ADN,3);
	return 0;
	
}


