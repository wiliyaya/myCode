#include <iostream>
using namespace std;
int main(){
    int n,num=0,f=0;
    cin>>n;
    for(int i=1;i<n+1;i++){
        f+=i;
        num+=f;
    }
    cout<<num;
}