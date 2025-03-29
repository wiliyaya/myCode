#include <iostream>
using namespace std;
int number(int n){
    int result=0;
    for(int i=1;i<n;i++){
        if(n%i==0)
        result+=i;
    }
    return result;
}
int main(){
    int s,a;
    cin>>s;
    for(; ;s++){
        a=number(s);
        if(number(a)==s){
        cout<<s<<' '<<a<<endl;
        break;}
    }
   return 0;
}