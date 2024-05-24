#ifndef POINT_H
#define POINT_H

class Point{
    int x , y;
    public : 
        Point(int = 0 , int = 0);
        Point(const Point &);


        //operators
        friend Point operator + (const Point & , const Point &);
        friend Point operator - (const Point & , const Point &);
        Point& operator /= (int);
        Point& operator = (const Point &);
        friend bool operator >= (const Point & , const Point &);



        //Getters and Setters
        void setx(int);
        int getx();

        void sety(int);
        int gety();
};

#endif