#include<iostream>
#include<string>
using namespace std;

#ifndef ADDRESS_H
#define ADDRESS_H

class Address{
    string country , city , street;
    public:
        Address(string , string ,string);
        friend ostream & operator <<(ostream& strm , const Address &a);
        friend istream & operator >>(istream& strm , Address &a);



        //Getters and Setters
        void setCountry();
        string getCountry();
        
        void setCity();
        string getCity();

        void setStreet();
        string getStreet();
};

#endif