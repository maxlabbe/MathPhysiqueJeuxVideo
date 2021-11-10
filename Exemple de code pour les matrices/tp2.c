#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Calcule du minimum */
float min(int a,int b){
	if(a>b){
		return b;
	}
	else{
		return a;
	}
}

/* Produit de deux matrices */
void produitM*M(double **A,double **B,int taille){
	int i,j,k;
	float s;
	double ** C= calloc(n,sizeof(double));
	for(i=0;i<n;i++){
		C[i]=calloc(n,sizeof(double));
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
}

/* Affichage des matrices */
void affichage(double **A,double*b,int taille){
	int l,c;
	for(l=0;l<taille;l++){
		for(c=0;c<taille;c++){
			printf("|%.2f ",A[l][c]);
		}
		printf("| %.2f|\n",b[l]);
	}
}

void affichageBis(double*x,double*b,int taille){
	int l;
	for(l=0;l<taille;l++){
		printf("|%.2f ",x[l]);
		printf("| %.2f|\n",b[l]);
	}
}

/* Méthode de Gauss */
void Gauss(double **A,double*b,double*x,int taille){
	int i,k,j;
	int imin;
	float min,tmp1,tmp2,alpha,s;
	for(k=0;k<taille-1;k++){
		min=A[k][k];
		imin=k;

		/* Pivot */
		for(i=k+1;i<taille;i++){
			if (min!=0){
				if ((abs(A[i][k])<abs(min)) && (A[i][k]!=0)){
					min=A[i][k];
					imin=i;
				}
			}
			else{
				min=A[i][k];
				imin=i;
			}
		}
		if(min==0){
			printf("La matrice est singulière.\n");
			exit(EXIT_FAILURE);
		}

		/* Echelonnage */
		for(j=0;j<taille;j++){
			tmp1=A[imin][j];
			A[imin][j]=A[k][j];
			A[k][j]=tmp1;
		}
		tmp2=b[imin];
		b[imin]=b[k];
		b[k]=tmp2;
		for(i=k+1;i<taille;i++){
			alpha=A[i][k]/A[k][k];
			for(j=i+1;j<taille;j++){
				A[i][j]=A[i][j]-alpha*A[k][j];
			}
			b[i]=b[i]-alpha*b[k];
		}
	}

	/* Résolution du système échelonné */
	x[taille-1]=b[taille-1]/A[taille-1][taille-1];
	for(i=taille-2;i>-1;i--){
		s=0;
		for(j=taille-1;j>i;j--){
			s=s+A[i][j]*x[j];
		}
		x[i]=(b[i]-s)/A[i][i];
	}
	printf("\n");
	affichageBis(x,b,taille);
}

/* Calcul de la norme */
float norme(double **A,double*b,double*x,int taille){
	int i,a,z;
	float n;
	double * y= calloc(taille,sizeof(double));
	for(i=0;i<taille;i++){
		for(a=0;a<taille;a++){
			for(z=0;z<taille;z++){
				y[a]=y[a]+A[a][z];
			}
			y[a]=y[a]*x[a]-b[a];
		}
		n=n+pow(y[i],2);
	}
	n=sqrt(n);
	return n;
}

/* Méthode de Jacobi */
void Jacobi(double **A,double*b,double*x,float e,int taille,int maxiter){
	int iter=0;
	int a,z,i;

	/* Choix du vecteur x de départ pour les itérations */
	for(i=0;i<n;i++){
		int c=0;
		printf("Entrer un entier\n");
		scanf("%d",&c);
		x[i]=c;
	}

	float resultat=norme(A,b,x,taille);

	/* Itérations */
	double * y= calloc(taille,sizeof(double));
	while((resultat>e) && (iter<maxiter)){
		for(a=0;a<taille;a++){
			for(z=0;z<taille;z++){
				y[a]=y[a]+A[a][z];			
			}
			y[a]=(b[a]-y[a]*x[a])/A[a][a];
		}
		for(i=0;i<taille;i++){
			x[i]=y[i];
		}
		resultat=norme(A,b,x,taille);
		iter++;
	}

	/* Affichage */
	affichageBis(x,b,taille);
}

/* Méthode de Gauss-Seidel */
void Gauss_Seidel(double **A,double*b,double*x,float e,int taille,int maxiter){
	double * y= calloc(taille,sizeof(double));
	int i,a,z;

	/* Choix du vecteur x de départ pour les itérations */
	for(i=0;i<n;i++){
		int c=0;
		printf("Entrer un entier\n");
		scanf("%d",&c);
		x[i]=c;
	}

	float resultat=norme(A,b,x,taille);
	for(i=0;i<taille;i++){
		y[i]=x[i];
	}

	/* Itérations */
	int iter=0;
	while((resultat>e) && (iter<maxiter)){
		for(i=0;i<taille;i++){
			x[i]=y[i];
		}
		for(a=0;a<taille;a++){
			for(z=0;z<a;z++){
				y[a]=y[a]+A[a][z]*y[z];
			}
			for(z=i;z<taille;z++){
				y[a]=y[a]+A[a][z]*x[z];
			}
			y[a]=(b[a]-y[a])/A[a][a];
		}
		resultat=norme(A,b,x,taille);
		iter++;
	}

	/* Affichage */
	affichageBis(x,b,taille);
}

/* Méthode de Cholesky */
void Cholesky(double **A,double*b,int taille){
	int i,k,l,m,n;
	float s=0;
	double ** r= calloc(n,sizeof(double));
	for(i=0;i<n;i++){
		r[i]=calloc(n,sizeof(double));
	}

	for(k=0;k<taille;k++){
		s=A[k][k];
		for(l=0;l<k-1;l++){
			s=s-pow(r[l][k],2);
		}
		if(s<=0){
			printf("R n'existe pas car A n'est pas définie positive.\n");
			exit(EXIT_FAILURE);
		}
		else{
			r[k][k]=sqrt(s);
			for(m=k;m<taille;m++){
				r[k][m]=A[k][m];
				for(n=0;n<k-1;n++){
					r[k][m]=r[k][m]-(r[n][k]*r[n][m]);
				}
				r[k][m]=r[k][m]/r[k][k];
			}
		}
	}
	affichage(r,b,taille);
}

/* Création des matrices */
void BordCarree(double **A, int taille){
	int i,j;
	for(i=0;i<taille;i++){
		for(j=0;j<taille;j++){
			if(i==j){
				A[i][j]=1;
			}
			else if((i==0) || (j==0)){
				A[i][j]=pow(2,-j);
			}
			else if((i==taille-1) || (j==taille-1)){
				A[i][j]=pow(2,taille-1-j);
			}
		}
	}
}

void DingDong(double **A, int taille){
	int i,j;
	for(i=0;i<taille;i++){
		for(j=0;j<taille;j++){
			A[i][j]=1/(2*(taille-i-j+1.5));
		}
	}
}

void FrancCarree(double **A, int taille){
		int i,j;
	for(i=0;i<taille;i++){
		for(j=0;j<taille;j++){
			if(i>=j+2){
				A[i][j]=0;
			}
			else{
				A[i][j]=min(i,j);
			}
		}
	}
}

void HilbertCarree(double **A, int taille){
	int i,j;
	for(i=0;i<taille;i++){
		for(j=0;j<taille;j++){
			A[i][j]=1/(i+j-1);
		}
	}
}

void kmsCarre(double **A, int taille, int p){
	int i,j;
	for(i=0;i<taille;i++){
		for(j=0;j<taille;j++){
			int a=fabs(i-j);
			A[i][j]=pow(p,a);
		}
	}
}

void LehmerCarre(double **A, int taille){
	int i,j;
	for(i=0;i<taille;i++){
		for(j=0;j<taille;j++){
			if(i<=j){
				A[i][j]=i/j;
			}
			else{
				A[i][j]=j/i;
			}
		}
	}
}

void LotkinCarre(double **A, int taille){
	int i,j;
	for(i=0;i<taille;i++){
		for(j=0;j<taille;j++){
			if(i==1){
				A[i][j]=1;
			}
			else{
				A[i][j]=1/(i+j-1);
			}
		}
	}
}

void MolerCarre(double **A, int taille){
	int i,j;
	for(i=0;i<taille;i++){
		for(j=0;j<taille;j++){
			if(i==j){
				A[i][j]=i;
			}
			else{
				A[i][j]=min(i,j)-2;
			}
		}
	}
}

/* Programme principal */
int main(){
	int n;
	printf("entrez la taille de votre matrice \n");
	scanf("%d",&n);
	double * b= calloc(n,sizeof(double));
	double * x= calloc(n,sizeof(double));
	double ** A= calloc(n,sizeof(double));
	int i;
	for(i=0;i<n;i++){
		A[i]=calloc(n,sizeof(double));
	}

	/* Création du vecteur b */
	for(i=0;i<n;i++){
		int a=0;
		printf("Entrer un entier\n");
		scanf("%d",&a);
		b[i]=a;
	}

	/* Création de la matrice A */
	//BordCarree(A,n);
	DingDong(A,n);
	//FrancCarree(A,n);
	//HilbertCarree(A,n);
	//kmsCarre(A,n);
	//LehmerCarre(A,n);
	//LotkinCarre(A,n);
	//MolerCarre(A,n);
	printf("Matrices de base :\n");
	affichage(A,b,n);

	/* Application des méthodes */
	//printf("\nGauss :\n");
	//Gauss(A,b,x,n);
	//printf("\nJacobi :\n");
	//Jacobi(A,b,x,pow(10,-2),n,5);
	//printf("\nGauss-Seidel :\n");
	//Gauss_Seidel(A,b,x,pow(10,-2),n,5);
	//printf("\nCholesky :\n");
	//Cholesky(A,b,n);
	return 0;
}
