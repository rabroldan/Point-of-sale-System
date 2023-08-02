/*
*****************************************************************************

Full Name  : Ronald Roldan

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#ifndef SDDS_POSIO_H
#define SDDS_POSIO_H
#include <iostream>
#include "POS.h"
using namespace std;

namespace sdds
{
	class PosIO  {
		public:
		virtual ~PosIO();
		virtual std::ostream& write(std::ostream& ostr = std::cout) const = 0;
		virtual std::istream& read(std::istream& istr = std::cin) = 0;
		virtual std::ifstream& save(std::ifstream& ifstr) = 0;
		virtual std::ofstream& load(std::ofstream& ostr) const = 0;


	};
	
	std::ostream& operator<<(std::ostream& ostr, const PosIO& right);

	std::istream& operator>>(std::istream& istr, PosIO& rightOperand);

	std::ofstream& operator<<(std::ofstream& ofstr, const PosIO& right);

	std::ifstream& operator>>(std::ifstream& ifstr, PosIO& rightOperand);



}

#endif