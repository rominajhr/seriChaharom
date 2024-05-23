#include<iostream>
#include<string>
#include "person.h"
using namespace std;

//constructors
Person :: Person(string na , string ID , Address adr):address(adr){
    name = na;
    id = ID;
}

Person :: Person(const Person & r):address(r.address){
    name = r.name;
    id = r.id;
}



//operators
ostream& operator <<(ostream &strm , const Person &p){
    strm << "Name : " << p.name << endl;
    strm << "Id : " << p.id << endl;
    strm << "Address" << p.address << endl;
    return strm;
}

istream& operator >>(istream &strm , Person &p){
    cout<< "Name : ";
    strm >> p.name;
    cout<<"\nId : ";
    strm >> p.id;
    cout<<endl;
    strm >> p.address;
    return strm;
}

Person& Person :: operator = (const Person &p){
    name = p.name;
    id = p.id;
    address = p.address;
    return *this;
}



//Getters and Setters
void Person :: setName(string na){
    name = na;
}
string Person :: getName(){
    return name;
}

void Person :: setId(string ID){
    id = ID;
}
string Person :: getId(){
    return id;
}

void Person :: setAddress(Address adr){
    address = adr;
}
Address Person :: getAddress(){
    return address;
}
