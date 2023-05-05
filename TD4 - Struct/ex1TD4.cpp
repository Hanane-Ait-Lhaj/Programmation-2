#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Point{
	int x;
	int y;
};
typedef struct Point Point;
typedef struct Disque{
	Point p;
	int R;
}Disque;

typedef struct Triangle{
	Point A;
	Point B;
	Point C;
}Triangle;

typedef struct Rectangle{
	Point A; //sup gauche
	Point B; //inf droit
}Rectangle;


int DistancePoint(Point a,Point b){
	int dx=a.x-b.x;
	int dy=a.y-b.y;
	return sqrt(pow(dx,2)+pow(dy,2));
}

float AireDisque(Disque D){
	return 3.14 * D.R * D.R;
}
int valAbs(int v){
	if(v>=0)
		return v;
	else return -v;
}
double AireTriangle(Triangle T){
	int calc = (T.B.x-T.A.x)*(T.C.y-T.A.y)-(T.C.x-T.A.x)*(T.B.y-T.A.y);
	return (1/2)*calc;
}

int AireRectangle(Rectangle R){
	int largeur = R.A.y - R.B.y;
	int longueur = R.B.x - R.A.x;
	return valAbs(largeur * longueur);
}



int main(){
	Point p1,p2;
	printf("----------------Menu-----------------");
	printf("\n1-distance entre 2 points :");
	printf("\nxA = ");
	scanf("%d",&p1.x);
	printf("\nyA = ");
	scanf("%d",&p1.y);
	printf("\nxB = ");
	scanf("%d",&p2.x);
	printf("\nyB = ");
	scanf("%d",&p2.y);
	printf("\nla distance : %d",DistancePoint(p1,p2));
	
	printf("\n2-Aire disque:");
	Disque D;
	printf("\nDonnez le centre :");
	printf("\nx = ");
	scanf("%d",&p1.x);
	printf("\ny = ");
	scanf("%d",&p1.y);
	D.p = p1;
	printf("\nDonner le rayon :");
	scanf("%d",&D.R);
	printf("\nAire du disque : %d",AireDisque(D));
	
	printf("\n3- Aire triangle :");
	Point A,B,C;
	Triangle T;
	printf("\nxA = ");
	scanf("%d",&A.x);
	printf("\nyA = ");
	scanf("%d",&A.y);
	printf("\nxB = ");
	scanf("%d",&B.x);
	printf("\nyB = ");
	scanf("%d",&B.y);
	printf("\nxC = ");
	scanf("%d",&C.x);
	printf("\nyC = ");
	scanf("%d",&C.y);
	
	T.A = A;
	T.B = B;
	T.C = C;
	printf("\nAire de triangle : %lf",AireTriangle(T));
	
	printf("\n2-Aire rectangle:");
	Rectangle R;
	printf("\nxA = ");
	scanf("%d",&A.x);
	printf("\nyA = ");
	scanf("%d",&A.y);
	printf("\nxB = ");
	scanf("%d",&B.x);
	printf("\nyB = ");
	scanf("%d",&B.y);
	R.A = A;
	R.B = B;
	printf("\nAire de rectangle : %d",AireRectangle(R));
	return 0;
}


