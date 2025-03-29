#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int I=10;
    for(int i=1;;i++){
        if(n/I==0){
            cout<<i<<endl;
            break;
        }
        else I=I*10;
    }
    return 0;
}