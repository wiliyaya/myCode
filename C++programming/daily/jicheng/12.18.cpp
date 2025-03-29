#include <iostream>
using namespace std; 
//组合关系中整体类依赖部分类
//所以要先定义部分类
// 定义Wheel类
class Wheel {
public:
    Wheel(double radius=10) : radius(radius) {cout<<"wheel constructed"<<endl;}
    ~Wheel(){ cout<<"wheel destructed"<<endl;
	} 
    // 获取轮子半径的方法
    double getRadius() const {
        return radius;
    }
 
    // 设置轮子半径的方法
    void setRadius(double radius) {
        this->radius = radius;
    }
 
private:
    double radius;

};
 
// 定义Car类，它包含4个Wheel对象
class Car {
public:
    Car(){
    	  cout<<"Car constructed"<<endl;
    }
    ~Car() {
        cout<<"Car destructed"<<endl;
    }
    // 获取所有轮子
    const Wheel* getWheels() const {
        return wheels;
    } 
    // 修改指定轮子的半径
    void setWheelRadius(int index, double radius) {
        if (index >= 0 && index < 4) {
            wheels[index].setRadius(radius);
        } else {
            cerr << "Invalid wheel index!" << std::endl;
        }
    }
 
    // 获取指定轮子的半径
    double getWheelRadius(int index) const {
        if (index >= 0 && index < 4) {
            return wheels[index].getRadius();
        } else {
            cerr << "Invalid wheel index!" << std::endl;
            return -1.0; // 返回一个无效值表示错误
        }
    }
 
private:
    Wheel wheels[4]; // 包含一个4个Wheel对象的数组 
};
 
int main() {

    Car myCar;
 
    // 输出初始所有轮子的半径
    for (int i = 0; i < 4; ++i) {
        cout << "Initial radius of wheel " << i + 1 << ": " << myCar.getWheelRadius(i) <<endl;
    }
 
    // 修改第二个轮子的半径为20.0
    myCar.setWheelRadius(1, 20.0);
 
    // 输出修改后所有轮子的半径
    for (int i = 0; i < 4; ++i) {
        cout << "Radius of wheel " << i + 1 << ": " << myCar.getWheelRadius(i) << endl;
    }
    const Wheel* w=myCar.getWheels();
    for (int i = 0; i < 4; ++i) {
        cout << "Radius of wheel " << i + 1 << ": " << w[i].getRadius() << endl;
    }
    return 0;
}
