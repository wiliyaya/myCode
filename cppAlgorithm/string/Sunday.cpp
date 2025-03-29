#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> Sunday(const string& text,const string& pattern)
{
  vector<int> matches;//储存匹配位置的数组
  size_t m=pattern.size();
  size_t n=text.size();

  //处理空子串情况
  if(m==0 || n<m)
  {
    return matches;
  }

  //1.预处理阶段：建立偏移表
  unordered_map<char,size_t> shift_table;
  for(size_t i=0;i<m;i++)
  {
    //记录每个字符最后一次出现的偏移量
    shift_table[pattern[i]]=m-i;
  }

  // 2.匹配阶段
  size_t i=0; //主串当前的搜索位置
  while(i<=n-m){
    //检查当前窗口是否匹配
    bool match=true;
    for(size_t j=0;j<m;j++)
    {
      if(text[i+j]!=pattern[j])
      {
        match=false;
        break;
      }
    }
    if(match){
      matches.push_back(i);//匹配成功，储存位置
    }

    // 计算移动步长
    if(i+m>=n) break;//已达到主串位置

    char next_char=text[i+m];//主串中下一个字符的位置
    //用三元运算符来判断主串的下一个字符在子串中是否存在
    size_t shift=shift_table.count(next_char) ? shift_table[next_char] : m+1;

    i+=shift;//移动子串的位置
  }
  return matches;
}

int main(){
  string text;
  string pattern;
  getline(cin,text);
  getline(cin,pattern);

  vector<int> result=Sunday(text,pattern);
  for(int pos:result)
  {
    cout<<pos<<' ';
  }
  return 0;
}