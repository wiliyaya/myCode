#include <iostream>
using namespace std;
int main(){
    int num,n=1,a=1;
    cin>>num;
    if(num>2147483647&&num<-21147483648){
        cout<<'0';
    }
    else
    for(int i=1;num/n!=0;i++){
        n=n*10;
    }
    if(num<0){
        cout<<'-';
        num=-num;
    }
    for(;a<n;){
        cout<<(num/a)%10;
        a=a*10;
    }
    return 0;
}