#include<iostream>
#include<string>
#include"address.h"
#include"employee.h"
#include"person.h"
#include"point.h"
#include"rectangle.h"
using namespace std;

int main(){

    //Adsress
    Address adr1("Iran" , "Karaj" , "Hesarak") , adr2;   //chacking constructors
    cout<<"\nAddress 1 :\n"<<adr1<<endl;

    cout<<"\nEnter Address 2 :\n"; //chacking << and >>
    cin>>adr2;
    cout<<"\nThe Address you put : \n"<<adr2;


    //Person
    Person pe1("romina" , "84jhr23189", Address("Iran" , "Karaj" , "baghestan")); //chacking << and constructors
    cout<<"\nPerson 1 information : \n"<<pe1<<endl;

    Person pe2 = pe1;     //chacking copy constructor
    cout<<"\nPerson 2 :"<<endl<<pe2<<endl;

    cout<<"\nEnter person 1 information : \n"; //chacking >>    
    cin>>pe1;

    Person pe3; //checking =
    pe3 = pe1;
    cout<<"\nPerson 3 :"<<endl<<pe3<<endl;


    //Employee
    Employee e1("romina" , "89*a13289" , Address("Iran" , "Karaj" , "Hesarak") , 12 , 3 , 5 , 4); //checking constructor and << 
    cout<<"\nEmployee 1 information : "<<endl<<e1<<endl;                                          // calculateSalary and efficiency

    Employee e2 = e1; //checking copy constructor
    cout<<"\nEmployee 2 information : "<<endl<<e2<<endl;

    cout<<"\nEnter Employee 1 information : "<<endl; //checking >>
    cin>>e1;

    Employee e3; //checking =
    e3 = e1;
    cout<<"\nEmployee 3 information : "<<endl<<e3<<endl;
    

    //Point
    Point p1(2 , 3); //checking constructor
    cout<<"\nx = "<<p1.getx()<<"\ty =  "<<p1.gety()<<endl;

    Point p2 = p1; //checking copy constructor
    cout<<"\nx = "<<p2.getx()<<"\ty =  "<<p2.gety()<<endl;

    Point p3;  //checking = operator
    int a , b;
    cout<<"\nEnter two numbers : \n"<<endl;
    cin>>a>>b;
    p1.setx(a);
    p1.sety(b);
    p3 = p1; 
    cout<<"\nx = "<<p3.getx()<<"\ty =  "<<p3.gety()<<endl;

    p3 /= 3;  //checking /=
    cout<<"\np3 /= 3 "; 
    cout<<"\nx = "<<p3.getx()<<"\ty =  "<<p3.gety()<<endl;

    p1 = p2 + p3; //checking +
    cout<<"\np2 + p3 ";
    cout<<"\nx = "<<p1.getx()<<"\ty =  "<<p1.gety()<<endl;

    cout<<"\nEnter 2 number for point 1 : \n"<<endl; //checking >=
    cin>>a>>b;
    p1.setx(a);
    p1.sety(b);
    cout<<"\nEnter 2 number for point 2 : \n"<<endl;
    cin>>a>>b;
    p2.setx(a);
    p2.sety(b);
    if(p1 >= p2)
        cout<<"\npoint 1 is biger than point 2\n"<<endl;
    else
        cout<<"\npoint 2 is biger than point 1\n"<<endl;
    


    //Rectangle
    Rectangle r1(Point(2 , 3) , 3 , 7); //checking constructor
    cout<<"\nRectangle 1 :"<<endl;
    cout<<"Start point : "<<"x = "<<r1.getStartPoint().getx()<<"\ty = "<<r1.getStartPoint().gety()<<endl;
    cout<<"Width : "<<r1.getWidth()<<endl;
    cout<<"Height : "<<r1.getHeight()<<endl;

    Rectangle r2 (Point(1 , 3) , 4 , 5); 
    
    cout<<"\nRectangle 2 :"<<endl;
    cout<<"Start point : "<<"x = "<<r2.getStartPoint().getx()<<"\ty = "<<r2.getStartPoint().gety()<<endl;
    cout<<"Width : "<<r2.getWidth()<<endl;
    cout<<"Height : "<<r2.getHeight()<<endl;

    cout<<"\nr1 += r2"<<endl; //checking += and -= with non equal start point
    r1 += r2;


    cout<<"\nchange start Point and do it again : "<<endl;
    r2.setStartPoint(r1.getStartPoint());
    r1 += r2;  //checking += 

    cout<<"\nr1 += r2"<<endl;
    cout<<"\nRectangle 1 :"<<endl;
    cout<<"Start point : "<<"x = "<<r1.getStartPoint().getx()<<"\ty = "<<r1.getStartPoint().gety()<<endl;
    cout<<"Width : "<<r1.getWidth()<<endl;
    cout<<"Height : "<<r1.getHeight()<<endl;


    cout<<"\nr1 -= r2"<<endl;  //checking -=
    r1 -= r2;
    cout<<"\nRectangle 1 :"<<endl;
    cout<<"Start point : "<<"x = "<<r1.getStartPoint().getx()<<"\ty = "<<r1.getStartPoint().gety()<<endl;
    cout<<"Width : "<<r1.getWidth()<<endl;
    cout<<"Height : "<<r1.getHeight()<<endl;


    int w , h;  //checking collision detection and / operator
    cout<<"\nEnter 2 number for starting point of first rectangle : "<<endl;
    cin>>a>>b;
    r1.setStartPoint(Point(a , b));
    cout<<"\nEnter width of first rectangle : "<<endl;
    cin>>w;
    r1.setWidth(w);
    cout<<"\nEnter height of first rectangle : "<<endl;
    cin>>h;
    r1.setHeight(h);

    cout<<"\nEnter 2 number for starting point of second rectangle : "<<endl;
    cin>>a>>b;
    r2.setStartPoint(Point(a , b));
    cout<<"\nEnter width of second rectangle : "<<endl;
    cin>>w;
    r2.setWidth(w);
    cout<<"\nEnter height of second rectangle : "<<endl;
    cin>>h;
    r2.setHeight(h);

    
    Rectangle result = r1 / r2; //checking /
    cout<<"\nr1 / r2 :"<<endl;
    cout<<"Start point : "<<"x = "<<result.getStartPoint().getx()<<"\ty = "<<result.getStartPoint().gety()<<endl;
    cout<<"Width : "<<result.getWidth()<<endl;
    cout<<"Height : "<<result.getHeight()<<endl;


    if(r1.collisionDetection(r2)) //checking collision
        cout<<"\nThey have collision"<<endl;
    else
        cout<<"\nThey don't have collision"<<endl;
}