/*
* main.cpp
* driver for MetroSim (no pun intended)
* Alyssa Rose
* Comp15 HW3
* 18-Feb-2019
*/

#include <iostream>
#include <fstream>
#include <string>
#include "MetroSim.h"
using namespace std;

int main(int argc, char* argv[]){
	MetroSim metro;
	if ((argc < 3) or (argc > 4)){
		cerr << "Usage: MetroSim stationsFile passFile [commands]" << endl;
		return 0;
	}
	else {
		string comm;
		metro.passFile = argv[2];
		metro.read_stat(argv[1]);

		while (argv[3] != "m f"){
			if (argv[3] == NULL){
				cout << "Command : ";
				cin >> comm;
				metro.command(comm);
			}
			if (argv[3] != NULL){
				comm = getline(argv[3], comm);
				metro.command(comm);
			}

		}

	}
	return 0;
}
