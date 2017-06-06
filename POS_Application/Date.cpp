//OOP244 Final Project
// File Date.cpp
// Version 1.0
// Date 13th March, 2017
// Author Bolarinwa Komolafe Email:bkomolafe@myseneca.ca
// Description
// This file contains the definiton for the Date class functions
// The Date class encapsulates a single date and time value in the form of five integers: year, month, day, hour and minute

#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <ctime>
#include <cstring>

using namespace std;
#include "Date.h"
#include "POS.h"


namespace ict{
	Date::Date()
	{
		m_dateOnly = false;
		set();
		m_readErrorCode = NO_ERROR;
	}
	Date::Date(int year, int mon, int day)
	{
		m_dateOnly = true;
		m_year = year; m_mon = mon; m_day = day;
		m_readErrorCode = NO_ERROR;
	}
	Date::Date(int year, int mon, int day, int hour, int min)
	{
		m_dateOnly = false;
		m_year = year; m_mon = mon; m_day = day; m_hour = hour; m_min = min;
		m_readErrorCode = NO_ERROR;
	}
	void Date::set(){
    time_t t = time(NULL);
    tm lt = *localtime(&t);
    m_day = lt.tm_mday;
    m_mon = lt.tm_mon + 1;
    m_year = lt.tm_year + 1900;
    if (dateOnly()){
      m_hour = m_min = 0;
    }
    else{
      m_hour = lt.tm_hour;
      m_min = lt.tm_min;
    }
  }

	bool Date::operator==(const Date & D)
	{
		bool output = false;
		if (this->value() == D.value())
		{
			output = true;
		}
		return output;
	}

	bool Date::operator!=(const Date & D)
	{
		bool output = false;
		if (this->value() != D.value())
		{
			output = true;
		}
		return output;
	}

	bool Date::operator<(const Date & D)
	{
		bool output = false;
		if (this->value() < D.value())
		{
			output = true;
		}
		return output;
	}

	bool Date::operator>(const Date & D)
	{
		bool output = false;
		if (this->value() > D.value())
		{
			output = true;
		}
		return output;
	}

	bool Date::operator<=(const Date & D)
	{
		bool output = false;
		if (this->value() <= D.value())
		{
			output = true;
		}
		return output;
	}

	bool Date::operator>=(const Date & D)
	{
		bool output = false;
		if (this->value() >= D.value())
		{
			output = true;
		}
		return output;
	}

  int Date::value()const{
    return m_year * 535680 + m_mon * 44640 + m_day * 1440 + m_hour * 60 + m_min;
  }

  int Date::mdays()const{
    int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
    int mon = m_mon >= 1 && m_mon <= 12 ? m_mon : 13;
    mon--;
    return days[mon] + int((mon == 1)*((m_year % 4 == 0) && (m_year % 100 != 0)) || (m_year % 400 == 0));
  }

  std::istream & Date::read(std::istream & is)
  {
	  int year, mon, day, hour, min;
	  char c1, c2, c3, c4;
	  if (this->m_dateOnly)
	  {
		  cin >> year >> c1 >> mon >> c2 >> day;
		   if (is.fail())
		  {
			  this->errCode(1);
		  }
		  else
		  {
			  if (year < 2000 || year > 2030)
			  {
				  this->m_readErrorCode = YEAR_ERROR;
				  this->m_year = year; this->m_mon = mon; this->m_day = day;
			  }
			  else if (mon < 1 || mon > 12)
			  {
				  this->m_readErrorCode = MON_ERROR;
				  this->m_year = year; this->m_mon = mon; this->m_day = day;
			  }
			  else if ((year % 4 == 0) && mon == 2 && (day > 29 || day < 1))
			  {
				  this->m_readErrorCode = DAY_ERROR;
				  this->m_year = year; this->m_mon = mon; this->m_day = day;
			  }
			  else if ((year % 4 != 0) && mon == 2 && (day > 28 || day < 1))
			  {
				  this->m_readErrorCode = DAY_ERROR;
				  this->m_year = year; this->m_mon = mon; this->m_day = day;
			  }
			  else if ((mon == 4 || mon == 6 || mon == 9 || mon == 11) && (day > 30 || day < 1))
			  {
				  this->m_readErrorCode = DAY_ERROR;
				  this->m_year = year; this->m_mon = mon; this->m_day = day;
			  }
			  else if (!(mon == 4 || mon == 6 || mon == 9 || mon == 11) && (day > 31 || day < 1))
			  {
				  this->m_readErrorCode = DAY_ERROR;
				  this->m_year = year; this->m_mon = mon; this->m_day = day;
			  }
			  else
			  {
			     this->m_year = year; this->m_mon = mon; this->m_day = day;
			  }
			  
		  }
	  }
	  else
	  {
		  is >> year >> c1 >> mon >> c2 >> day >> c3 >> hour >> c4 >> min;
		  if (is.fail())
		  {
			  this->m_readErrorCode = CIN_FAILED;
		  }
		  else
		  {
			  if (year < 2000 || year > 2030)
			  {
				  this->m_readErrorCode = YEAR_ERROR;
				  this->m_year = year; this->m_mon = mon; this->m_day = day;
				  this->m_hour = hour; this->m_min = min;
			  }
			  else if (mon < 1 || mon > 12)
			  {
				  this->m_readErrorCode = MON_ERROR;
				  this->m_year = year; this->m_mon = mon; this->m_day = day;
				  this->m_hour = hour; this->m_min = min;
			  }
			  else if ((year % 4 == 0) && mon == 2 && (day > 29 || day < 1))
			  {
				  this->m_readErrorCode = DAY_ERROR;
				  this->m_year = year; this->m_mon = mon; this->m_day = day;
				  this->m_hour = hour; this->m_min = min;
			  }
			  else if ((year % 4 != 0) && mon == 2 && (day > 28 || day < 1))
			  {
				  this->m_readErrorCode = DAY_ERROR;
				  this->m_year = year; this->m_mon = mon; this->m_day = day;
				  this->m_hour = hour; this->m_min = min;
			  }
			  else if ((mon == 4 || mon == 6 || mon == 9 || mon == 11) && (day > 30 || day < 1))
			  {
				  this->m_readErrorCode = DAY_ERROR;
				  this->m_year = year; this->m_mon = mon; this->m_day = day;
				  this->m_hour = hour; this->m_min = min;
			  }
			  else if (!(mon == 4 || mon == 6 || mon == 9 || mon == 11) && (day > 31 || day < 1))
			  {
				  this->m_readErrorCode = DAY_ERROR;
				  this->m_year = year; this->m_mon = mon; this->m_day = day;
				  this->m_hour = hour; this->m_min = min;
			  }
			  else if (hour < 0 || hour > 23)
			  {
				  this->m_readErrorCode = HOUR_ERROR;
				  this->m_year = year; this->m_mon = mon; this->m_day = day;
				  this->m_hour = hour; this->m_min = min;
			  }
			  else if (min < 0 || min > 59)
			  {
				  this->m_readErrorCode = MIN_ERROR;
				  this->m_year = year; this->m_mon = mon; this->m_day = day;
				  this->m_hour = hour; this->m_min = min;
			  }
			  else
			  {
			     this->m_year = year; this->m_mon = mon; this->m_day = day;
			     this->m_hour = hour; this->m_min = min;
			  }

		       
		  }
	  }
	  
	  // TODO: insert return statement here
	  return is;
  }

  std::ostream & Date::write(std::ostream & ostr) const
  {
       if (this->m_dateOnly)
	  {
		 ostr.fill('0');
		 //ostr.width(4);
		  ostr << this->m_year;
		  ostr << '/';
		 ostr.width(2);
		  ostr << this->m_mon;
		  ostr << '/';
		  ostr.width(2);
		  ostr << this->m_day;
	  }
	  else
	  {
		  ostr.fill('0');
		 // ostr.width(4);
		  ostr << this->m_year;
		  ostr << '/';
		  ostr.width(2);
		  ostr << this->m_mon;
		  ostr << '/';
		 ostr.width(2);
		  ostr << this->m_day;
		  ostr << ',' << ' ';
		  ostr.width(2);
		  ostr << this->m_hour;
		  ostr << ':';
		  ostr.width(2);
		  ostr << this->m_min;
	  }
	  // TODO: insert return statement here
	  return ostr;
       
  }


  

  void Date::errCode(int errCode)
  {
	  this->m_readErrorCode = errCode;
  }

  void Date::set(int year, int mon, int day, int hour, int min)
  {
	  this->m_year = year;
	  this->m_mon = mon;
	  this->m_day = day;
	  this->m_hour = hour;
	  this->m_min = min;
	  this->m_readErrorCode = NO_ERROR;
  }

  int Date::errCode() const
  {
	  return m_readErrorCode;
  }

  bool Date::bad() const
  {
	  bool output = false;
	  if (this->m_readErrorCode != 0)
	  {
		  output = true;
	  }
	  return output;
  }

  bool Date::dateOnly() const
  {
	  return this->m_dateOnly;
  }

  void Date::dateOnly(bool value)
  {
	  this->m_dateOnly = value;
	  if (value)
	  {
		  this->m_hour = 0; this->m_min = 0;
	  }
  }

  std::istream & operator>> (std::istream & is, Date& D)
  {
	  D.read(is);
	  // TODO: insert return statement here
	  return is;
  }

  std::ostream & operator<<(std::ostream & os, const Date& D)
  {
	  D.write(os);
	  // TODO: insert return statement here
	  return os;
  }

}
