/*
*****************************************************************************

Full Name  : Ronald Roldan

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#ifndef SDDS_ITEM_H
#define SDDS_ITEM_H
#include <iostream>
#include "POS.h"
#include "PosIO.h"
#include "Error.h"
#include "Utils.h"
#include "POS.h"
#include "Utils.h"

using namespace std;

namespace sdds
{
	class Item 
	{
		char m_sku[MAX_SKU_LEN];
		char* m_name = nullptr;
		double m_price;
		bool m_taxed;
		int m_quantity;
		char itemtype = 'T';
		double m_totalprice;
		double totalprices;
	protected:
		int m_displayType;
		Error m_error = ERROR_POS_EMPTY;

	public:

		Item();
		Item(const Item& Items);
		Item& operator=(const Item& Items);
		~Item();
		operator bool()const;


		// member operator overloads
		bool operator==(const char* value) const;
		bool operator>(const Item& Items) const;


		int operator+=(int value);
		
		int operator-=(int value);

		//member functions
		Item& displayType(int no);
		double cost() const;
		int quantity() const;
		Item& clear();



		// IO
		std::ostream& write(std::ostream& ostr = std::cout) const;
		std::istream& read(std::istream& istr = std::cin);
		std::ofstream& save(std::ofstream& ofstr);
		std::ifstream& load(std::ifstream& ifstr) ;
		std::ostream& bprint(std::ostream& ostr = std::cout) const;



	};
	std::ostream& operator<<(std::ostream& ostr, const Item& right);

	std::istream& operator>>(std::istream& istr, Item& rightOperand);

	std::ofstream& operator<<(std::ofstream& ofstr,  Item& right);

	std::ifstream& operator>>(std::ifstream& ifstr, Item& rightOperand);
	
	double operator+=(double& total, Item& items);
}

#endif