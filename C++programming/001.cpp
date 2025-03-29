#include <iostream>
using namespace std;
class Point
{public:
  Point(){cout<<"Point constructor"<<endl;}
  virtual ~Point(){cout<<"executing Point destructor"<<endl;}
  //要让基类指针指向派生类对象，要让基类的析构函数声明为虚析构
};

class Circle:public Point
{public:
  Circle(){cout<<"Circle constructor"<<endl;}
   ~Circle(){cout<<"executing Circle destructor"<<endl;}
 private:
  int radus;
};

int main()
{
  
  Circle *cn=new Circle;
  delete cn;
  //*
  Point *pn=new Circle;
  delete pn;
  //*/
 return 0;
}

