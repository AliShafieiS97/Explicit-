#include <iostream>
#include <cmath>

using namespace std; 

int main(){
	
	double deltat,deltax,landa,rho,Cp; 
	
	deltat=0.1;
	deltax=0.01;
	landa=400;
	rho=8690;
	Cp=380;

	double alpha=(landa/(rho*Cp)); 
	cout<<"Alpha is equal to: "<<alpha<<endl;
	double convergence_index=(deltat*alpha)/(deltax*deltax);
	
	
	double T[100][10000];
	
	int i,j;
	
	for (i=1;i<=99;i++){
		T[i][0]=30;
	}
	
	for (j=0;j<=10000;j++){
		T[0][j]=100;
	}
	
	for (j=0;j<=10000;j++){
		T[100][j]=20;
	}
	
	
	for(j=0;j<=10000;j++){
		
		for(i=1;i<=99;i++){
			
			T[i][j+1]=(((alpha*deltat)/(deltax*deltax))*(T[i+1][j]-2*T[i][j]+T[i-1][j]))+T[i][j];
		}	
	}
	cout<<T[50][5000];
	
}