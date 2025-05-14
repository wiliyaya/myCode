#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;//叶子节点个数
  while(cin>>n){
      if(n==0) break;
      if(n==1){cout<<0<<endl;continue;}
      vector<int>leaf(n);
      //问题又来了，我怎么判断它刚好属于2的p次方里的？用对数取整？
      int maxlevel=ceil(log2(n));
      int minlevel=floor(log2(n));
      //bool full=(pow(2,maxlevel)==n);
      bool full=((1<<maxlevel)==n);
      //学到了位运算，原来1<<n代表的就是pow(2,n)，那么我们可以修改一下更高效

      for(int i=0;i<n;i++){
          cin>>leaf[i];
      }
      sort(leaf.begin(),leaf.end());
      reverse(leaf.begin(),leaf.end());
      long long WPL=0;
      if(full){
          for(int i=0;i<n;i++){
              WPL+=leaf[i]*maxlevel;
          }
      }
      else{
          int deepleaf=n-(1<<minlevel);
          int upleaf=(1<<minlevel)-deepleaf;
          for(int i=0;i<upleaf;i++){
              WPL+=leaf[i]*minlevel;
          }
          for(int i=upleaf;i<n;i++){
              WPL+=leaf[i]*maxlevel;
          }
      }
      cout<<WPL<<endl;

  }
  return 0;
}