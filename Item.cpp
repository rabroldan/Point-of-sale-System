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
#include "Item.h"

using namespace std;
namespace sdds {

	Item::Item()
	{
		m_sku[0] = '\0';
		m_name = nullptr;
		m_price = 0;
		m_quantity = 0;
		m_taxed = false;
		itemtype = 'T';
	}

	Item::Item(const Item& Items)
	{
		Item::operator=(Items);
	}

	Item& Item::operator=(const Item& other)
	{
		if (this != &other)
		{
			m_error.clear();
			delete[] this->m_name;
			if (nullptr == other.m_name)
			{
				this->m_name = nullptr;
			}
			if (other.m_name && other.m_name[0] != '\0')
			{
				int size = strlen(other.m_name);
				this->m_name = new char[size + 1];
				strcpy(this->m_name, other.m_name);
			}
		}
		this->m_taxed = other.m_taxed;
		this->m_price = other.m_price;
		strcpy(m_sku, other.m_sku);
		this->m_quantity = other.m_quantity;
		this->m_totalprice = other.m_totalprice;
		return *this;
	}

	Item::~Item()
	{
		delete[] m_name;
	}

	bool Item::operator==(const char* sku) const
	{


		return strcmp(this->m_sku, sku) == 0 ? true : false;
	}

	bool Item::operator>(const Item& Items) const
	{

		return Items.m_name[0] < this->m_name[0] ? true : false;
	}




	int Item::operator+=(int value)
	{
		this->m_quantity += value;
		if (this->m_quantity > MAX_STOCK_NUMBER)
		{
			this->m_quantity = MAX_STOCK_NUMBER;
			m_error = ERROR_POS_QTY;
		}
		return m_quantity;
	}

	double operator+=(double& total, Item& items)
	{
		double items1 = items.cost();
		int quantity = items.quantity();
		total += items1 * quantity;
		return total;

	}

	int Item::operator-=(int value)
	{
		this->m_quantity -= value;
		if (value > this->m_quantity)
		{
			this->m_quantity -= value;
			this->m_quantity = 0;
			m_error = ERROR_POS_STOCK;
		}
		return this->m_quantity;
	}

	Item& Item::displayType(int no)
	{
		this->m_displayType = no;

		return *this;
	}

	double Item::cost() const
	{
		double price = m_price;

		if (m_taxed == true)
		{
			price *= TAX + 1;
		}


		return price;
	}

	int Item::quantity() const
	{
		return m_quantity;
	}

	Item& Item::clear()
	{
		m_error.clear();
		return *this;
	}

	std::ostream& Item::write(std::ostream& ostr) const
	{

		string name(m_name);
		string r = name.substr(0, 20);
		switch (m_displayType) {
		case 1:
			if (!m_error)
			{
				ostr.setf(ios::left);
				ostr.width(7);
				ostr.fill(' ');


				ostr << m_sku;
				ostr << "|";

				ostr.width(20);
				ostr.fill(' ');
				ostr << r;
				ostr.unsetf(ios::left);

				ostr << "|";

				ostr.setf(ios::fixed);
				ostr.setf(ios::right);
				cout.precision(2);
				ostr.width(7);
				ostr.fill(' ');
				ostr << m_price;
				ostr.unsetf(ios::right);

				ostr << "|";

				ostr << " ";
				if (m_taxed == true)
				{
					ostr << "X";
				}
				else
				{
					ostr << " ";

				}
				ostr << " ";

				ostr << "|";

				ostr.setf(ios::right);
				ostr.width(4);
				ostr.fill(' ');
				ostr << m_quantity;
				ostr.unsetf(ios::right);

				ostr << "|";

				ostr.setf(ios::fixed);
				ostr.setf(ios::right);

				ostr.precision(2);
				ostr.width(9);
				ostr.fill(' ');
				ostr << m_totalprice;
				ostr.unsetf(ios::right);

				ostr << "|";

			}
			else
			{

				ostr << m_error;

			}

			break;
		case 2:
			
				ostr.width(14);
				ostr.fill('=');
				ostr << "v";


				ostr << "\n";
				ostr.setf(ios::left);
				ostr.width(13);
				ostr.fill(' ');
				ostr << "Name:";


				ostr << m_name;
				ostr << "\n";

				ostr.setf(ios::left);
				ostr.width(13);
				ostr.fill(' ');
				ostr << "Sku:";

				ostr << m_sku;
				ostr << "\n";

				ostr.setf(ios::fixed);

				ostr.precision(2);
				ostr.width(13);
				ostr.fill(' ');
				ostr << "Price:";

				ostr << m_price;
				ostr << "\n";

				ostr.setf(ios::fixed);

				ostr.precision(2);
				ostr.width(13);
				ostr.fill(' ');
				ostr << "Price + tax:";
				if (m_taxed == false)
				{
					ostr << "N/A";
				}
				else
				{
					ostr << m_taxed;
				}

				ostr << "\n";

				ostr.width(13);
				ostr.fill(' ');
				ostr << "Stock Qty:";

				ostr << m_quantity;


				ostr << "\n";
			
			


				break;

		}

		return(ostr);
	}

	std::istream& Item::read(std::istream& istr)
	{
		int name2;
		bool decimalcheck = false;
		bool intcheck = false;
		bool namecheck = false;
		bool taxcheck = false;
		int num;
		char decimal[50];

		char taxy;
		char Ucase;
		char Lcase;
		char Ucase2 = '\0';
		char Lcase2 = '\0';

		char integer[10];
		m_error.clear();
		cout << "Sku";

		do
		{
			cout << "\n";
			cout << "> ";
			istr >> m_sku;
			istr.ignore();
			if (strlen(m_sku) > MAX_SKU_LEN)
			{
				cout << ERROR_POS_SKU;
				m_error = ERROR_POS_SKU;

			}
		} while (strlen(m_sku) > 7 && m_sku[0] != '\0');
		cout << "Name";

		do
		{
			cout << "\n";
			cout << "> ";
			this->m_name = dynRead(istr, '\n');

			name2 = strlen(m_name);
			if (name2 > 20)
			{
				cout << ERROR_POS_NAME;
				m_error = ERROR_POS_NAME;
				delete[] m_name;
				namecheck = false;
			}
			else
			{
				namecheck = true;
			}
		} while (namecheck != true);

		cout << "Price";
		do
		{

			cout << "\n";
			cout << "> ";
			istr >> decimal;
			num = number_isit(decimal);
			if (decimal[0] == '-')
			{
				cout << ERROR_POS_PRICE;
				m_error = ERROR_POS_PRICE;

				decimalcheck = false;

			}
			else if (num == 0)
			{
				cout << ERROR_POS_PRICE;
				m_error = ERROR_POS_PRICE;
				decimalcheck = false;
			}

			else
			{
				m_price = std::stod(decimal);
				decimalcheck = true;

			}

		} while (decimalcheck != true);


		cout << "Taxed?\n";
		cout << "(Y)es/(N)o:";
		do
		{
			cout << " ";

			istr >> taxy;
			Ucase = toupper(taxy);
			Lcase = tolower(taxy);
			if (Ucase == 'Y' || Lcase == 'y')
			{
				Ucase2 = 'N';
				Lcase2 = 'n';
				m_taxed = true;
			}
			else if (Ucase == 'N' || Lcase == 'n')
			{

				Ucase = 'Y';
				Lcase = 'y';
				Ucase2 = 'N';
				Lcase2 = 'n';
				m_taxed = false;

			}

			if ((Ucase != 'Y' || Lcase != 'y') && (Ucase2 != 'N' || Lcase2 != 'n'))
			{
				cout << ERROR_POS_TAX;
				m_error = ERROR_POS_TAX;
				taxcheck = false;
				istr.ignore(20, '\n');
			}
			else
			{
				taxcheck = true;
				m_error = nullptr;
			}
		} while (taxcheck != true);


		cout << "Quantity";
		do
		{
			cout << "\n";
			cout << "> ";
			istr >> integer;
			num = number_isit(integer);
			if (integer[0] == '-')
			{
				cout << ERROR_POS_QTY;
				m_error = ERROR_POS_QTY;
				intcheck = false;

			}
			else if (num == 0)
			{
				cout << ERROR_POS_QTY;
				m_error = ERROR_POS_QTY;

				intcheck = false;
			}

			else
			{
				m_quantity = std::stod(integer);
				if (m_quantity > 0 && m_quantity < 100)
				{
					intcheck = true;
				}
				else
				{
					cout << ERROR_POS_QTY;
					m_error = ERROR_POS_SKU;
					intcheck = false;
				}
			}


		} while (intcheck != true);

		if (m_taxed == true)
		{
			m_totalprice = ((m_quantity * m_price) * TAX) + (m_quantity * m_price);
			m_error = nullptr;

		}
		else if (m_taxed == false)
		{
			m_totalprice = m_quantity * m_price;
			m_error = nullptr;

		}
		m_error = nullptr;
		return(istr);
	}

	std::ofstream& Item::save(std::ofstream& ofstr)
	{

		if (!m_error)
		{
			cerr << m_error;

		}

		ofstr << itemtype << "," << m_sku << "," << m_name << ",";
		ofstr.setf(ios::fixed);
		ofstr.precision(2);
		ofstr << m_price;

		ofstr << "," << m_taxed << "," << m_quantity;
		return(ofstr);
	}

	std::ifstream& Item::load(std::ifstream& ifstr)
	{
		bool badentry = false;

		double sm_price = 0.0;
		int sm_quantity = 0;
		bool taxed = false;
		m_error.clear();

		char sku[MAX_SKU_LEN + 2]{};
		char sm_name[MAX_NAME_LEN + 2]{};

		ifstr.get(sku, MAX_SKU_LEN + 2, ',');
		ifstr.ignore(1000, ',');
	
		ifstr.get(sm_name, MAX_NAME_LEN + 2, ',');
		ifstr.ignore(1000, ',');
		
		ifstr >> sm_price;
		ifstr.ignore();
		
		ifstr >> taxed;
		ifstr.ignore();
		
		ifstr >> sm_quantity;
		//sku
		int skus = strlen(sku);
		if (skus > 4 && badentry == false && sm_quantity != 200)
		{
			m_error = ERROR_POS_SKU;
			badentry = true;
		}
		else
		{
			
			strcpy(this->m_sku, sku);
			
		}
		// name

		int name = strlen(sm_name);

		if (name > 20 && strlen(sku) > 4)
		{
			m_error = ERROR_POS_NAME;

		}
		else
		{
			delAlloCopy(this->m_name, sm_name);
		}

		// pricce
		if (sm_price < 0)
		{
			m_error = ERROR_POS_PRICE;

		}
		else
		{
			
			this->m_price = sm_price;

		}

		// quantity
		if ((sm_quantity > MAX_STOCK_NUMBER || sm_quantity < 0) && badentry == false)
		{
			m_error = ERROR_POS_QTY;

		}
		else
		{
			this->m_quantity = sm_quantity;
		}

		//taxed
		if (taxed == true)
		{
			m_taxed = taxed;
			this->m_totalprice = ((m_quantity * m_price) * TAX) + (m_quantity * m_price);

		}
		else if (taxed == false)
		{
			m_taxed = taxed;
			this->m_totalprice = this->m_price * this->m_quantity;
		}




		
		return(ifstr);
	}

	std::ostream& Item::bprint(std::ostream& ostr) const
	{
		string name(m_name);
		string r = name.substr(0, 20);


		ostr.setf(ios::left);

		ostr << "| ";

		ostr.width(20);
		ostr.fill(' ');
		ostr << r;
		ostr.unsetf(ios::left);

		ostr << "|";

		ostr.setf(ios::fixed);
		ostr.setf(ios::right);
		cout.precision(2);
		ostr.width(10);
		ostr << cost();
		ostr.unsetf(ios::right);

		ostr << " |";

		ostr << " ";
		if (m_taxed == true)
		{
			ostr << " T ";
		}
		else
		{
			ostr << "   ";

		}
		ostr << " ";

		ostr << "|";
		ostr << "\n";
		return(ostr);

	}

	std::ostream& operator<<(std::ostream& ostr, const Item& right)
	{
		return right.write(ostr);

	}

	std::istream& operator>>(std::istream& istr, Item& rightOperand)
	{
		return rightOperand.read(istr);
	}

	std::ofstream& operator<<(std::ofstream& ofstr, Item& right)
	{
		return right.save(ofstr);
	}

	std::ifstream& operator>>(std::ifstream& ifstr, Item& rightOperand)
	{

		return rightOperand.load(ifstr);
	}

	Item::operator bool()const
	{

		return !m_error;
	}

};