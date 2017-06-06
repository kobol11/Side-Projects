//OOP244 Final Project
// File NonPerishable.h
// Version 1.0
// Date 6th April, 2017
// Author Bolarinwa Komolafe Email:bkomolafe@myseneca.ca
// Description
// NonPerishable class is derived from an Item Class

#ifndef ICT_NONPERISHABLE_H__
#define ICT_NONPERISHABLE_H__
#include "Item.h"
#include "Error.h"

namespace ict {
	class NonPerishable : public Item {
		Error m_err;

	protected:
		bool ok()const;
		void error(const char* message);
		virtual char signature()const;

	public:
		//using Item::Item;
	     std::fstream& save(std::fstream& file)const;
		 std::fstream& load(std::fstream& file);
		 std::ostream& write(std::ostream& ostr, bool linear)const;
		 std::istream& read(std::istream& is);
	};
}






#endif