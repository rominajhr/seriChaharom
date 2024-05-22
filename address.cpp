#include <iostream>
#include <string>
#include "address.h"
using namespace std;

Address :: Address(string co , string ci , string st){
    country = co;
    city = ci;
    street = st;
}



//operators
ostream & operator <<(ostream& strm , const Address &a){
    strm << "Country : " << a.country << endl;
    strm << "City : " << a.city << endl;
    strm << "Street : "<< a.street << endl;
    return strm;
}

istream & operator >> (istream & strm , Address &a){
    cout<< "Country : ";
    strm>>a.country;
    cout<<"\nCity : ";
    strm>>a.city;
    cout<<"\nStreet : ";
    strm>>a.street;
    return strm;
}



//Getters and Setters
void Address :: setCountry(string co){
    country = co;
}
string Address :: getCountry(){
    return country;
}

void Address :: setCity(string ci){
    city = ci;
}
string Address :: getCity(){
    return city;
}

void Address :: setStreet(string st){
    street = st;
}
string Address :: getStreet(){
    return street;
}
