/*
*****************************************************************************

Full Name  : Ronald Roldan

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#ifndef SDDS_ERROR_H
#define SDDS_ERROR_H
#include <iostream>
#include "POS.h"
using namespace std;
namespace sdds
{

	class Error {
		char* m_message;
		int* number;
	public:
		Error();
		Error(const char* errors);
		Error(const Error& errors);
		Error& operator=(const char* errors);
		//copy assignment operator
		Error& operator=(const Error& errors);
		operator bool() const;
		ostream& display(ostream& ostr = cout) const;
		Error& clear();

		~Error();
	};
	std::ostream& operator<<(std::ostream& ostr, const Error& right);

}
#endif