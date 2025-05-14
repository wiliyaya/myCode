#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> build_next(const string& pattern)
{
  int m=pattern.size();
  vector<int> next(m,0);//初始化全为0的next数组
  // int j=0; //前缀指针
  next[0]=-1;
  for(int i=0;i<m;i++)//i为后缀指针
  {
    int j=next[i-1];  //每次的j都由上一个已经求得得next[i-1]来给，后面就不用考虑j的变化
    //当 前缀字符不匹配时，回溯到前一个匹配位置
    while(j>=0&&pattern[i]!=pattern[j+1])//这里的j代表的其实是正在配对的字符的索引-1，也就是正在配对的字符的前一个字符
    {
      j=next[j];
    }

    //匹配成功时，给next数组赋值
    if(pattern[i]==pattern[j+1])
    {
      next[i]=j+1;
    }
    // 若找不到匹配的，就赋值为-1
    else {next[i]=-1;}

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
  int j=0;
  int i=0;
  while(j<n&&i<m){
    if(text[j]==pattern[i]){
      j++;
      i++;
    }
    else if(i>0){
      i=next[i-1]+1;  //在子串中回溯，如果为-1，就说明没有前缀可以匹配
    }
    else {j++;} //这时候就可以把j后移
  }

  if(i==m){    //成功遍历子串，匹配成功
    
     positions.push_back(j-m); //这里只能输出一个值，暂时先不管了
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