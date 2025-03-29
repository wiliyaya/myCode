#include <iostream>
using namespace std;
int main(){
    int n=0,k=1,num;
    cin>>n;
    for(int i=0;i<n-1;i++){
        k=k*2;
    }
    num=3*k-2;
    cout<<num<<endl;
    return 0;


}