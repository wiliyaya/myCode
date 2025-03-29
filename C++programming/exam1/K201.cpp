#include <iostream>
using namespace std;
int perfect(int n){
    int result=0;
    for(int i=1;i<n;i++){
        if(n%i==0){
            result+=i;
        }
    }
    return result;
}
int main(){
    int n,f;
    cin>>n;
    f=perfect(n);
    if(n==f){
        cout<<"true";
    }
    else cout<<"false";
    cout<<endl;
    return 0;
}