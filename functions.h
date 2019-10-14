#include "lattice.cc"
using namespace std;
#include <stdlib.h> 
#include "ctime"
#include "math.h"
#include <fstream>

//print the lattice to file
void print_lattice(Lattice &lattice);

//move the lattice 1 step forward by doing  N^2 systematical spin flips
void step_sys(Lattice &lattice);

//move the lattice 1 step forward by doing  N^2 rnd spin flips
void step_rnd(Lattice &lattice);

//computes the change of energy associated with the change of the spin at position (col, row)
int delta_E(Lattice &lattice, int col,int row);

int sum_adjacent_spins(Lattice &lattice, int row,int col);

double std_dev(double energies[], int n);
