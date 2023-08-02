#ifndef SDDS_Utils_H
#define SDDS_Utils_H
#include <iostream>
#include <fstream>
namespace sdds {


	void getSystemDate(int& year, int& mon, int& day, int& hour, int& min, bool dateOnly);
	int uniqueDateValue(int year, int mon, int day, int hour, int min);
	int daysOfMonth(int year, int month);
	int strLen(const char* str);
	void strCpy(char* des, const char* src);
	void strCat(char* des, const char* src);
	void delAlloCopy(char*& des, const char* src);
	char* dynRead(std::istream& istr, char delimeter = '\n');
	bool number_isit(const std::string& s);

}
#endif