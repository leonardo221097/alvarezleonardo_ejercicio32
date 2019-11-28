#include <fstream>
#include <iostream>
#include <cmath>
using namespace std;


int main(){
 float rho=0.01;
float deltat = 0.01;
float deltax = 0.01;
float t= 6.0;
float c= 0.5;
float L = 1.0;
int numt = t/deltat;
int numx= L/deltax;
float c_prima = deltax/deltat;
ofstream outfile;
outfile.open("ejercicio32.dat");

    
    double **M = new double *[numx];
    for (int i=0;i<numx;i++){
        M[i] =new double[numt];
    }
    
    
	for (int i=0;i<numx;i++){  
      
        M[i][0] = sin(M_PI*(i*deltax)/L);
		
        }
    M[0][1]=0;
    M[numx-1][1]=0;
    for (int i=1;i<numx-1;i++)
    {
       M[i][1]=M[i][0] + (c*c/(2*c_prima*c_prima))*(M[i+1][0]+M[i-1][0]-2*M[i][0]);
    }
    
    
    for(int j=1;j<numt-1;j++){
        for(int i=1; i<numx-1; i++){
            M[i][j+1] = 2*M[i][j]-M[i][j-1]+(c*c/(c_prima*c_prima))*(M[i+1][j]+M[i-1][j]-2*M[i][j]);
        }
    }
     
    
    for(int j=0; j<numt; j++){
        for(int i=0; i<numx; i++){
            outfile<<M[i][j]<<"\t";
        }
        outfile<<endl;
    }
    outfile.close();
    
    
    return 0;
}

