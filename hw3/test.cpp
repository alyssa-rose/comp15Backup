/*
* test.cpp
* unit testing file for MetroSim
* Alyssa Rose
* Comp15 HW3
* 18-February-2019
*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "MetroSim.h"
using namespace std;

void read_stat_unit_test();
void print_train_unit_test();
void command_unit_test();
void commFile_unit_test();

int main(){
	read_stat_unit_test();
	print_train_unit_test();
	command_unit_test();
	commFile_unit_test();
}

// checks if stations are read in correctly
// no apparent edge cases 
void read_stat_unit_test(){
	ifstream in;
	in.open("stations.txt");

	read_stat(in);
	if (stat[2].name != "Riverway")
		cerr << "3rd station should be Riverway" << endl;
	if (stat[4].id != 4)
		cerr << "4th station's id should be 4" << endl;
}

// checks if print train func works
// no apparent edge cases
void print_train_unit_test(){
	Passenger a, b, c;
	a.id = 1;
	b.id = 2;
	c.id = 3;

	a.arrive = 1;
	a.depart = 5;

	b.arrive = 3;
	b.depart = 4;

	c.arrive = 2;
	c.depart = 7;

	train.push_back(a);
	train.push_back(b);
	train.push_back(c);

	//temporarily change print_train to output a string
	if (print_train() != "Passengers on the train: {[1, 1->5][2, 3->4][3, 2->7]}")
		cerr << "Print train doesn't match expectation" << endl;
}

void command_unit_test(){
	
}
