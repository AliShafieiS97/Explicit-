#include <iostream>
#include <cmath>

using namespace std; 

int main(){
	
	double landa = 400;
	double rho = 8960; 
	double Cp = 380; 
	double alpha=landa/(rho*Cp);
	double L = 1; 
	double t = 2000; 
	double deltat = 0.1; 
	double deltax = 0.01;
	int N = L/deltax; 
	int M = t/deltat; 
	
	double convergence_index = (deltat*alpha)/(deltax*deltax);

	double T[M-1][N-1];
	
	if (convergence_index < 0.5){
	
		for (int i = 0;i<=N-1;i++){
	
    		T[0][i] = 30; 
    		
    	}
    
    	for (int j = 0;j<=M-1-1;j++){
	
    		T[j][0] = 100; 
    		T[j][N-1] = 20;
    		
    	}
    
		for (int j = 0;j<=M-2;j++){
		
        	for (int i = 1;i<=N-2;i++){
        		
            	T[j+1][i]=(((alpha*deltat)/(deltax*deltax))*(T[j][i+1]-2*T[j][i]+T[j][i-1])+T[j][i]);
            	
            }
        }
	}
	
	else {
		
		cout<<"Error! Please Refine the convergence index!";
	}
	
}
