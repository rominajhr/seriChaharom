#include<iostream>
#include<string>
#include"employee.h"
using namespace std;

//constructors
Employee :: Employee(string na , string ID , Address adr , int hw , int sph , int wtd , int wd ): address(adr){
    name = na;
    if(!validate(ID)){
        cout<<"id invalid"<<endl;
        exit(0);
    }
    id = ID;
    hourWork = hw;
    salaryPerHour = sph;
    workToDo = wtd;
    workDone = wd;
}

Employee :: Employee(const Employee & r):address(r.address){
    name = r.name;
    id = r.id;
    hourWork = r.hourWork;
    salaryPerHour = r.salaryPerHour;
    workToDo = r.workToDo;
    workDone = r.workDone;
}



//operators
ostream & operator <<(ostream& strm , const Employee & e){
    strm << "Name : " << e.name << "\nId : " << e.id << "\nSalary : " << e.calculateSalary()<< "$" << "\nEfficiency : " << e.efficiency() <<" %" << endl << e.address;
    return strm;
}

istream & operator >>(istream &strm , Employee & e){
    cout<<"Name : ";
    strm>>e.name;
    cout<<"Id : ";
    strm>>e.id;
    while(!e.validate(e.id)){
        cout<<"invalid id"<<endl;
        cout<<"Id : ";
        strm >> e.id;
    }
    cout<<"Hour work : ";
    strm>>e.hourWork;
    cout<<"Salary per hour : ";
    strm >> e.salaryPerHour;
    cout<< "Work to do : ";
    strm >> e.workToDo;
    cout<<"Work Done : ";
    strm >> e.workDone;
    strm>>e.address;

    return strm;
}

Employee & Employee :: operator = (const Employee & r){
    address = r.address;
    name = r.name;
    id = r.id;
    hourWork = r.hourWork;
    salaryPerHour = r.salaryPerHour;
    workDone = r.workDone;
    workToDo = r.workToDo;

    return *this;
}



//Getters and Setters
void Employee ::setHourWork(int hw){
    hourWork = hw;
}
int Employee :: getHourWork(){
    return hourWork;
}

void Employee :: setSalaryPerHour(int sph){
    salaryPerHour = sph;
}
int Employee::getSalaryPerHour(){
    return salaryPerHour;
}

void Employee :: setWorkToDo(int wtd){
    workToDo = wtd;
}
int Employee :: getWorkToDo(){
    return workToDo;
}

void Employee :: setWorkDone(int wd){
    workDone = wd;
}
int Employee :: getWorkDone(){
    return workDone;
}



//others
double Employee :: calculateSalary() const{
    int notDone = workDone - workToDo;
    double totalSalary = hourWork * salaryPerHour;
    
    totalSalary -= totalSalary * ((notDone * 1.0) / (workToDo * 1.0));
    return totalSalary;    
}

double Employee :: efficiency() const {
    return (workDone * 1.0) / (hourWork * 1.0) * 100;    
}

