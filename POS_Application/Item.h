#ifndef ICT_ITEM_H__
#define ICT_ITEM_H__
#include <fstream>
#include <iostream>
#include "PosIO.h"
#include "POS.h"
// inlcude PosIO and POS header files

namespace ict{
  // class Item

	class Item : public PosIO {
		char m_sku[MAX_SKU_LEN + 1];
		char* m_name;
		double m_price;
		bool m_taxed;
		int m_quantity;
		void reusedCode(const Item& src);
	public:
		Item();
		Item(const char* p_sku, const char* p_name, double p_price, bool p_taxStatus = true);
		~Item();
		Item(const Item& src);
		Item& operator=(const Item& src);
		void sku(const char* src);
		void price(double cost);
		void name(const char* src);
		void taxed(bool src);
		void quantity(int src);
		const char* sku()const;
		double price()const;
		const char* name()const;
		bool taxed()const;
		int quantity()const;
		double cost()const;
		bool isEmpty()const;
		bool operator==(const char* src)const;
		int operator+=(int src);
		int operator-=(int src);
		virtual std::ostream& write(std::ostream& os, bool linear = true)const;
		virtual std::istream& read(std::istream& is);
		virtual std::fstream& save(std::fstream& file) const;
		virtual std::fstream& load(std::fstream& file);
};

	double operator+=(double& value, const Item& src);
	std::istream& operator >> (std::istream& is, Item& src);
	std::ostream& operator<<(std::ostream& os, const Item& src);







  // end class Item
  // operator += 
 // double operator+=(double& d, const Item& I);
  // operator << and operator >>
}


#endif