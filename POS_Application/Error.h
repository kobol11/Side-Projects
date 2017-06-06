//OOP244 Final Project
// File Error.h
// Version 1.0
// Date 13th March, 2017
// Author Bolarinwa Komolafe Email:bkomolafe@myseneca.ca
// Description
// The Error class encapsulates error processing using a dynamic C-style string and flag for the error state of other classes

// compilation safegaurds
#ifndef ICT_ERROR_H_
#define ICT_ERROR_H_



#include <iostream>
namespace ict {
   class Error {
      char* m_message;
   public:
   // constructors
	   Error();
	   Error(const char* errorMessage);
	   //Error(const Error& em) = delete;
	   
   // destructor
	   virtual ~Error();
   // deleted constructor and operator=
	   //Error& operator=(const Error& em) = delete;
   // operator= for c-style strings

   // methods
	   void clear();
	   bool isClear() const;
	   void message(const char*);
	   void operator=(const char*);
   // cast overloads
	   operator const char*() const;
	   operator bool() const;
   };
   // operator << overload prototype for cout
   std::ostream& operator<<(std::ostream& os, const Error& e);
}

#endif // !ICT_ERROR_H_
