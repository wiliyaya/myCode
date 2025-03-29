#include <iostream>
using namespace std;
int main(){
    int n,n1,grade=0;
    cin>>n;
    char color;
    for(int i=0;i<n;i++){
    cin>>color;
    switch(color){
        case 'y':grade+=2;break;
        case 'g':grade+=3;break;
        case 'c':grade+=4;break;
        case 'b':grade+=5;break;
        case 'p':grade+=6;break;
        case 'B':grade+=7;break;
        case 'r':cin>>n1;grade+=n1;break;
    }
    }
    cout<<grade<<endl;
    return 0;
}