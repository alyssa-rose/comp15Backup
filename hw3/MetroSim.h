/*
* MetroSim.h
* header file for MetroSim
* Alyssa Rose
* Comp15 HW3
* 18-February-2019
*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

#ifndef _METROSIM_H_
#define _METROSIM_H_

struct Passenger
{
	int arrive;
	int depart;
	int id;
};

struct Station
{
	int id;
	string name;
	vector<Passenger> pass;
};

class MetroSim{
	public:
		MetroSim();
		~MetroSim();
		// name of the passfile, updated if f command
		// used
		string passFile;
	private:

		//vector of all the stations
		vector<Station> stat;
		// vector to keep track of the passengers
		// on the train
		vector<Passenger> train;

		// reads in the station names
		void read_stat(ifstream& infile);

		// writes to the outfile
		void out_file(ostream& out, Passenger p);

		// prints out the current map
		void print_map();

		//helper func for print_map()
		void print_train();

		// handles commands in modular way
		void command(string comm);

		// will deal with passFile
		void move_train();

		// keeping track for pass id #
		int numPass;
		// determines current station train
		// is at
		int currStat;
		// keeps track of train direction
		int dir;
};

#endif
