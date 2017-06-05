// OOP345 Workshop 2
// File Station.h
// Version 1.0
// Date 28th May, 2017
// Author Bolarinwa Komolafe, Email:bkomolafe@myseneca.ca, Student ID:122948169
// Description
// This file contains the definition for the Station class

#ifndef _STATION_H_
#define _STATION_H_

#include <iostream>
#include <string>

using namespace std;
namespace w2 { 
class Station {
	std::string m_stationName; // This variable stores the name of the station
	unsigned int m_noOfStudentPass; // This variable holds the number of student passes
	unsigned int m_noOfAdultPasses; // This variable holds the number of adult passes

public:
	Station(); // Default constructor for the Staion class
	void set(const std::string&, unsigned, unsigned); // It sets the instance variables to the values received in its parameters
	enum PassType {STUDENT, ADULT}; // It holds the type of Pass
	void update(PassType, int); // It updates the number of passes
	unsigned inStock(PassType); // It returns the number of passes of the requested type
	const std::string& getName(); // It returns a reference to a String object holding the name of the station

}
;
}

#endif
