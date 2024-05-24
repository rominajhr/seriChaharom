#include<string>
#include"address.h"
using namespace std;

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee{
    int hourWork , salaryPerHour , workToDo , workDone;


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
        if(numOfChar < 1 || numOfChar > 3 || checkId[2] != '*') //check if the third character is * or not
            return false;
        

        //The following five characters are numbers less than 4 or greater than 6
        for(int j = 0;j < 5;j++ , i++){
            if(!((checkId[i] >= '0' && checkId[i] < '4') || (checkId[i] <= '9' && checkId[i] > '6')))
                return false;
        }


        return true;
    }    


    public :
        string name , id;
        Address address;
        Employee(string = "" , string = "" , Address , int = 0 , int = 0 , int = 0 , int = 0);
        Employee(const Employee &);




        //operators
        friend ostream & operator <<(ostream& , const Employee &);
        friend istream & operator >>(istream& , Employee &);  
        Employee& operator = (const Employee &);



        //Getters and Setters
        void setHourWork(int);
        int getHourWork();

        void setSalaryPerHour(int);
        int getSalaryPerHour();

        void setWorkToDo(int);
        int getWorkToDo();

        void setWorkDone(int);
        int getWorkDone();



        //others
        double calculateSalary() const;
        double efficiency() const;
};

#endif