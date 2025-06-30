#include <iostream>
using namespace std;
int main(){
  unsigned int n, cnt=0;
    cin>>n;
    
    short a, b, c;
    while(n--)
    {
        cin>>a>>b>>c;     // 输入每行
        int n1=0;
        if(a==1) n1++;
        if(b==1) n1++;
        if(c==1) n1++;
        if(n1>=2) cnt++;  // 如果有两个或以上的1，则计数器加1
    }
    
    cout<<cnt<<endl;
    return 0;
}