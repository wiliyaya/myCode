#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <cctype>
using namespace std;

//解析表达式并判断是否合法
bool token(string &str,vector<string>& tokens)
{
  // vector<string> tokens;
  size_t pos = 0;
  while (pos < str.size())
  {
    char c = str[pos];
    if(c=='#'&&pos==str.size()-1){
      break;
    }
    if (isdigit(c))
    {
      string num;
      while (pos < str.size() && isdigit(c))
      {
        num += c;
        pos++;
        c=str[pos];
      }
      tokens.push_back(num);
    }
    else 
      if(c=='+'||c=='-'||c=='*'||c=='/'||c=='('||c==')'){
        tokens.push_back(string(1,c));
        pos++;
      }
    
    else {
      cerr<<"NO"<<endl;
      return false;
    }
  }
  return true;
}

//自定义一个函数来比较优先级
int precedence(const string& op){
  if(op=="+"||op=="-") return 1;
  if(op=="*"||op=="/") return 2;
  return 0;
}

//把中缀表达式转化为后缀表达式
vector<string> ItoP(vector<string>& infix_expr){
  vector<string> postfix_expr;
  stack<string> op_stack;
  for(const auto& token:infix_expr){
    if(isdigit(token[0])){
     postfix_expr.push_back(token);//遇到数字直接输入到postfix_expr序列中 
    }
    else if(token =="+"||token=="-"||token=="*"||token=="/"){
      while(!op_stack.empty()&& op_stack.top()!="("&& precedence(op_stack.top())>=precedence(token)){
        postfix_expr.push_back(op_stack.top());
        op_stack.pop();
      }
      op_stack.push(token);
    }
    else if(token=="("){
      op_stack.push(token);
    }
    else if(token==")"){
      if(op_stack.empty()){
        cerr<<"error"<<endl;
        break;
      }
      while (!op_stack.empty()&&op_stack.top()!="(")
      {
        postfix_expr.push_back(op_stack.top());
        op_stack.pop();
      }
      if(op_stack.top()!="("){
        cerr<<"error";
      }
      else {
        op_stack.pop();
      }
    }
  }

  while(!op_stack.empty()){
    if(op_stack.top()=="("){
      cerr<<"error";
    }
    postfix_expr.push_back(op_stack.top());
    op_stack.pop();
  }
  return postfix_expr;
}

//打印函数
void print(vector<string>& v){
  for(const auto& t:v){
    cout<<t<<" ";
  }
  cout<<endl;
}


int op_cal(int num2,string& s,int num1){
  int result=0;
  switch (s[0])
  {
  case '+':
    result=num2+num1;
    break;
  case '-':
    result=num2-num1;
    break;
  case '*':
    result=num2*num1;
    break;
  case '/':
    result=num2/num1;
    break;
  }
  return result;
}

//计算后缀表达式
int cal_postfix_expr(vector<string>& postfix_expr){
  stack<int> s;
  for( auto& item :postfix_expr){
    if(isdigit(item[0])){
      s.push(stoi(item));
    }
    else {
      int num1=s.top();
      s.pop();
      int num2=s.top();
      s.pop();
      int result=op_cal(num2,item,num1);
      s.push(result);
    }
  }
  return s.top();
}


int main()
{
  string str;
  getline(cin, str);
  
  //解析表达式并判断是否合法
  vector<string> infix_expr;
  bool isTrue=token(str,infix_expr);
  if(isTrue){
    vector<string> post_expr=ItoP(infix_expr);
    // print(post_expr);
    int result=cal_postfix_expr(post_expr);
    cout<<result;
  }
  else {
    cout<<"NO";
  }

  return 0;
}