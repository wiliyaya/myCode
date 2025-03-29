#include <iostream>
using namespace std;
int main(){
    long long w;
    cin>>w;
    if(w==2||w==1){
        cout<<"No";
    }
    else if(w%2==0){
        cout<<"Yes";
    }
    else cout<<"No";
    return 0;
}
