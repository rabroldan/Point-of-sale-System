/*
*****************************************************************************

Full Name  : Ronald Roldan

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<string>
#include <fstream>
#include "POS.h"
#include "Error.h"

using namespace std;
namespace sdds {

	Error::Error()
	{
		m_message = nullptr;
	}

	Error::Error(const char* errors) : m_message(nullptr) {



		if (errors && errors[0] != '\0')
		{

			clear();
			int size = (strlen(errors));
			m_message = new char[size + 1];
			strcpy(m_message, errors);
		}
	}

	Error::Error(const Error& errors) : m_message(nullptr)
	{

		*this = errors;
	}
	Error& Error::clear() {


		delete[] m_message;
		m_message = nullptr;


		return *this;
	}


	Error& Error::operator=(const char* errors)
	{


		if (errors && errors[0] != '\0')
		{
			clear();
			int size = (strlen(errors));
			m_message = new char[size + 1];
			strcpy(m_message, errors);
		}
		return *this;
	}

	Error& Error::operator=(const Error& errors)
	{


		if (this != &errors)
		{
			clear();
			if (errors)
			{
				int size = strlen(errors.m_message);
				m_message = new char[size + 1];
				strcpy(m_message, errors.m_message);
			}
		}
		return *this;
	}

	Error::~Error()
	{



		
		clear();

	}


	Error::operator bool( ) const {

		bool flag3;


		if (this->m_message != nullptr)
		{
			flag3 = true;
		}
		else {
			flag3 = false;
		}
		return flag3;
	}



	std::ostream& Error::display(ostream& ostr) const {

		if (this->m_message != nullptr)
		{
			ostr << this->m_message;
		}

		return ostr;
	}

	std::ostream& operator<<(std::ostream& ostr, const Error& right) {
		return right.display(ostr);

	}


};