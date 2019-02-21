/*
* MetroSim.cpp
* Implementation file for MetroSim
* Alyssa Rose
* Comp15 HW3
* 18-Feb-2019
*/

#include "MetroSim.h"
#include <iostream>
#include <fstream>
#include <vector>

MetroSim::MetroSim(){
	numPass = 1;
	currStat = 0;
	dir = 1;
}

MetroSim::~MetroSim(){

}


// Function: read_stat(ifstream& infile)
// Input: text file
// Return: nothing
// Does: reads stat file into structs
void MetroSim::read_stat(ifstream& infile){
	string statName = "";
	int count = 1;
	while (getline(infile, statName)) {
		Station s;
		s.name = statName;
		s.id = count;
		stat.push_back(s);
		count++;
	}
	currStat = 1;
}


// Function: print_map()
// Input: nothing
// Return: nothing
// Does: prints the structs of the stations
// and the passengers
void MetroSim::print_map(){
	print_train();
	for (int i = 0; i < stat.size(); i++){
		if (currStat == i + 1)
			cout << "TRAIN: ";
		else {
			cout << "       ";
		}
		cout << "[" << i + 1 << "] " <<
		stat[i].name << " ";
		if (((stat[i]).pass).size() == 0)
			cout << "{}" << endl;
		else {
			for (int j = 0; j < ((stat[i]).pass).size(); j++){
				if (i == 0)
					cout << "{";
				cout << "[" << ((stat[i]).pass[j]).id << ", " << ((stat[i]).pass[j]).arrive <<
				"->" << ((stat[i]).pass[j]).depart << "]";
				if (i == ((stat[i]).pass).size() - 1)
					cout << "}" << endl;
			}
		}
	}
}


// Function: command(string comm)
// Input: string containing the command
// Return: nothing
// Does: calls helper functions for all the possible commands
void MetroSim::command(char* two){
	ostream outfile;
	outfile.open(two);
	cout << "Command : ";
	cin >> comm;
	while (comm != "m f"){
		cout << "Command : ";
		cin >> comm;
		if (comm == "m m")
			move_train(outfile);

		if (comm[0] == 'p'){
			Passenger p;
			p.id = numPass;
			p.arrive = comm[2] - '0';
			p.depart = comm[4] - '0';
			((stat[(p.arrive) - 1]).pass).push_back(p);
			numPass++;
		}

		if (comm[0] == 'f'){
			outfile.close();
			ostream outfile;
			string passFile;
			passFile = comm.substr(2, comm.length());
			outfile.open(passFile);
			if (!outfile.is_open()){
				cerr << "Could not open file " << outfile << endl;
				return;
			}
		}
		print_map();
	}
}
void MetroSim::commandFile(char* two, char* three){
	ostream outfile;
	outfile.open(two);

	ifstream commFile;
	commFile.open(three);
	string comm;

	string comm = getline(commFile, comm);

	while ((getline(commFile, comm) and (comm != "m f")){
		comm = getline(commFile, comm);

		if (comm == "m m") 
			move_train(outfile);

		if (comm[0] == 'p'){
			Passenger p;
			p.id = numPass;
			p.arrive = comm[2] - '0';
			p.depart = comm[4] - '0';
			((stat[(p.arrive) - 1]).pass).push_back(p);
			numPass++;
		}

		if (comm[0] == 'f'){
			outfile.close();
			ostream outfile;
			string passFile;
			passFile = comm.substr(2, comm.length());
			outfile.open(passFile);
			if (!outfile.is_open()){
				cerr << "Could not open file " << outfile << endl;
				return;
			}
		}
		print_map();
	}
}




// Function: move_train()
// Input: none
// Return: nothing
// Does: function to handle passenger info if the train moves
void MetroSim::move_train(ostream& out){
	// checking if passengers need to be put into
	// the train vector
	int k = (stat[currStat - 1].pass).size();
	if (k != 0) {
		for (int i = k; i > 0; i--){
			Passenger m = stat[currStat - 1].pass[i];
			(stat[currStat - 1].pass).pop_back();
			train.push_back(m);
		}
	}
	if ((currStat == 0) or (currStat == stat.size()))
		dir *= -1;
	if (dir == 1)
		currStat++;
	if (dir == -1)
		currStat--;
	if (train.size() != 0){
		for (int i = 0; i < train.size(); i++){ 
			Passenger p = train[i];
			if (p.depart == currStat){
				out << "Passenger " << p.id << "left train at station " << p.depart << '\n';
				train.erase(train.begin() + i);
			}
		}
	}
}

// Function: print_train()
// Input: none
// Return: none
// Does: helper function for print_map()
void MetroSim::print_train(){
	cout << "Passengers on the train: ";
	if (train.size() == 0)
		cout << "{}" << endl;
	for (int i = 0; i < train.size(); i++){
		if (i == 0)
			cout << "{";
		cout << "[" << (train[i]).id << ", " << (train[i]).arrive <<
		"->" << (train[i]).depart << "]";
		if (i == (train.size() - 1))
			cout << "}" << endl;
	}
}
