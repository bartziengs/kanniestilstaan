/*

    Comment on `const` and `&` here.  See ../README.md.

    If you have a point other (as defined in the main) itś better to use the ampersand beccause you only need to pass that by reference. 
    passing by value would create another block scope vairable. This goes for all of the operations.
    The use of const particulairy comes in handy when constructing the so-called in place functions. Because you will need an auxilary varible
    that only has to be created once and after that you are fine with that variable being just read-only.

 */

#include <cmath>
#include <ostream>
#include <iomanip>

class Point
{
public:
    // constructors
    Point(){
        x = 0.0;
        y = 0.0;
    }

    Point(double x, double y){
        this->x= x;
        this->y= y;
    }
    // operators
    Point operator+(Point &other){
        return Point(x + other.x, y + other.y);
    }

    Point operator-(Point &other){
        return Point(x - other.x, y - other.y);
    }

    Point &operator+=(Point &other){
        x += other.x;
        y += other.y;
        return *this;
    }

    Point &operator-=(Point &other){
        x -= other.x;
        y -= other.y;
        return *this;
    }
    // methods

    double distance() {
        return sqrt(pow(x,2) + pow(y,2));
    }

    double distance(Point other) {
        Point res = Point(x - other.x, y - other.y);
        return sqrt(pow(res.x,2)+pow(res.y,2));
    }

    Point rotated(double angle){
        double old_x, old_y, new_x, new_y;
        old_x =x;
        old_y =y;
        new_x = old_x*cos(angle) - old_y*sin(angle);
        new_y = old_x*sin(angle) + old_y*cos(angle);
        return Point(new_x, new_y);

    }

    Point rotated(double angle, Point &other){
        double old_x, old_y, new_x, new_y;
        old_x =x;
        old_y =y;
        new_x = (old_x-other.x)*cos(angle) - (old_y-other.y)*sin(angle) + other.x;
        new_y = (old_x-other.x)*sin(angle) + (old_y-other.y)*cos(angle) + other.y;
        return Point(new_x, new_y);
    }

    Point &rotate(double angle){
        const Point res = rotated(angle);
        x = res.x;
        y = res.y;
        return *this;
    }

    Point &rotate(double angle, Point &other){
        const Point res = rotated(angle, other);
        x = res.x;
        y = res.y;
        return *this;
    }

    double x;
    double y;
};

class Triangle
{
public:
    // constructors
    Triangle(){
        a = Point();
        b = Point();
        c = Point();
    }

    Triangle(Point a, Point b, Point c){
        this->a =a;
        this->b =b;
        this->c =c;
    }

    Triangle translated(Point &t){
        Triangle res;
        res.a = a + t;
        res.b = b + t;
        res.c = c + t;
        return res;
    }

    Triangle &translate(Point &t){
        const Triangle res = translated(t);
        a = res.a;
        b = res.b;
        c = res.c;
        return *this;
    }

    Triangle rotated(double angle) {
        Triangle res;
        res.a = a.rotated(angle);
        res.b = b.rotated(angle);
        res.c = c.rotated(angle);
        return res;
    }

    Triangle rotated(double angle, Point &other) {
        Triangle res;
        res.a = a.rotated(angle, other);
        res.b = b.rotated(angle, other);
        res.c = c.rotated(angle, other);
        return res;
    }

    Triangle &rotate(double angle) {
        const Triangle res = rotated(angle);
        a = res.a;
        b = res.b;
        c = res.c;
        return *this;
    }

    Triangle &rotate(double angle, Point &other) {
        const Triangle res = rotated(angle, other);
        a = res.a;
        b = res.b;
        c = res.c;
        return *this;
    }

    double area(){
        return (a.x*b.y + b.x*c.y + c.x*a.y - a.x*c.y - c.x*b.y - b.x*a.y)/2; 
    }

    Point a, b, c;
};

// ostream operator for `Point`s
std::ostream &operator<<(std::ostream &os, const Point &p)
{
    // remember current flags, precision
    auto flags = os.flags();
    auto current_precision = os.precision();
    // output numers with fixed point and three decimal precision
    os.setf(std::ios::fixed, std::ios::floatfield);
    os.precision(3);
    // output point `p`
    os << "(" << std::setw(6) << std::setfill(' ') << p.x
        << "," << std::setw(6) << std::setfill(' ') << p.y << ")";
    // restore current flags, precision
    os.flags(flags);
    os.precision(current_precision);
    return os;
}

// ostream operator for `Triangle`s
std::ostream &operator<<(std::ostream &os, const Triangle &t)
{
    return os << "Triangle< " << t.a << ", " << t.b << ", " << t.c <<  " >";
}


#include <iostream>
using namespace std;

int main()
{
    // example, replace with your tests

    Point p,q,r,s,u,v,w; //all for testing and debugging
    Triangle t,t1,t2;

    // set point `p` to (1, 2)
    p.x = 1;
    p.y = 2;

    q.x = 3;
    q.y = 4;

    r = p + q;
    
    cout << "%%%%%%POINT PRINTING VALUES%%%%" << endl;

    cout << "Point r is: " << r << endl;

    p+=q;

    cout << "Point p-=q is: " << p << endl;

    cout << "distance from p to (0,0) is: " << q.distance() << endl;

    cout << "distance from q(3,4) to r(4,6) is: " << q.distance(r) << " (square root of 5)" << endl;

    s.x = 2;
    s.y = 0;



    u = s.rotated(M_PI);
    cout << "s rotated 180 degrees is :" << u << "should be (-2,0)" << endl;

    s.x=2;
    s.y=0;
    u.x=1;
    u.y=0;

    v = s.rotated(M_PI/2, u);

    cout << "s(2.0) rotated 90 degrees around u(1,0) is: " << v << "should be(1,1)" << endl;

    s.rotate(M_PI/2);

    cout << "S after rotation: "<< s << endl;

    s.rotate(M_PI/2,u);

    cout << "S after another rotation, but this time around u: "<< s << "should be (-1,-1)" << endl;


    cout << "%%%%%%TRIANGLE PRINTING VALUES%%%%" << endl;
   

    u.y=1;

    // set triangle `t` to (1, 2), (3, 4), (5, 6)
    t.a.x = 1;
    t.a.y = 2;
    t.b.x = 3;
    t.b.y = 4;
    t.c.x = 5;
    t.c.y = 6;

    t1 = t.translated(u);
    
    cout << t1 << endl;
    cout <<"new triangle t1 which is t translated bij (1,1) on every point:\n"<<t1 << endl;

    t.translate(u);

    cout << "t after translation (1,1):\n" << t << endl;

    t.a.x = 1;
    t.a.y = 0;
    t.b.x = 2;
    t.b.y = 0;
    t.c.x = 2;
    t.c.y = 1;

    cout<< "area of t: " << t.area() << endl;

    cout << t << endl;
    t.rotate(M_PI/2,s);
    cout << "t after a 90 degree rotation" << t << endl;


    // print point `p` and triangle `t`
    
}
