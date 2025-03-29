#include <iostream>
using namespace std;


//声明Point类
class Point                        
{public:
  Point(float=0,float=0);
  void setPoint(float,float);
  virtual  float area() const {return 0.0;} 
  //virtual  float area() const=0;
  virtual float volume() const {return 0.0;}
  float getX() const {return x;}
  float getY() const {return y;}
  virtual void shapeName() const {cout<<"Point:";}  //对纯虚函数进行定义
  virtual void display(ostream& out)
  {
  	out<<"["<<x<<","<<y<<"]";
 
  }
 
 protected:
  float x,y;
};

Point::Point(float a,float b)
{x=a;y=b;}

void Point::setPoint(float a,float b)
{x=a;y=b;}


//声明Circle类
class Circle:public Point
{public:
  Circle(float x=0,float y=0,float r=0);
  void setRadius(float);
  float getRadius() const;
  virtual float area() const;
  virtual void shapeName() const {cout<<"Circle:";}         //对纯虚函数进行再定义
  virtual void display(ostream& out)
  {
  	out<<"["<<x<<","<<y<<"], r="<<radius;
 
  }
 
 protected:
  float radius;
};

Circle::Circle(float a,float b,float r):Point(a,b),radius(r){}

void Circle::setRadius(float r)
{radius=r;}

float Circle::getRadius() const {return radius;}

float Circle::area() const
{return 3.14159*radius*radius;}


//声明Cylinder类
class Cylinder:public Circle
{public:
  Cylinder (float x=0,float y=0,float r=0,float h=0);
  void setHeight(float);
  float getHeight() const;
  virtual float area() const;
  virtual float volume() const;
  virtual void shapeName() const {cout<<"Cylinder:";}         //对纯虚函数进行再定义
   virtual void display(ostream& out)
  {
  	out<<"["<<x<<","<<y<<"], r="<<radius<<", h="<<height;
 
  }
 
 protected:
  float height;
};

Cylinder::Cylinder(float a,float b,float r,float h)
    :Circle(a,b,r),height(h){}

void Cylinder::setHeight(float h){height=h;}

float Cylinder::getHeight() const {return height;}

float Cylinder::area() const
{ return 2*Circle::area()+2*3.14159*radius*height;}

float Cylinder::volume() const
{return Circle::area()*height;}



ostream& operator<<(ostream &output,Point& s){
	s.display(output);
	output<<endl;
	return output;
}
void fun(Point& s){
	s.shapeName();
	cout<<s;  
    cout<<s.area()<<" "<<s.volume()<<endl;
}
//*/
int main()
{Point point(3.2,4.5);                           //建立Point类对象point
 Circle circle(2.4,12,5.6);                      //建立Circle类对象circle
 Cylinder cylinder(3.5,6.4,5.2,10.5);            //建立Cylinder类对象cylinder
  //Ball ball(2.4,12,5.6); 

 fun(point);
 fun(circle); 
 fun(cylinder);
 //fun(ball);  
 
 return 0;
}

