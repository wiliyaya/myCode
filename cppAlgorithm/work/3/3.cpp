#include<iostream>
#include<string>
using namespace std;

void Order(string& pre,string& in){
  //如果长度为空则树为空
  if(pre.size()==0||in.size()==0){
    return;
  }

  char root=pre[0];//前序遍历的第一个字符为根节点
  int pos=in.find(root);//中序遍历中找到根节点的位置

  string in_left=in.substr(0,pos);
  string in_right=in.substr(pos+1);

  string pre_left=pre.substr(1,in_left.length());
  string pre_right=pre.substr(in_left.length()+1);

  Order(pre_left,in_left);
  Order(pre_right,in_right);
  cout<<root;

}

int main(){
  while(true){
    int n=0;
    cin>>n;
    if(n==0){break;}
    string pre;
    string in;
    cin>>pre>>in;
    Order(pre,in);
    cout<<endl;
  }
  return 0;
}