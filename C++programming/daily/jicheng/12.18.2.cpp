#include <iostream>
#include <string>
using namespace std;
// 组合类：Course
class Course {
private:
    string courseName;
    string courseCode;
 
public:
    Course(const string& courseName, const string& courseCode)
        : courseName(courseName), courseCode(courseCode) {cout<<"Course Constructed"<<endl;}
    Course(Course &c){
    	courseName=c.courseName;
    	courseCode=c.courseCode;
    	cout<<"Course Copy Constructed"<<endl;
	}
    ~Course(){cout<<"Course Destructed"<<endl;}
    void describe() const {
        cout << courseName << " (Course Code: " << courseCode << ")" << endl;
    }
};
 
// 基类：Person
class Person {
protected:
    string name;
    int age;
 
public:
    Person(const string& name, int age) : name(name), age(age) 
	{cout<<"Person Constructed"<<endl;}
 
    void introduce() const {
        cout << "Hello, my name is " << name << " and I am " << age << " years old." << endl;
    }
 
    // 在派生类中被重写
    void display() const {
        introduce();
    }
 
    // 析构函数 
    ~Person() {cout<<"Person Destructed"<<endl;}
};
 
// 派生类：Student，继承自 Person
class Student : public Person {
private:
    string studentId;
    Course course; // 组合关系：Student 包含一个 Course 对象
 
public:
    Student(const string& name, int age, const string& studentId, Course &ocourse)
        : Person(name, age), studentId(studentId), course(ocourse) {cout<<"Student Constructed"<<endl;}
    ~Student(){cout<<"Student Destructed"<<endl;	}
    // 重写 display 方法
    void display() const  {
        introduce();
        cout << "I am a student with ID " << studentId << "." << endl;
                    cout << "I am currently enrolled in: ";
            course.describe();
       
    }
 
    // 设置课程
    void setCourse(Course &ocourse) {
        course = ocourse;
    }
};
 

int main() {
    // 创建 Course 对象
    Course mathCourse("Mathematics", "MATH101");
    cout<<"1"<<endl;
    // 创建 Student 对象，并设置其 Course
    Student student("Alice", 20, "S12345", mathCourse);
    cout<<"2"<<endl;
    // 显示学生信息
    student.display();
 
    return 0;
}
