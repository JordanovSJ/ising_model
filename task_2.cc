#include <iostream>
using namespace std;
#include <fstream>
#include "functions.h"

//Produces values of the mean magnetisation and energy as function of temperature or magnetic field
int main(){
	
	int steps;
	int N;
	int mode;	
	
	cout<<"As function of T: choose 1. As function of H: choose 2."<<endl;
	cin >> mode;
	
	if (mode==1){
		double Tmax,Tmin,Tstep;
		double H;
		cout<<"Write: N, steps, H, from T, to T, T step"<<endl;
		cin >> N >> steps >> H >> Tmin >> Tmax >> Tstep;		
		
		ofstream fout;	 
		fout.open("M_and_E_vs_T");	
		for (double T=Tmin;T<Tmax;T+=Tstep){		
			Lattice lattice(N,T,H);
			lattice.init_lattice_one();
		
			long int E_0=-lattice.energy(); //use this to scale the values of energy
			srand(time(NULL));	
			for (int i=0;i<steps;i++){
				step_sys(lattice);		
			}					 		
			fout<<T<<","<<lattice.magnetisation()<<","<<lattice.energy()/E_0<<endl;	
			lattice.deleteCells();
		}		
		fout.close();
	}
	
	
	if (mode==2){
		double Hmax,Hmin,Hstep;
		double T;
		cout<<"Write: N, steps, T, from H, to H, H step"<<endl;
		cin >> N >> steps >> T >> Hmin >> Hmax >> Hstep;		
		
		ofstream fout;	 
		fout.open("M_and_E_vs_H");	
	
		for (double H=Hmin;H<Hmax;H+=Hstep){		
			Lattice lattice(N,T,H);
			lattice.init_lattice_one();
		
			long int E_0=-lattice.energy(); //use this to scale the values of energy
			srand(time(NULL));	
			for (int i=0;i<steps;i++){
				step_sys(lattice);		
			}					 		
			fout<<H<<","<<lattice.magnetisation()<<","<<lattice.energy()/E_0<<endl;	
			lattice.deleteCells();
		}
		fout.close();
	}		
	
	return 0;	
}
