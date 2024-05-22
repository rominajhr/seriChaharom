#include<iostream>
#include<string>
using namespace std;

#ifndef ADDRESS_H
#define ADDRESS_H

class Address{
    string country , city , street;
    public:
        Address(string , string ,string);
        ostream & operator <<(ostream& strm);
        istream & operator>>(istream& strm);



        //Getters and Setters
        void setCountry();
        string getCountry();
        
        void setCity();
        string getCity();

        void setStreet();
        string getStreet();
};

#endif