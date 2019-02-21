/*
* main.cpp
* driver for MetroSim (no pun intended)
* Alyssa Rose
* Comp15 HW3
* 18-Feb-2019
*/

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include "MetroSim.h"
using namespace std;

int main(int argc, char* argv[]){
	MetroSim metro;
	int input = argc;
	string one = argv[1];
	string two = argv[2];
	if ((input < 3) or (input > 4)){
		cerr << "Usage: MetroSim stationsFile passFile [commands]" << endl;
		return 0;
	}
	else {
		/**********************************/
		ofstream outfile;
		outfile.open(two);
		ifstream infile1;
		metro.read_stat(infile1);
		metro.passFile = outfile;
		/**************************************/
		string comm = "h h";
		while ((comm[0] != "m") and (comm[2]) != "f"){
			if (argv[3] == NULL){
				cout << "Command : ";
				cin >> comm;


				/************************************/
				if (comm[0] == 'f'){
					(metro.passFile).close()
					ofstream out2;
					outFile = comm.substr(2, comm.length());
					out2.open(outFile);
					if (!out2.is_open()){
						cerr << "Could not open file " << outFile << endl;
						return;
					}
					metro.passFile = out2;
					/***********************************/

					else{
						metro.command(comm);
					}
				}

				if (argv[3] != NULL){
				/**********************************/
					comm = getline(argv[3], comm);

					if (comm[0] == 'f'){
						(metro.passFile).close()
						ofstream out2;
						outFile = comm.substr(2, comm.length());
						out2.open(outFile);
						if (!out2.is_open()){
							cerr << "Could not open file " << outFile << endl;
							return;
						}
						metro.passFile = out2;
						else {
							metro.command(comm);
						}
					}
				}
				cout << "Thanks for playing MetroSim. Have a nice day!" << endl;
			}
			return 0;
		}
