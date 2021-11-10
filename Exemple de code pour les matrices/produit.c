void produitM*V(double **A,double*x,double*y,int taille){
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

void freeMatriceCarrée(double **A,int taille){
	int i;
	for(i=0;i<taille;i++){
		free(A[i]);
	}
	free(A);
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
			double ** B=malloc(sizeof(*double)*(taille-1));
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
