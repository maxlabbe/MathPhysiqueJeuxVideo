#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void produitMxV(double **A,double*x,double*y,int taille){
	int i,j;
	float s;
	for(i=0;i<taille;i++){
		s=0;
		for(j=0;j<taille;j++){
			s=s+A[i][j]*x[i];
		}
	y[i]=s;
	}
}

/* Produit de deux matrices */
double **produitMxM(double **A,double **B,int taille){
	int i,j,k;
	float s;
	double ** C= calloc(taille,sizeof(double));
	for(i=0;i<taille;i++){
		C[i]=calloc(taille,sizeof(double));
	}
	for(i=0;i<taille;i++){
		for(j=0;j<taille;j++){
			s=0;
			for(k=0;k<taille;k++){
				s=s+A[i][k]*B[k][j];
			}
		C[i][j]=s;
		}
	}
	return C;
}

float determinant(double **A,int taille){
	int i,j,k;
	float det=0;
	if(taille==2){
		det=A[0][0]*A[1][1]-A[0][1]*A[1][0];
		return det;
	}
	else{
		for(i=0;i<taille;i++){
			double ** B= malloc((taille-1)*sizeof(double));
			for(j=0;j<taille;j++){
				if(j!=i){
					for(k=0;k<taille-1;k++){
						B[j][k]=A[j][k+1];
					}
				}
			}
			det=det+determinant(B,taille-1);
			if(i%2==0){
				det=det*A[i][0];
			}
			else{
				det=det*(-A[i][0]);
			}
		}
		return det;
	}
}

float trace(double **A,int taille){
	int i;
	float trace=0;
	for(i=0;i<taille;i++){
		trace=trace+A[i][i];
	}
	return trace;
}

void Leverrier(double **A,int taille){
	int i,j;
	double * a=calloc(taille,sizeof(double));
	double * S=malloc(taille*sizeof(double));
	double ** B=malloc(taille*sizeof(double));
	for(i=0;i<taille;i++){
		B[i]=calloc(taille,sizeof(double));
		B[i][i]=1;
	}
	for(i=0;i<taille;i++){
		for(j=1;j<=i;j++){
			B=produitMxM(A,B,taille);
		}
		S[i]=trace(B,taille);
	}
	a[0]=-S[0];
	for(i=1;i<taille;i++){
		a[i]=S[i];
		for(j=0;j<i;j++){
			a[i]=a[i]+(a[j]*S[i-j]);
		}
		a[i]=-a[i]/i;
	}
	printf("Le polynôme caractéristique de A est :\nP(X) = ");
	for(i=0;i<taille-1;i++){
		printf("%f * (X^%d) + ",a[i],taille-i);
	}
	printf("%f\n",a[taille-1]);

	/* Libération de la mémoire */
	for(i=0;i<taille;i++){
		free(B[i]);
	}
	free(B);
	free(a);
	free(S);
}


double vp_puissances(double **A,double*x,double*y,int taille){
	double * q= calloc(taille,sizeof(double));
	int test=1;
	int i;
	double a;
	double valprop;
	float e=pow(10,-3);

	/* Calcul du quotient */
	for(i=0;i<taille;i++){
		a = y[i]/x[i];
		q[i]=a;
	}
	test=1;

	for(i=0;i<taille-1;i++){
		if(abs(q[i]-q[i+1])<=e){
			test=test&&1;
		}
		else{
			test=test&&0;
		}
	}

	/* Récursivité */
	if(test!=0){
		valprop=q[0];
		return valprop;
	}
	else{
		for(i=0;i<taille-1;i++){
			x[i]=y[i];
		}
		produitMxV(A,x,y,taille);
		vp_puissances(A,x,y,taille);
	}

	/* Libération de la mémoire */
	free(q);
}


void puissances(double **A,int taille){
	double * x= calloc(taille,sizeof(double));
	double * y= calloc(taille,sizeof(double));
	int i;
	double vp;

	// Choix du vecteur x de départ pour les itérations
	printf("Valeur de départ de x pour les itérations :\n");
	for(i=0;i<taille;i++){
		int c=0;
		printf("x[%d] = ",i+1);
		scanf("%d",&c);
		x[i]=c;
	}

	// Itérations
	produitMxV(A,x,y,taille);
	vp=vp_puissances(A,x,y,taille);
	printf("La plus grande valeur propre de A est : %f\n",vp);

	/* Libération de la mémoire */
	free(y);
}



int main(){
	return 0;
}
