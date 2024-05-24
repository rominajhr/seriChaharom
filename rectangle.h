#include"point.h"

#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle{
    Point startPoint;
    int width , height;
    public : 
        Rectangle(Point , int , int);
        Rectangle(const Rectangle &);



        //operators
        Rectangle & operator += (const Rectangle &);
        Rectangle & operator -= (const Rectangle &);
        friend Rectangle operator / (const Rectangle & , const Rectangle &);



        //Getters and Setters
        void setStartPoint(const Point &);
        Point getStartPoint();

        void setWidth(int);
        int getWidth();

        void setHeight(int);
        int getHeight();



        //others
        bool collisionDetection(const Rectangle &) const;
};

#endif