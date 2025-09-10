#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;
int main(){
  int n;
  while (cin>>n&&n!=0)
  {
    unordered_set<string> names;
    for(int i=0;i<2*n-1;i++){
      string name;
      cin>>name;
      if(names.find(name)==names.end()){
        names.insert(name);
      }
      else {
        names.erase(name); // 如果名字已经存在，则删除
      }
    }

    for(const auto& str:names){
      cout<<str<<endl; // 输出剩余的名字
    }

  }
  return 0;
}
