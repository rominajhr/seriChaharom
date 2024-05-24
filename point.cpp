#include<iostream>
#include<cmath>
#include"point.h"
using namespace std;

//constructors
Point :: Point(int a , int b ){
    x = a;
    y = b;
}

Point :: Point(const Point & r){
    x = r.x;
    y = r.y;
}



//operators
Point operator + (const Point &p1 , const Point &p2){
    int newx = p1.x + p2.x;
    int newy = p1.y + p2.y;

    return Point(newx , newy);
}

Point operator - (const Point &p1 , const Point &p2){
    int newx = p1.x - p2.x;
    int newy = p1.y - p2.y;

    return Point(newx , newy);
}

Point & Point :: operator /= (int num){
    if(!num)   //if num was zero
        cout<<"\nYou can't divide by zero"<<endl;
    else{
        x /= num;
        y /= num;
    }
    return *this;
}

Point & Point :: operator = (const Point & r){
    x = r.x;
    y = r.y;

    return *this;
} 

bool operator >= (const Point & p1 , const Point & p2){
    double distanceP1 = sqrt(p1.x * p1.x + p1.y * p1.y) , distanceP2 = sqrt(p2.x * p2.x + p2.y * p2.y);

    if(distanceP1 >= distanceP2)
        return true;
    else
        return false;
}



//Getters and Setters
void Point :: setx(int a){
    x = a;
}
int Point :: getx() const {
    return x;
}

void Point :: sety(int b){
    y = b;
}
int Point :: gety() const {
    return y;
}

