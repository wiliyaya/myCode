#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    cout<<a<<'+'<<b<<'+'<<c<<'='<<a+b+c<<endl
    <<"平均值是"<<fixed<<setprecision(2)<<(a+b+c)*1.00/3<<endl
    <<a<<'*'<<b<<'*'<<c<<'='<<a*b*c;
    return 0;
}