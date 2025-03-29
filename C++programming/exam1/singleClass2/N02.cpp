#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    if(n==1||n==2){cout<<n;return 0;}
    long long n1=1,n2=2,n3;
    for(int i=3;i<=n;++i){
        n3=n1+n2;
        n1=n2;
        n2=n3;
    }
    cout<<n2;
    return 0;

}