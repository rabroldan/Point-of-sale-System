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
#include <ctime>
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include "POS.h"
#include "Error.h"
#include "Utils.h"



namespace sdds {
    void getSystemDate(int& year, int& mon, int& day, int& hour, int& min, bool dateOnly) {
        time_t t = time(NULL);
        tm lt = *localtime(&t);
        day = lt.tm_mday;
        mon = lt.tm_mon + 1;
        year = lt.tm_year + 1900;
        if (dateOnly) {
            hour = min = 0;
        }
        else {
            hour = lt.tm_hour;
            min = lt.tm_min;
        }
    }

    int uniqueDateValue(int year, int mon, int day, int hour, int min) {
        return year * 535680 + mon * 44640 + day * 1440 + hour * 60 + min;
    }
    int daysOfMonth(int year, int month) {
        int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
        int mon = month >= 1 && month <= 12 ? month : 13;
        mon--;
        return days[mon] + int((mon == 1) * ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
    }


        int strLen(const char* str) {
            int len = -1;
            while (str[++len]);
            return len;
        }
        void strCpy(char* des, const char* src) {
            while (*src) *des++ = *src++;
            *des = *src;
        }
        void strCat(char* des, const char* src) {
            while (*des) des++;
            while (*src) *des++ = *src++;
            *des = *src;
        }
        void delAlloCopy(char*& des, const char* src) {
            delete[] des;
            des = nullptr;
            if (src && src[0]) {
                des = new char[strLen(src) + 1];
                strCpy(des, src);
            }
        }
        char* dynRead(istream& istr, char delimeter) {
            char* str{};
            string toRead;
            getline(istr, toRead, delimeter);
            if (istr) {
                str = new char[strLen(toRead.c_str()) + 1];
                strCpy(str, toRead.c_str());
            }
            return str;
        }


        bool number_isit(const std::string& s)
        {
            std::string::const_iterator it = s.begin();
            while (it != s.end() && std::isdigit(*it)) ++it;
            return !s.empty() && it == s.end();
        }

        
}