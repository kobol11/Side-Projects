//OOP244 Final Project
// File PosIO.h
// Version 1.0
// Date 19th March, 2017
// Author Bolarinwa Komolafe Email:bkomolafe@myseneca.ca
// Description
// The PosIO class enforces inherited class to implement functions that work with fstream and iostream objects

#ifndef ICT_POSIO_H__
#define ICT_POSIO_H__
// includes go here
#include <fstream>

// ict namespace
namespace ict {
	class PosIO {
	public:
		// pure virutal methods go here
		virtual std::fstream& save(std::fstream& file) const = 0;
		virtual std::fstream& load(std::fstream& file) = 0;
		virtual std::ostream& write(std::ostream& os, bool linear) const = 0;
		virtual std::istream& read(std::istream& is) = 0;
	};
}
  


#endif