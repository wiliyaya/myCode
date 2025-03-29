#include<iostream>
using namespace std;
class SeqList {
private:
  int* data; //存储数据的数组
  int length;//当前元素个数
  int capacity;//数组总容量
public:
  //构造函数，根据给定数组初始化顺序表
  SeqList(const int* arr,int len,int cap){
    capacity=(cap>=len) ? cap:len ; //确定容量不小于初始长度
    data=new int[capacity];// 动态分配内存
    length=len;
    for(int i=0;i<length;i++){
      data[i]=arr[i];   //复制数据
    }
  }

  //析构函数
  ~SeqList(){
    delete[] data;
  }

  //删除所有值为x的元素
  void deletaValue(int x){
    int slow=0;
    for(int fast=0;fast<length;fast++){
      if(data[fast]!=x){
        data[slow++]=data[fast]; //保留非x元素
      }
    }
    length=slow; //更新长度
  }

  //打印顺序表元素
  void print() const{
    for(int i=0;i<length;i++){
      cout<<data[i]<<' ';
    }
    cout<<endl;
  }
};

int main(){
  int arr[]={1,2,3,4,5};
  SeqList list(arr,5,10);

  list.deletaValue(2);

  list.print();
  return 0;
}