#include <iostream>
using namespace std;
#include <fstream>
#include "functions.h"

int main(){
	
	int steps,N;
	double T,H;
	int init_lattice;
	
	cout<<"Input,N , no. steps,  T, H, initial lattice: 1-rnd, 2-half,3-ones"<<endl;
	cin >> N >> steps >> T >> H>>init_lattice;
	
	Lattice lattice(N,T,H);
	//initialize latice
	if (init_lattice==1) lattice.init_lattice_rnd();
	if (init_lattice==2) lattice.init_lattice_half();
	if (init_lattice==3) lattice.init_lattice_one();
	
	//use to rescale energy values in the range -1 to 0. 
	//Works only if the initial lattice is homogeneous
	int E_0= - lattice.energy(); 
	
	//write data in file
	ofstream fout;	
	fout.open("data_ising_model");	
	
	//Seeding only once in order to preserve the uniform distribution of the rand function
	srand(time(NULL));	
	
	for (int i=0;i<steps;i++){		
		step_sys(lattice);		
		fout<< i << "," << lattice.magnetisation() <<","<<lattice.energy()/E_0<< endl;		
		print_lattice(lattice);
	}	
	fout.close();
	
	//print the final state of the lattice to file
	print_lattice(lattice);
		
	lattice.deleteCells(); 
		
	return 0;	
}
