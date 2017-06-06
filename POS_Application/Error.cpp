#define _CRT_SECURE_NO_WARNINGS 

#include <cstring>
#include <string>
#include <iostream>
#include "Error.h"

using namespace std;
namespace ict{
	Error::Error()
	{
		m_message = nullptr;
	}
	Error::Error(const char * errorMessage)
	{
		m_message = nullptr;
		message(errorMessage);

	}
	Error::~Error()
	{
		delete [] m_message;
	}
	void Error::clear()
	{
		delete [] m_message;
		m_message = nullptr;
	}
	bool Error::isClear() const
	{
		bool output = false;
		if (this->m_message == nullptr)
		{
			output = true;
		}
		return output;
	}
	void Error::message(const char * value)
	{
		this->clear();
		this->m_message = new char[strlen(value) + 1];
		std::strcpy(this->m_message, value);
	}
	void Error::operator=(const char * errorMessage)
	{
		this->clear();
		this->message(errorMessage);
	}
	Error::operator const char*() const
	{
		return m_message;
	}
	Error::operator bool() const
	{
		bool output = false;
		if (this->m_message == nullptr)
		{
			output = true;
		}
		return output;
	}
	std::ostream & operator<<(std::ostream & os, const Error& e)
	{
		if (!e.isClear())
	      
		{
			os << (const char*)e;
		}
		// TODO: insert return statement here
		return os;
	}
}

