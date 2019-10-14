#include <iostream>
using namespace std;
#include <fstream>
#include "functions.h"

int main(){
	//Compare different initial lattices 
	
	int steps=20000;
	int N=1000;	
	double H=0.0;
	double T=2.0;
	
	ofstream fout;	
	
	Lattice lattice_rnd(N,T,H);
	fout.open("data_rnd");	
	lattice_rnd.init_lattice_rnd();
	srand(time(NULL));		
	for (int i=0;i<steps;i++){
		step_sys(lattice_rnd);
		fout<< i << "," << lattice_rnd.spin() << endl;		
	}	
	fout.close();	
	
	Lattice lattice_half(N,T,H);
	fout.open("data_half");	
	lattice_half.init_lattice_half();
	srand(time(NULL));		
	for (int i=0;i<steps;i++){
		step_sys(lattice_half);
		fout<< i << "," << lattice_half.spin() << endl;		
	}	
	fout.close();	
	
	Lattice lattice_one(N,T,H);
	fout.open("data_one");	
	lattice_one.init_lattice_one();
	srand(time(NULL));		
	for (int i=0;i<steps;i++){
		step_sys(lattice_one);
		fout<< i << "," << lattice_one.spin() << endl;		
	}	
	fout.close();	

	return 0;	
}
