#include <iostream>
#include <string>
#include <map>
using namespace std;

string str_replace(string str1,map<char,char>& f,int num){
  int size=str1.size();
  while(num--){
    string str3;
    for(int i=0;i<size;i++){
      str3+=f[str1[i]];
    }
    // cout<<str3<<endl;
    str1.swap(str3);//这样写比直接str1=str3性能好
  }
  return str1;
}

int main(){
  string str1;
  getline(cin,str1);
  int n;
  cin>>n;
  cin.ignore();
  map<char,char> f;
  //先初始化让str1的每个字符映射到自己
  for(char c :str1){
    f[c]=c;
  }
  for(int i=0;i<n;i++){
    string str2;
    getline(cin,str2);
    f[str2[1]]=str2[2];
  }

  int m;
  cin>>m;
  while(m--){
    int num;
    cin>>num;
    cout<<str_replace(str1,f,num)<<endl;
  }
  return 0;
}