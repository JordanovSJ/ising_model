#include <iostream>
using namespace std;
#include <fstream>
#include "functions.h"

//Compute the heat capacity/ magnetic succeptibility using the fluctuation dissipation theorem
int main(){
	
	int N=1000;
	long int steps=10000; //number of measurements from which the standard deviation is calculated
	int equilibrium_step=500; 
	double H=0.0;
	double Tmin,Tmax;
	int mode; //1 for heat capacity, 2 for magnetic succeptibility
	
	cout<<"Heat capacity:1.Magnetic succeptibilty:2"<<endl;
	cin>>mode;
	cout<<"Write: N, equillibrium , steps, from temperature, to temperature"<<endl;
	cin >> N >> equilibrium_step >> steps>>Tmin>>Tmax;

	//It is important that we seed only once since we are interested in standard deviation
	srand(time(NULL));
	
	//write data to file
	ofstream fout;	
	fout.open("C_and_Chi");	
	
	//simulate for a range of temperatures
	for (double T=Tmin;T<Tmax;T+=0.01){	
		Lattice lattice(N,T,H);
		double values[steps];		
		lattice.init_lattice_one();
								
		for (int step=0;step<(steps+equilibrium_step);step++){
			step_sys(lattice);
			if (step >= equilibrium_step){ 				
				if (mode==1) values[step-equilibrium_step]=lattice.energy();
				if (mode==2) values[step-equilibrium_step]=lattice.magnetisation();		
			}
		}			
		
		if (mode==1){
			double C=std_dev(values,steps)/(T*T);		
			fout<< T << "," << C << endl;
		}					 
		if (mode==2){
			double chi=std_dev(values,steps)/T;
			fout<< T << "," << chi << endl;
		}				 
					
		lattice.deleteCells();			
	}
	fout.close();
	
	return 0;	
}
