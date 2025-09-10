#include <iostream>
#include <string>
#include <map>
using namespace std; 

bool is_ThreeSort(string str){
  bool number=false,zimu=false,other=false;
  for(char c:str){
    if(c>='0'&&c<='9'){
      number=true;
    }
    else if((c>='a'&&c<='z')||(c>='A'&&c<='Z')){
      zimu=true;
    }
    else{
      other=true;
    }
  }
  if(number&&zimu&&other){
    return true;
  }else {
    return false;
  }

}

bool is_highSave(string str){
    int size=str.size();
    
    //判断是否同一个字符出现次数不超过俩次
    map<char,int> str_c;
    for(int i=0;i<size;i++){
      str_c[str[i]]++;
      if(str_c[str[i]]>2){
        return false;
        break;
      }
    }
    return true;
}

int main(){
  int n;
  cin>>n;
  while(n--){
    string str;
    cin>>str;
    bool flag1=is_ThreeSort(str);
    bool flag2=is_highSave(str);
    if(flag1&&flag2){
      cout<<'2'<<endl;
    }
    else if(flag1){
      cout<<'1'<<endl;
    }
    else{
      cout<<'0'<<endl;
    }
  }
  return 0;
}

