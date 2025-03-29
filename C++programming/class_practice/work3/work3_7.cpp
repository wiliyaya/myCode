#include <iostream>
using namespace std;
int main(){
    int a,c;
    char mny;
    cin>>a>>mny>>c;
    bool n1= a>4999;
    bool n2= mny=='y';
    bool n3=c<2001;
    if(n1&&n2&&n3){
        cout<<"Accept";
    }
    else if((n1&&n2)||(n1&&n3)||(n2&&n3)){
        cout<<"Accept";
    }
    else cout<<"Refuse";
    return 0;

}