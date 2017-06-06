//OOP244 Final Project
// File Perishable.h
// Version 1.0
// Date 6th April, 2017
// Author Bolarinwa Komolafe Email:bkomolafe@myseneca.ca
// Description
// Perishable Class is derived from NonPerishable class

#ifndef ICT_PERISHABLE_H__
#define ICT_PERISHABLE_H__
#include "NonPerishable.h"
#include "Date.h"

namespace ict {
	class Perishable : public NonPerishable {
		Date m_expiry;

	protected:
		char signature()const;
		
	public:
		Perishable();
		std::fstream& save(std::fstream& file)const;
		std::fstream& load(std::fstream& file);
		std::ostream& write(std::ostream& os, bool linear)const;
		std::istream& read(std::istream& istr);
	};
}




#endif
