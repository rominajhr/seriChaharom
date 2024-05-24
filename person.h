#include<string>
#include "address.h"
using namespace std;

#ifndef PERSON_H
#define PERSON_H

class Person{
    string name , id;
    Address address;


    bool validate(string checkId){
        
        //checking the length of id
        int length = checkId.length();
        if(length < 8 || length > 10)
            return false;


        //The first two digits should be equal to the year of entry
        int year = (checkId[0] - '0') * 10 + (checkId[1] - '0');
        if(year > 99 || year < 84)
            return false;


        //have one to three non number charecters
        int numOfChar = 0 , i;
        for(i = 2;checkId[i] < '0' || checkId[i] > '9';i++)
            numOfChar++;
        if(numOfChar < 1 || numOfChar > 3)
            return false;
        

        //The following five characters are numbers less than 4 or greater than 6
        for(int j = 0;j < 5;j++ , i++){
            if(!((checkId[i] >= '0' && checkId[i] < '4') || (checkId[i] <= '9' && checkId[i] > '6')))
                return false;
        }


        return true;
    }

    
    public : 
        Person(string , string , Address);
        Person(const Person &);


        
        //operators
        friend ostream & operator <<(ostream& , const Person &);
        friend istream & operator >>(istream& , Person &);   
        Person& operator = (const Person &);



        //Getters and Setters
        void setName(string);
        string getName();

        void setId(string);
        string getId();

        void setAddress(const Address &);
        Address getAddress();
};

#endif