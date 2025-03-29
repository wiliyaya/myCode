#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> build_next(const string& pattern)
{
  int m=pattern.size();
  vector<int> next(m,0);//初始化全为0的next数组
  int j=0; //前缀指针
  for(int i=0;i<m;i++)//i为后缀指针
  {
    //当 前缀字符不匹配时，回溯到前一个匹配位置
    while(j>0&&pattern[i]!=pattern[j])
    {
      j=next[j-1];
    }

    //匹配成功时，前缀指针后移
    if(pattern[i]==pattern[j])
    {
      ++j;
    }

    //更新next数组的值
    next[i]=j;
    //呃，如果按照教材的话应该要为j-1
  }
  return next;

}

vector<int> KMP_search(const string& text,const string& pattern)
{
  vector<int> positions;
  int n=text.size();
  int m=pattern.size();
  if(m==0||n<m) return positions;

  vector<int> next=build_next(pattern);
  int j=0;//模式串指针

  for(int i=0;i<n;i++)//i为主串指针
  {
    //
    while(j>0 && text[i]!=pattern[j])
    {
      j=next[j-1];
    }

    //字符匹配时，模式串指针后移
    if(text[i]==pattern[j])
    {
      j++;
    }
    //找到完全匹配的情况
    if(j==m)
    {
      positions.push_back(i-m+1);//记录起始位置
      j=next[j-1];//继续寻找下一个匹配
    }
  }
  return positions;
}

int main(){
  string text;
  string pattern;
  getline(cin,text);
  getline(cin,pattern);

  vector<int> result=KMP_search(text,pattern);

  if(!result.empty())
  {
    cout<<"起始位置是：";
    for(int pos : result)
    {
      cout<<pos<<" ";
    }
  }
  else {
    cout<<"未找到匹配项";
  }
  return 0;
}