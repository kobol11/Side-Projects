//OOP244 Final Project
// File Item.cpp
// Version 1.0
// Date 19th March, 2017
// Author Bolarinwa Komolafe Email:bkomolafe@myseneca.ca
// Description
// This file contains implementation for the Item Class functions 

#define _CRT_SECURE_NO_WARNINGS  
// Lib includes
#include <iostream>
#include <cstring>
#include <string>

// inlcude Item and POS header files
#include "Item.h"

using namespace std;
namespace ict{
  // class Item implementaion





	void Item::reusedCode(const Item & src)
	{
		this->m_price = src.m_price;
		this->m_quantity = src.m_quantity;
		this->m_taxed = src.m_taxed;
		strcpy(m_sku, src.m_sku);
		if (src.m_name != nullptr)
		{
			this->m_name = new char[strlen(src.m_name) + 1];
			strcpy(this->m_name, src.m_name);
		}
		else
		{
			this->m_name = nullptr;
		}
	}

	Item::Item()
	{
		m_sku[0] = '\0';
		m_name = nullptr;
		m_price = 0;
		m_taxed = true;
		m_quantity = 0;
	}

	Item::Item(const char * p_sku, const char * p_name, double p_price, bool p_taxStatus)
	{
		int k;
		for ( k = 0; k <= (MAX_SKU_LEN - 1); k++)
		{
			if (p_sku[k] != '\0')
			{
				m_sku[k] = p_sku[k];
			}
			else
			{
				m_sku[k] = '\0';
				break;
			}
		}
		if (k == MAX_SKU_LEN)
		{
			m_sku[MAX_SKU_LEN] = '\0';
		}
		m_name = new char[(strlen(p_name)) + 1];
		strcpy(m_name, p_name);
		m_quantity = 0;
		m_price = p_price;
		m_taxed = p_taxStatus;
	}
	Item::~Item()
	{
		delete[] m_name;
	}
	Item::Item(const Item & src)
	{
		this->reusedCode(src);
	}
	Item & Item::operator=(const Item & src)
	{
		if (this != &src)
		{
			delete[] m_name;
			this->reusedCode(src);
		}
		else if (src.m_sku[0] == '\0' && src.m_price == 0 && src.m_quantity == 0 )
		{
			;
		}
		// TODO: insert return statement here
		return *this;
	}
	void Item::sku(const char* src)
	{
		strcpy(this->m_sku, src);
	}
	void Item::price(double cost)
	{
		this->m_price = cost;
	}
	void Item::name(const char * src)
	{
		m_name = new char[strlen(src) + 1];
		strcpy(this->m_name, src);
	}
	void Item::taxed(bool src)
	{
		this->m_taxed = src;
	}
	void Item::quantity(int src)
	{
		this->m_quantity = src;
	}
	const char * Item::sku() const
	{
		return this->m_sku;
	}
	double Item::price() const
	{

		return this->m_price;
	}
	const char * Item::name() const
	{
		return m_name;
	}
	bool Item::taxed() const
	{
		return this->m_taxed;
	}
	int Item::quantity() const
	{
		return this->m_quantity;
	}
	double Item::cost() const
	{
		double value = m_price;
		if (this->m_taxed)
		{
			value = (m_price * TAX + m_price);
		}
		return value;
	}
	bool Item::isEmpty() const
	{
		bool state = false;
		if (this->m_sku == '\0' && this->m_price == 0 && this->m_quantity == 0)
		{
			state = true;
		}
		return state;
	}
	bool Item::operator==(const char * src)const
	{
		bool result = false;
		if (strcmp(this->sku(), src) == 0)
		{
			result = true;
		}
		return result;
	}
	int Item::operator+=(int src)
	{
		return (this->m_quantity + src);
	}
	int Item::operator-=(int src)
	{
		return (this->m_quantity - src);
	}
	std::ostream & Item::write(std::ostream & os, bool linear)const
	{
		// TODO: insert return statement here
		return os;
	}
	std::istream & Item::read(std::istream & is)
	{
		// TODO: insert return statement here
		return is;
	}
	std::fstream & Item::save(std::fstream & file) const
	{
		// TODO: insert return statement here
		return file;
	}
	std::fstream & Item::load(std::fstream & file)
	{
		// TODO: insert return statement here
		return file;
	}
	double operator+=(double& value, const Item & src)
	{
		return (value + (src.quantity() * src.price()));
	}

	std::istream & operator >> (std::istream & is, Item & src)
	{
		src.read(is);
		// TODO: insert return statement here
		return is;
	}

	std::ostream & operator<<(std::ostream & os, const Item & src)
	{
	      
		src.write(os);
		// TODO: insert return statement here
		return os;
	}
	
}
