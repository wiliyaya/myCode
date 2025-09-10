#include <iostream>
#include<string>
#include <stack>
// #include <vector>
// #include <algorithm>
#include <sstream>
using namespace std;

int main(){
  string str;
  while(getline(cin,str)){
    istringstream iss(str);
    string word;
    stack<string> wordStack;
    while(iss>>word){
        wordStack.push(word); // 将单词压入栈中
    }
    while(!wordStack.empty()){
      cout<<wordStack.top()<<' ';
      wordStack.pop(); // 输出栈顶单词并弹出
    }
    cout<<endl;

  }

  return 0;
}