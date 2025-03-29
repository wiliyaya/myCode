#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int j=1;
    for(int i=10;;i=i*10){
        
        if(n/i==0){
            cout<<j;
            break;
        }
        else j++;
    }
    return 0;
}