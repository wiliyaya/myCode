#include <iostream>
#include <unordered_map>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main(){
  long long n;
  cin>>n;
  unordered_map<char,char> tele_map={
    {'A','2'}, {'B','2'}, {'C','2'},
    {'D','3'}, {'E','3'}, {'F','3'},
    {'G','4'}, {'H','4'}, {'I','4'},
    {'J','5'}, {'K','5'}, {'L','5'},
    {'M','6'}, {'N','6'}, {'O','6'},
    {'P','7'}, {'R','7'}, {'S','7'},
    {'T','8'}, {'U','8'}, {'V','8'},
    {'W','9'}, {'X','9'}, {'Y','9'}
  };

  map<string,int> tele_book;
  while(n--){
    string tele_numbers;
    cin>>tele_numbers;
    string res_numbers;
    for(char c:tele_numbers){
      if(c>='0' && c<='9'){
        res_numbers+=c; // 如果是数字，直接添加
      }
      else if(c>='A' && c<'Z' && c!='Q' ){
        res_numbers+=tele_map[c]; // 如果是字母，转换为对应的数字
      }
    }
    if(res_numbers.size()==7){
      res_numbers.insert(3,"-"); // 在第4个位置插入'-'
      tele_book[res_numbers]++; // 统计电话号码出现的次数
    }
  }

  for(const auto& entry: tele_book){
    if(entry.second > 1){ // 如果电话号码出现超过一次
      cout<<entry.first<<" "<<entry.second<<endl; // 输出电话号码和出现次数
    }
  }

  return 0;
}




