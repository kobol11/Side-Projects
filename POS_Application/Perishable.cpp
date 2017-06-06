#define _CRT_SECURE_NO_WARNINGS
// lib includes
#include <iostream>
#include <cstring>
#include <string>





#include "Perishable.h"
using namespace std;

char ict::Perishable::signature() const
{
	return 'P';
}

ict::Perishable::Perishable()
{
	m_expiry.dateOnly(true);
}

std::fstream & ict::Perishable::save(std::fstream & file) const
{
	NonPerishable::save(file);
	file << ',' << m_expiry;
	// TODO: insert return statement here
	return file;
}

std::fstream & ict::Perishable::load(std::fstream & file)
{
	
		NonPerishable::load(file);
		char c1, c2, c3;
		int year, month, day;
		file >> c1 >> year >> c2 >> month >> c3 >> day;
		m_expiry.set(year, month, day, 0, 0);
	
	// TODO: insert return statement here
	return file;
}

std::ostream & ict::Perishable::write(std::ostream & os, bool linear) const
{
	NonPerishable::write(os, linear);
	if (this->ok() && linear == false)
	{
		os << "Expiry date: " << m_expiry << endl;
	}
	// TODO: insert return statement here
	return os;
}

std::istream & ict::Perishable::read(std::istream & istr)
{
	cout << "Perishable ";
	NonPerishable::read(istr);
	if (!istr.fail())
	{
		cout << "Expiry date (YYYY/MM/DD): ";
		istr >> m_expiry;
			if (m_expiry.errCode() == CIN_FAILED)
			{
				this->error("Invalid Date Entry");
				istr.setstate(ios::failbit);
			}
			if (m_expiry.errCode() == YEAR_ERROR)
			{
				this->error("Invalid Year in Date Entry");
				istr.setstate(ios::failbit);
			}
			if (m_expiry.errCode() == MON_ERROR)
			{
				this->error("Invalid Month in Date Entry");
				istr.setstate(ios::failbit);
			}
			if (m_expiry.errCode() == DAY_ERROR)
			{
				this->error("Invalid Day in Date Entry");
				istr.setstate(ios::failbit);
			}
			
	}
	
	if (istr.fail())
	{
		m_expiry.errCode(NO_ERROR);
	}
	
	// TODO: insert return statement here
	return istr;
}

