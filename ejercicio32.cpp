#include <fstream>
#include <iostream>
#include <cmath>
using namespace std;

// para realizar este ejercicio me guié de las condiciones para inicializar la matriz del libro de Landau capitulo 18.
int main(){
	// condiciones iniciale dadas en el libro y dadas en clase
 float rho=0.01;
float ten=40.0;
float deltat = 0.0001;
float deltax = 0.01;
float t= 0.1;
float c= sqrt(ten/rho);
float L = 1.0;
int numt = t/deltat;
int numx= L/deltax;
float c_prima = deltax/deltat;


    //creo la matriz
    double **M = new double *[numx];
    for (int i=0;i<numx;i++){
        M[i] =new double[numt];
    }
    
    // inicializo la matriz del pasado
	for (int i=0;i<numx;i++){  
      
        M[i][0] = 0.0001*sin(2.0*M_PI*(i*deltax)/L);
		
        }
	// inicializo la matriz del presente 
    M[0][1]=0;
    M[numx-1][1]=0;
    for (int i=1;i<numx-1;i++)
    {
       M[i][1]=M[i][0] + (c*c/(2*c_prima*c_prima))*(M[i+1][0]+M[i-1][0]-2*M[i][0]);
    }
    
    //inicializo la matriz del futuro.
    for(int j=1;j<numt-1;j++){
        for(int i=1; i<numx-1; i++){
            M[i][j+1] = 2*M[i][j]-M[i][j-1]+(c*c/(c_prima*c_prima))*(M[i+1][j]+M[i-1][j]-2*M[i][j]);
        }
    }
     // imprimo los valores de la matriz en un .dat
    ofstream outfile;
outfile.open("ejercicio32.dat");
    for(int j=0; j<numt; j++){
        for(int i=0; i<numx; i++){
            outfile<<M[i][j]<<"\t";
        }
        outfile<<endl;
    }
    outfile.close();
    
    
    return 0;
}

