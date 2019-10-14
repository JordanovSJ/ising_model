CFLAGS = -ansi -g -Wall
#~ LDIR =	-L /usr/lib
LIBS   =	-l stdc++ -lm 

#~ 

CXX = g++

ising_model: ising_model.o lattice.o functions.o 
				$(CXX) $(CFLAGS) $(LIBS) ising_model.o  functions.o lattice.o -o ising_model

test: test.o lattice.o functions.o 
				$(CXX) $(CFLAGS) $(LIBS) test.o  functions.o lattice.o -o	test
				
task_1: task_1.o lattice.o functions.o 
				$(CXX) $(CFLAGS) $(LIBS) task_1.o  functions.o lattice.o -o	task_1		

task_2: task_2.o lattice.o functions.o 
				$(CXX) $(CFLAGS) $(LIBS) task_2.o  functions.o lattice.o -o	task_2						

task_3: task_3.o lattice.o functions.o 
				$(CXX) $(CFLAGS) $(LIBS) task_3.o  functions.o lattice.o -o	task_3		
				

%.o: %.cc
				$(CXX) $(CFLAGS)		$< -c -o $@
%: %.cc Makefile
				$(CXX) $(CFLAGS) $(LIBS) $< -o $@

