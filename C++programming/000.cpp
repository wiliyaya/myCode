#include <iostream>
#include <string>
using namespace std;
class Member
{
   public: 
   Member(string s){name=s;}
   void answer()
   {cout<<"I am a member. I'm "<<name<<endl;}
   protected:
   string name;
};
class Teacher: public Member
{
 public:
 Teacher(string s) :Member(s){ }  
 void answer()
 {cout<<"I am a teacher. I'm "<<name<<endl;}
};
class Student: public Member
{
 public:
 Student(string s) :Member(s){ }   
 void answer()
 {cout<<"I am a student. I'm "<<name<<endl;}
};

void funp(Member *mp){
	mp->answer();
}
void funr(Member& mr) {
	mr.answer();
}
int main()
 {
    Member m1("张三");
	Teacher t1("老王");
	Student s1("李四");
    cout<<sizeof(Member)<<endl;
    cout<<sizeof(Student)<<endl;

    
  //基类指针
   //* 
	Member* who;
	
	who = &m1;
	m1.answer();
	who->answer() ;
	
	who = &t1;
	t1.answer();
	who->answer() ;
	
	who = &s1;
	s1.answer();
	who->answer() ;
	//*/
	/*
	funp(&t1);
	funr(s1);
	//*/
 return 0;

 }
  

