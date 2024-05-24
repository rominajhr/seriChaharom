#include<iostream>
#include"rectangle.h"
using namespace std;

//constructors
Rectangle :: Rectangle(Point p , int w = 0 , int h = 0) : startPoint(p) {
    width = w;
    height = h;
}

Rectangle :: Rectangle(const Rectangle & r): startPoint(r.startPoint){
    width = r.width;
    height = r.height;
}



//operators
Rectangle & Rectangle :: operator += (const Rectangle &r){
    if(startPoint.getx() != r.startPoint.getx() || startPoint.getx() != r.startPoint.gety())
        cout<<"Error : Start points are not equal"<<endl;
    else{
        width = max(width , r.width);
        height = max(height , r.height);
    }

    return *this;
}

Rectangle & Rectangle :: operator -= (const Rectangle &r){
    if(startPoint.getx() != r.startPoint.getx() || startPoint.getx() != r.startPoint.gety())
        cout<<"Error : Start points are not equal"<<endl;
    else{
        width = min(width , r.width);
        height = min(height , r.height);
    }

    return *this;    
}

Rectangle operator / (const Rectangle & p1 , const Rectangle & p2){

    //new starting piont between two StartPoint
    Point newStartPoint = p1.startPoint + p2.startPoint;
    newStartPoint /= 2;


    int newWidth = (p1.width + p2.width) / 2;
    int newHeight = (p1.height + p2.height) / 2;


    return Rectangle(newStartPoint , newWidth , newHeight);
}



//Getters and Setters
void Rectangle :: setStartPoint(const Point & p){
    startPoint = p;
}
Point Rectangle :: getStartPoint(){
    return startPoint;
}

void Rectangle :: setWidth(int w){
    width = w;
}
int Rectangle :: getWidth(){
    return width;
}

void Rectangle :: setHeight(int h){
    height = h;
}
int Rectangle :: getHeight(){
    return height;
}



//others
bool Rectangle :: collisionDetection(const Rectangle & r) const{

    //max point of rectangles
    Point maxPoint1 = startPoint + Point(width , height);
    Point maxPoint2 = r.startPoint + Point(r.width , r.height);


    //if one start point is in the other rectangle they have collision
    if((startPoint >= r.startPoint && maxPoint2 >= startPoint) || (r.startPoint >= startPoint && maxPoint1 >= r.startPoint))
        return true;
    else
        return false;
}
