//Nom: Tutusaus Alcaraz Guillem
//NIU: 1533701

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

#define TOL 1.e-6

void matriu(int ,double *); //Creem una funció tipus void per llegir la matriu
void vector(int ,double *); //Creem una funció tipus void per llegir el terme independent del sistema
void esglao(int ,double *,double *); //Funció que esglaona la matriu usant el mètode de Gauss
void LU(int ,double *,double *,double *); //Funció que genera dues matrius, la L i U
void solveL(int ,double *,double *,double *); //funció que soluciona el sistema triangular inferior amb substitució cap al davant
void solveU(int ,double *,double *,double *); //funció que soluciona el sistema triangular superior amb substitució cap al darrera
void pivottotal(int ,double *,double *,double *);

int main(void) {
	double *mat,*vect,*L,*U,*y,*z,*P,*Q; //Declaració dels punters que emmagatzemaran la matriu i el vector
	int dim,i,j; //Declaració de variables diverses
	
	printf("***************FACTORITZACIO LU***************\n");
	
	printf("Quina dimensio te la matriu?\n");
	scanf("%d",&dim); //Dimensió de la matriu
	
	mat=(double *)malloc(dim*dim*sizeof(double)); //Dynamic Memory Allocator (DMA) que guarda la memòria necessaria per la matriu
	vect=(double *)malloc(dim*sizeof(double)); //DMA pel vector tipus double
	L=(double *)malloc(dim*dim*sizeof(double)); //Assignem memòria a la matriu L
	U=(double *)malloc(dim*dim*sizeof(double)); //Assignem memòria a la matriu U
	y=(double *)malloc(dim*sizeof(double)); //assignem memòria al vector que contindra les solucions del sisttema L
	z=(double *)malloc(dim*sizeof(double)); //assignem memoria al vector que contindra les solucions del sistema
	P=(double *)malloc(dim*dim*sizeof(double));
	Q=(double *)malloc(dim*dim*sizeof(double));
	
	if((mat==NULL)||(vect==NULL)||(L==NULL)||(U==NULL)||(y==NULL)||(z==NULL)||(P==NULL)||(Q==NULL)){ //Per si no pot guardar la memòria sol·licitada
		printf("No he pogut reservar l’espai.\n");
		return 1;
	}
	
	matriu(dim,mat); //Cridem la funció per generar la matriu
	
	vector(dim,vect); //Cridem la funció per generar el terme independent
	
	LU(dim,mat,L,U); //Cridem la funció LU
	
	solveL(dim,L,vect,y); //cridem la funció solveL que soluciona el sistema L amb substitució cap al davant i emmagatzema les solucions al vector y
	
	solveU(dim,U,y,z); //cridem la funció solveU que soluciona el sistema U am substitucio cap al darrera i emmagatzema les solucions al vector z
	
	printf("Solucions del sistema\n");
	
	for(i=0;i<dim;i++){
		printf("z[%i]=%lf\n",i+1,z[i]);
	}
	
	printf("Matriu L\n");
	
	for(i=0;i<dim;i++){
		for(j=0;j<dim;j++){
			printf("L[%i][%i]=%lf\n",i+1,j+1,L[dim*i+j]);
		}
	}
	
	printf("Matriu U\n");
	
	for(i=0;i<dim;i++){
		for(j=0;j<dim;j++){
			printf("U[%i][%i]=%lf\n",i+1,j+1,U[dim*i+j]);
		}
	}
	
	printf("Matriu P\n");
	
	for(i=0;i<dim;i++){
		for(j=0;j<dim;j++){
			printf("P[%i][%i]=%lf\n",i+1,j+1,P[dim*i+j]);
		}
	}
	
	printf("Matriu Q\n");
	
	for(i=0;i<dim;i++){
		for(j=0;j<dim;j++){
			printf("Q[%i][%i]=%lf\n",i+1,j+1,Q[dim*i+j]);
		}
	}

	free(mat); //DMA Alliberament de la memòria reservada
	free(vect);
	free(L);
	free(U);
	free(y);
	free(z);
	free(P);
	free(Q);
	
	return 0;
}

void matriu(int dim, double *mat){
	int i,j;
	
	printf("Introdueix la matriu.\n");
	
	for(i=0;i<dim;i++){ //Introducció de les components de la matriu
		for(j=0;j<dim;j++){
			printf("a[%d][%d]=",i+1,j+1);
			scanf("%lf",&mat[dim*i+j]);
		}
	}
}

void vector(int dim, double *vect){
	int i;
	
	printf("Introdueix els termes independents del sistema.\n");
	
	for(i=0;i<dim;i++){ //Introducció de les components del vector
		printf("b[%d]=",i+1);
		scanf("%lf",&vect[i]);
	}
}

void esglao(int dim, double *U, double *x){
	int i,j,k;
	
	for(k=0;k<dim;k++){ //Mètode de reducció de Gauss per esglaonar la matriu U, aquest mètode esglaona la matriu sencera
		for(i=k+1;i<dim;i++){
			x[dim*k+i]=((U[dim*i+k])/(U[dim*k+k]));
			if(abs(U[dim*k+k])<TOL){
				printf("No existeix factoritzacio LU.\n");
				exit(1);
			}
			for(j=k;j<dim;j++){
				U[dim*i+j]=U[dim*i+j]-x[dim*k+i]*U[dim*k+j];
			}
		}
	}
}

void LU(int dim, double *mat, double *L, double *U){
	int i,j;
	double *x;
	
	x=(double *)malloc(dim*dim*sizeof(double));
	
	for(i=0;i<dim;i++){
		for(j=0;j<dim;j++){
			U[dim*i+j]=mat[dim*i+j];
		}
	}
	
	esglao(dim,U,x); //Funció que esglaona una matriu amb el mètode de Gauss
	
	for(i=0;i<dim;i++){
		for(j=0;j<dim;j++){
			if(i==j){
				L[dim*i+j]=1;
			}
			else{
				L[dim*i+j]=0;
			}
		}
	}
	
	for(i=0;i<dim;i++){
		for(j=i+1;j<dim;j++){
			L[dim*j+i]=x[dim*i+j];
		}
	}
}

void solveL(int dim, double *L, double *vect, double *y){
	int i,j;
	double sum=0;

	y[0]=vect[0]/L[dim*0+0];

	for(i=1;i<dim;i++){
		for(j=0;j<i;j++){
			sum=sum+L[dim*i+j]*y[j];
		}
		y[i]=(1/L[dim*i+i])*(vect[i]-sum);
		sum=0;
	}
}

void solveU(int dim, double *U, double *y, double *z){
	int i,j;
	double sum=0;
	
	z[dim-1]=y[dim-1]/U[dim*(dim-1)+(dim-1)];
	
	for(i=dim-2;i>=0;i--){
		for(j=i+1;j<=dim;j++){
			sum=sum+U[dim*i+j]*z[j];
		}
		z[i]=(1/U[dim*i+i])*(y[i]-sum);
		sum=0;
	}
}

void pivottotal(int dim, double *U, double *P, double *Q){
	int i,j,coordi=0,coordj=0;
	double max=0;
	
	for(i=0;i<dim;i++){
		for(j=0;j<dim;j++){
			if(abs(U[dim*i+j])>max){
				max=U[dim*i+j];
				coordi=i;
				coordj=j;
			}
		}
	}
	
	for(i=0;i<dim;i++){
		for(j=0;j<dim;j++){
			if(i==j){
				P[dim*i+j]=Q[dim*i+j]=1;
			}
			else{
				P[dim*i+j]=Q[dim*i+j]=0;
			}
		}
	}
	
	for(i=0;i<dim;i++){
		for(j=0;j<dim;j++){
			
		}
	}
	
}