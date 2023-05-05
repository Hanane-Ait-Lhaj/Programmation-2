#include <stdio.h>
#include <stdlib.h>
 

void PremiersR(int n,int k, int *T,int taille,int i){
	if (n%2 == 0)
    {
   		taille++;
		T=(int *)realloc(T,taille*sizeof(int));
        
        *(T+i) = 2;
        printf(" %d ",*(T+i));
        i++;
        
        n=n/2;
        PremiersR(n,k,T,taille,i);
    }

    if(n!=1){ //or n>=k
        if(n%k==0)
        {
        	while(n%k == 0){
            	taille++;
				T=(int *)realloc(T,taille*sizeof(int));
        
        		*(T+i) = k;
        		printf(" %d ",*(T+i));
        		i++;
        		
            	n=n/k;
			}
		}else{
            	k = k+2;
		}
		PremiersR(n,k,T,taille,i);
	}
           
}

void Premiers(int n){
	int i = 0, taille = 1,k;
	int *T = (int *) malloc(taille * sizeof(int));
	
    printf("\nFacteurs premiers\n");
    while (n%2 == 0)
    { 
		taille++;
		T=(int *)realloc(T,taille*sizeof(int));
        
        *(T+i) = 2;
        printf(" %d ",*(T+i));
        i++;
        
        n=n/2;
    }
    
    k=3;
    while(n!=1){ //or n>=k
        if(n%k==0)
        {
        	while(n%k == 0){
            	taille++;
				T=(int *)realloc(T,taille*sizeof(int));
        
        		*(T+i) = k;
        		printf(" %d ",*(T+i));
        		i++;
        		
            	n=n/k;
			}
		}else{
            	k = k+2;
		}
	}
}

int main()
{
	int n=0 ;
	printf("\nDecomposition d'un nombre en facteurs premiers\n");
	printf("\nIntroduire un nombre >0\n");
	scanf("%d",&n);

	Premiers(n);
	
	printf("\n");
	
	int *T = (int *) malloc(sizeof(int));
    PremiersR(n,3,T,1,0);

 
return 0;
 
}

