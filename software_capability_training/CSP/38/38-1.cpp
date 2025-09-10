#include <iostream>
using namespace std;
//此代码的浮点数精度存在问题，还没改
int main(){
  int k;cin>>k;
  for(int i=0;i<k;i++){
    int u,o,n;
    cin>>u>>o>>n;
    double Z=1.0*(n-u)/o;
    //计算行
    double row=(static_cast<int>(Z*10))/10.0 ;
    int rK_row=row/0.1;
    //计算列
    double column=(static_cast<int>((Z-row)*100)/100.0);
    int rk_column=column/0.01;
    cout<<rK_row+1<<' '<<rk_column+1<<endl;
  }
  return 0;
}