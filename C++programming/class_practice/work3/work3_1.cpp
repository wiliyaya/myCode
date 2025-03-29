#include <iostream>
using namespace std;
int main(){
    int N,n,grade=0;
    char color;
    cin>>N;
    for(int i=0;i<N;i+=n){
        cin>>color;
        switch(color){ 
            case 'r':cin>>n;
            grade+=n;break;
            case 'y':grade+=2;break;
            case 'g':grade+=3;break;
            case 'c':grade+=4;break;
            case 'b':grade+=5;break;
            case 'p':grade+=6;break;
            case 'B':grade+=7;break;
        }
    
    }
    cout<<grade;
     return 0;   
        
        
        
}