// OOP345 Workshop 2
// File Station.cpp
// Version 1.0
// Date 28th May, 2017
// Author Bolarinwa Komolafe, Email:bkomolafe@myseneca.ca, Student ID:122948169
// Description
// This file contains the definition for the functions in Station class

#include "Station.h"
#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>

using namespace std;

namespace w2 { 

Station::Station()
{
	m_stationName = "Yet to be specified";
	m_noOfAdultPasses = 0;
	m_noOfStudentPass = 0;
}

void Station::set(const std::string & name, unsigned studentPass, unsigned adultPass)
{
	m_stationName = name;
	m_noOfStudentPass = studentPass;
	m_noOfAdultPasses = adultPass;
}

void Station::update(PassType pass, int no)
{
	unsigned int change;
	if (pass == STUDENT)
	{
		if (no < 0)
		{
			change = abs(no);
			m_noOfStudentPass -= change;
		}
		else
			m_noOfStudentPass += no;
		
	}
	else
	{
		if (no < 0)
		{
			change = abs(no);
			m_noOfAdultPasses -= change;
		}
		else
		m_noOfAdultPasses += no;
	}
		
}

unsigned Station::inStock(PassType pass)
{
	unsigned int output;
	if (pass == STUDENT)
	{
		output = this->m_noOfStudentPass;
	}
	else
	{
		output = this->m_noOfAdultPasses;
	}
	return output;
}

const std::string & Station::getName()
{
	// TODO: insert return statement here
	return this->m_stationName;
}
}