// OOP244 Final Project
// File Date.h
// Version 1.0
// Date 13th March, 2017
// Author Bolarinwa Komolafe Email:bkomolafe@myseneca.ca
// Description
// This file contains the Date class definiton
// The Date class encapsulates a single date and time value in the form of five integers: year, month, day, hour and minute




// compilation safegaurds
#ifndef ICT_DATE_H_
#define ICT_DATE_H_



#include <iostream>
// ict namespace 
namespace ict {
   // Date defined Error values
#define NO_ERROR     0
#define CIN_FAILED   1
#define YEAR_ERROR   2
#define MON_ERROR    3
#define DAY_ERROR    4
#define HOUR_ERROR   5
#define MIN_ERROR    6


   class Date {
   private:
      // member variables
	   int m_year;
	   int m_mon;
	   int m_day;
	   int m_hour;
	   int m_min;
	   int m_readErrorCode;
	   bool m_dateOnly;

     // private methods
      int value()const;


   public:
      // constructors
	   Date();
	   Date(int, int, int);
	   Date(int, int, int, int, int = 0);

      void set();
      // operator overloads
	  bool operator==(const Date&);
	  bool operator!=(const Date&);
	  bool operator<(const Date&);
	  bool operator>(const Date&);
	  bool operator<=(const Date&);
	  bool operator>=(const Date&);
      // methods
	  void errCode(int errCode);
	  void set(int, int, int, int, int);
	  int errCode() const;
	  bool bad() const;
	  bool dateOnly() const;
	  void dateOnly(bool);

      int mdays()const;

      // istream  and ostream read and write methods
	  std::istream& read(std::istream& is = std::cin);
	  std::ostream& write(std::ostream& ostr = std::cout) const;

   };
   // operator<< and >> overload prototypes for cout and cin
   std::istream& operator>>(std::istream& is,  Date& D);
   std::ostream& operator<<(std::ostream& os, const Date& D);
}
#endif // !ICT_DATE_H_