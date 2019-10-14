#include <iostream>
using namespace std;
#include "functions.h"


void print_lattice(Lattice &lattice){
	ofstream fout;	
	fout.open("print");	
	int N=lattice.size();
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){			 
			if (lattice(i,j)==1) fout<<1;
			else fout<<0;
		}
		fout<<'\n' ;
	}
	fout.close();
}


//NOT used
int delta_E(Lattice &lattice, int row,int col){	
	short int sum_spins=lattice(row-1,col) + lattice(row+1,col) + lattice(row,col-1) + lattice(row,col+1);
	return sum_spins*2*lattice(row,col); // add *2 ???
}

int sum_adjacent_spins(Lattice &lattice, int row,int col){
	return (lattice(row-1,col) + lattice(row+1,col) + lattice(row,col-1) + lattice(row,col+1));
}


void step_sys(Lattice &lattice){
	int N=lattice.size();
	double H=lattice.field_strength();
	double exp, dE, p;
	int sum_spins, spin;
	//walk through the lattice systematically row by row
	for (int row=0;row<N;row++){
		for(int col=0;col<N;col++){
			
			spin=lattice(row,col);
			sum_spins=sum_adjacent_spins(lattice,row,col);			
			dE = 2 * spin * (H + sum_spins);
						
			if (dE<=0){
				lattice.flip_spin(row,col);
				lattice.change_E(dE);
			}
			else{
				if (spin==1){
					//first 5 elements correspons to + spin
					exp=lattice.exp_i((int) sum_spins/2+2);					
				}else{
					//last 5 elements correspons to - spin
					exp=lattice.exp_i((int) sum_spins/2+7);							
				}				
				
				p=(double) rand()/(RAND_MAX);					
				if(exp>p) {
					lattice.flip_spin(row,col);
					lattice.change_E(dE); 
				}
			}				
		}
	}
}


//NOT up to date!!!
void step_rnd(Lattice &lattice){
	int N=lattice.size();
	double T=lattice.temperature();	
	double p;
	int dE, col, row;
	
	for (long int i=0;i<(N*N);i++){
		col = (int) (((double) rand()/RAND_MAX)*N); 
		row = (int) (((double) rand()/RAND_MAX)*N);
		
		
		dE=delta_E(lattice,row,col);			
		
		if (dE<0) lattice.flip_spin(row,col);
		else{
			p=(double) rand()/(RAND_MAX);				
			if(exp(-dE/T)>p) lattice.flip_spin(row,col); // !!!
		}		
	}	
}


double std_dev(double energies[], int n){
	//TODO: consider using long int instead of double
	double mean=0.0;
	double mean_sqr=0.0;
	double E;
	for (int i=0;i<n;i++){
		E=energies[i];
		mean+=E;
		mean_sqr+=E*E;
	}
	mean = mean/n;
	mean_sqr=mean_sqr/n;
	
	return mean_sqr-mean*mean;	
}



