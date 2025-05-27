#include <iostream>
#include <vector>
using namespace std;

class MyHashSet {
private :
  vector<int> bs;
  MyHashSet(){
    bs.resize(40000);
  }

public:
//通过设val是true还是false，来决定操作是增还是删
  void setVal(int bucket,int loc, bool val){
    if(val){
      int u=bs[bucket] | (1<<loc);
      bs[bucket]=u;
    }
    else {
      int u=bs[bucket] & ~(1<<loc);
      bs[bucket] = u;
    }
  }

//判断某个位置所对应的元素是否存在
bool getVal(int bucket,int loc){
  int u=(bs[bucket]>> loc) & 1;
  return u==1;
}


  void add(int key){
    int bucketIdx = key /32; //桶的索引
    int bitIdx = key % 32; //桶内的索引
    setVal(bucketIdx,bitIdx,true);
  }

  void remove(int key){
    int bucketIdx = key /32; //桶的索引
    int bitIdx = key % 32; //桶内的索引
    setVal(bucketIdx,bitIdx,false);
  }

  bool contains(int key){
    int bucketIdx = key /32; //桶的索引
    int bitIdx = key % 32; //桶内的索引
    return getVal(bucketIdx,bitIdx);
  }
 };