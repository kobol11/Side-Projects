// OOP345 Workshop 2
// File Stations.h
// Version 1.0
// Date 28th May, 2017
// Author Bolarinwa Komolafe, Email:bkomolafe@myseneca.ca, Student ID:122948169
// Description
// This file contains the definition for the Stations class


#ifndef _STATIONS_H_
#define _STATIONS_H_

#include <iostream>
#include <string>
#include "Station.h"

using namespace std;

namespace w2 { 

class Stations {

	Station* station; // Pointer to the stations being monitored

public:

	Stations(const char*); 
	void update() const; // It accepts the number of passes sold and updates the data for each station in turn
	void restock() const;// It accepts the number of passes added and updates the data for each station in turn
	void report() const; // It reports the number of passes currently available at each station
	~Stations();
};
}

#endif