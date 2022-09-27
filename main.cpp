// =================================================================
//
// File: main.cpp
// Author: Erik Cabrera
// Date: septiembre 2022
//
// =================================================================
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Barco.h"
#include "bubbleSort.h"

using namespace std;

int main(int argc, char *argv[]){
	ifstream inFile;
	ofstream outFile;
// Si no existen archivos salir
	inFile.open(argv[1]);
	if (inFile.fail())
		return -1;

	outFile.open(argv[2]);
	if (outFile.fail())
		return -1;
// Vector barcos
	int numBarcos = 0;
	string prefix = "";
	inFile >> numBarcos >> prefix;

	vector<Barco *> barcos(numBarcos);

	string date, hour, entry, UBI;

	for (int i = 0; i < numBarcos; i++){
		inFile >> date >> hour >> entry >> UBI;
		barcos[i] = new Barco(date, hour, entry, UBI);
	}
// Filtramos barcos
	vector<Barco *> filteredVector;

	for (int i = 0; i < numBarcos; i++){
		if (barcos[i]->UBI.substr(0, 3) == prefix)
			filteredVector.push_back(barcos[i]);
	}
// Utilizamos bubble sort
	bubbleSort(filteredVector);
// Imprimimos
	for (int i = 0; i < filteredVector.size(); i++){
		outFile << *(filteredVector[i]) << endl;
	}
// Cerramos archivos
	inFile.close();
	outFile.close();
}
