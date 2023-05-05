#include <stdio.h>
#include <stdlib.h>

int Hailstone_numbers(int Nb){
	int taille=1,i=0;
	int *T = (int *)malloc (taille * sizeof(int));
	
	int length = 0;
    while(Nb != 1)
    {
        if( Nb % 2)  //si le nb est pair
            Nb = (Nb*3)+1;
        else                /* even */
            Nb /= 2;
        
        length++;
        taille++;
        T = (int *)realloc(T,taille*sizeof(int));
        *(T+i) = Nb;
        
        printf("%3d ",*(T+i));
        i++;
    }
    return length;
}


int Hailstone_numbersR(int Nb,int length,int taille,int i,int *T){

    if(Nb != 1)
    {
        if( Nb % 2 )  /* true if odd */
            Nb = (Nb*3)+1;
        else                /* even */
            Nb /= 2;
        length++;
        taille++;
        T = (int *)realloc(T,taille*sizeof(int));
        *(T+i) = Nb;
        printf("%3d ",*(T+i));
        
        i++;
        
        Hailstone_numbersR(Nb,length,taille,i,T);
    }else{
   		 return length;
    	
	}
}

int main()
{
	int *T= (int *)malloc (sizeof(int));
	printf("--------------------------------------\n");
	printf("-------------Hailstone_numbers--------\n");
    printf("--------------------------------------\n");
	int Nb,length;
    
	printf("entrer le nombre : ");
	scanf("%d",&Nb);
    
    length = Hailstone_numbers(Nb);
    printf("\nNombre des étapes requises: %d\n",length);
    
    printf("la methode recursive :");
    length = Hailstone_numbersR(Nb,0,1,0,T);
    printf("\nNombre des étapes requises: %d\n",length);
    
    return(0);
}
