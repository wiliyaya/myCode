// 树的高度最小，通常需要让树尽可能的“满”，也就是每个可能的层都被填满，或者尽量多的节点分布在较高的层。比如，满二叉树的高度是最小的，但这里可能因为节点的类型不同而不同。
#include <iostream>
#include <algorithm>
// #include <bits/stdc++.h>
using namespace std;

int minHeight(int a,int b,int c){
  //边数=节点数-1，a类节点贡献两条边，b类贡献一条边，2a + b = (a + b + c) - 1
  if(c!=a+1){
    return -1;
  }

  int a_remain=a;
  int b_remain=b;
  int c_remain=c;

  int current_nodes=1;
  int height=0;

  while(current_nodes>0){
    int x=min(current_nodes,a_remain);//这行中最多使用的a类节点的数量
    int y=min(current_nodes-x,b_remain);//这行中最多使用的b类节点的数量
    int z=current_nodes-x-y;//剩下的必须用z来填满

    if(z>c_remain){
      return -1;
    }

    a_remain-=x;
    b_remain-=y;
    c_remain-=z;
    
    int next_nodes=2*x+y;
    if(next_nodes!=0){
      height++;
      current_nodes=next_nodes;
    }
    else {
      current_nodes=0;
    }
  }

  if(a_remain==0&&b_remain==0&&c_remain==0){
    return height;
  }
  else return -1;
}

int main(){
  int T;
  cin>>T;
  for(int i=0;i<T;i++){
    int a=0;
    int b=0;
    int c=0;
    cin>>a>>b>>c;
    cout<<minHeight(a,b,c)<<endl;
  }
  return 0;
}