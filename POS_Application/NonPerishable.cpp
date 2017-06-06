#define _CRT_SECURE_NO_WARNINGS
// lib includes
#include <cstring>
#include <iostream>
#include <string>
#include "NonPerishable.h"
#include "Item.h"

using namespace std;

namespace ict {
	bool NonPerishable::ok() const
	{
		return (m_err.isClear());
	}
	void NonPerishable::error(const char * message)
	{
		m_err.message(message);
	}
	char NonPerishable::signature() const
	{
		return 'N';
	}
	std::fstream & NonPerishable::save(std::fstream & file) const
	{
		file << this->signature() << "," << this->sku() << "," << this->name() << ","
			<< this->price() << "," << this->taxed() << "," << this->quantity();
		// TODO: insert return statement here
		return file;
	}
	std::fstream & NonPerishable::load(std::fstream & file)
	{
		
		char sku[MAX_SKU_LEN + 1];
		char* nameStore;
		string name;
		char c1, c2;
		int quantity;
		double price;
		bool taxStatus;
		file.getline(sku, (MAX_SKU_LEN + 1), ',');
		getline(file, name, ',');
		file >> price >> c1 >> taxStatus >> c2 >> quantity;
		nameStore = new char[name.length() + 1];
		strcpy(nameStore, name.c_str());
		this->sku(sku);
		this->name(nameStore);
		this->price(price);
		this->taxed(taxStatus);
		this->quantity(quantity);
		// TODO: insert return statement here
		return file;
	}
	std::ostream & NonPerishable::write(std::ostream & ostr, bool linear) const
	{
		if (!this->ok()) {
			ostr << (const char*)m_err;
		}
		else
		{
			if (linear)
			{
				ostr.width(MAX_SKU_LEN);
				ostr.setf(ios::left);
				ostr << this->sku() << '|';
				ostr.width(20);
				ostr << this->name() << '|';
				ostr.width(7);
				ostr.setf(ios::fixed);
				ostr.setf(ios::right);
				ostr.precision(2);
				ostr << this->price() << '|' << " ";
				if (this->taxed())
				{
					ostr << 'T' << this->signature() << '|';
				}
				else {
					ostr << " " << this->signature() << '|';
				}
				ostr.width(4);
				ostr << this->quantity() << '|';
				ostr.width(9);
				ostr << this->cost() * this->quantity() << '|';
				ostr.unsetf(ios::right);
				ostr.unsetf(ios::fixed);
			}
			else
			{
				ostr << "Name:" << endl;
				//ostr.width(80);
				//ostr.setf(ios::left);
				//ostr.fill();
				//ostr.setf(ios::fixed);
				ostr << this->name() << endl;
				ostr << "Sku: "<< this->sku() << endl;
				ostr.setf(ios::fixed);
				ostr.precision(2);
				ostr << "Price: " << this->price() << endl;
				if (this->taxed())
				{
					ostr << "Price after tax: " << this->cost() << endl;
				}
				else
				{
					ostr << "Price after tax: " << "N/A" << endl;
				}
				ostr << "Quantity: " << this->quantity() << endl;
				ostr << "Total Cost: " << this->quantity() * this->cost() << endl;
				ostr.unsetf(ios::fixed);
				ostr.unsetf(ios::left);
			}
		}
		// TODO: insert return statement here
		return ostr;
	}
	std::istream & NonPerishable::read(std::istream & is)
	{
		char sku[MAX_SKU_LEN + 1];
		char* nameStore;
		string name;
		//char c1, c2;
		int quantity;
		double price;
		char taxStatus;
		bool taxState;
		bool state = true;
		if (state)
		{
		if (is.fail())
		{
			state = false;
		}
		}
		if (state)
		{
			cout << "Item Entry:" << endl;
			cout << "Sku: ";
			is.getline(sku, (MAX_SKU_LEN + 1), '\n');
			cout << "Name:" << endl;
			getline(is, name, '\n');
			cout << "Price: ";
			is >> price;
			if (is.fail())
			{
				m_err.message("Invalid Price Entry");
				state = false;
			}
			is.ignore(2000, '\n');
		}
		if (state)
		{
			cout << "Taxed: ";
			is.get(taxStatus);
			if (is.fail())
			{
				m_err.message("Invalid Taxed Entry, (y)es or (n)o");
				state = false;
			}
			else if (taxStatus != 'y' && taxStatus != 'Y' && taxStatus != 'n' && taxStatus != 'N')
			{
				is.setstate(ios::failbit);
				m_err.message("Invalid Taxed Entry, (y)es or (n)o");
				state = false;
			}
			is.ignore(2000, '\n');
		}
		if (state)
		{
			cout << "Quantity: ";
			is >> quantity;
			if (is.fail())
			{
				m_err.message("Invalid Quantity Entry");
				state = false;
			}
	
		}
		
		if (state)
		{
			if (taxStatus == 'y' || taxStatus == 'Y')
			{
				taxState = true;
			}
			else
			{
				taxState = false;
			}
			
			nameStore = new char[name.length() + 1];
			strcpy(nameStore, name.c_str());
			this->sku(sku);
			this->name(nameStore);
			this->price(price);
			this->taxed(taxState);
			this->quantity(quantity);
			m_err.clear();
		}
		// TODO: insert return statement here

	
				return is;
	}
}

