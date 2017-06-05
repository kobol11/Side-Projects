// OOP345 Workshop 2
// File Stations.cpp
// Version 1.0
// Date 28th May, 2017
// Author Bolarinwa Komolafe, Email:bkomolafe@myseneca.ca, Student ID:122948169
// Description
// This file contains the definition for the functions in Stations class

#include <iostream>
#include <fstream>
#include <string>
#include "Stations.h"

using namespace std;
namespace w2 { 
	string fileName; // Name of the file that contains the stations being monitored
unsigned int noOfStations; // Number of stations on the file
Stations::Stations(const char * file)
{
	fileName = file;
	string stationName;
	unsigned int adultPass, studentPass;
	char delimiter;
	std::ifstream fin(file);
	fin >> noOfStations;
	if (fin.fail())
	{
		fin.clear();
	}
	fin.get(delimiter);
	fin.ignore(2000, '\n');
	station = new Station[noOfStations];
	for (unsigned int i = 0; i < noOfStations; i++)
	{
		getline(fin, stationName, ';');
		fin >> studentPass >> adultPass;
		fin.ignore(2000, '\n');
		station[i].set(stationName, studentPass, adultPass);
	}
	fin.close();
}

void Stations::update() const
{
	int studentPass, adultPass;
	cout << "Passes Sold :" << endl;
	int format = strlen("Passes Sold :");
	for (int i = 0; i < format; i++)
	{
		cout << "-";
	}
	cout << endl;
	for (unsigned int i = 0; i < noOfStations; i++)
	{
		cout << (station[i].getName()).c_str() << endl;
		cout << " "<< "Student Passes sold : ";
		cin >> studentPass;
		station[i].update(w2::Station::PassType::STUDENT, -1 * studentPass);
		cout << " " << "Adult   Passes sold : ";
		cin >> adultPass;
		station[i].update(w2::Station::PassType::ADULT, -1 * adultPass);
	}
}

void Stations::restock() const
{
	int studentPass, adultPass;
	cout << endl;
	cout << "Passes Added :" << endl;
	int format = strlen("Passes Added :");
	for (int i = 0; i < format; i++)
	{
		cout << "-";
	}
	cout << endl;
	for (unsigned int i = 0; i < noOfStations; i++)
	{
		cout << (station[i].getName()).c_str() << endl;
		cout << " " << "Student Passes added : ";
		cin >> studentPass;
		station[i].update(w2::Station::PassType::STUDENT, studentPass);
		cout << " " << "Adult   Passes added : ";
		cin >> adultPass;
		station[i].update(w2::Station::PassType::ADULT, adultPass);
	}
}

void Stations::report() const
{
	cout << endl;
	cout << "Passes in Stock : Student Adult" << endl;
	int format = strlen("Passes in Stock : Student Adult");
	for (int i = 0; i < format; i++)
	{
		cout << "-";
	}
	cout << endl;
	for (unsigned int i = 0; i < noOfStations; i++)
	{
		cout << (station[i].getName()).c_str();
		int width1 = strlen("Passes in Stock : Student") - strlen((station[i].getName()).c_str()); // This width is required for the formatting of the output
		cout.width(width1);
		cout << station[i].inStock(Station::PassType::STUDENT);
		cout.width(6);
		cout << station[i].inStock(Station::PassType::ADULT) << endl;
	}
}

Stations::~Stations()
{
	std::ofstream fout(fileName, std::ios::out|std::ios::trunc);
	fout << noOfStations << ";" << endl;
	for (unsigned int i = 0; i < noOfStations; i++)
	{
		fout << (station[i].getName()).c_str();
		fout << ";" << station[i].inStock(Station::PassType::STUDENT)
			<< " "
			<< station[i].inStock(Station::PassType::ADULT) << endl;
	}
	fout.close();
	delete[] station;
	station = nullptr;
}

}