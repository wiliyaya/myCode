#include <iostream>
using namespace std;
int grade(int mny,char vac,int road)
{
    int result=0;
    result=mny/5000*100;
    if(vac=='y'){
        result+=20;
    }
    if(road<2001){
        result+=100;
    }
    else if(road<3801){ 
    result+=100-(10*(road-2000+200-1)/200);
    }
    return result;
}
int main(){
    int a1,a3,b1,b3,c1,c3,A,B,C;
    char a2,b2,c2;
    cin>>a1>>a2>>a3
    >>b1>>b2>>b3
    >>c1>>c2>>c3;
    A=grade(a1,a2,a3);
    B=grade(b1,b2,b3);
    C=grade(c1,c2,c3);
    if(A>B&&A>C){
        cout<<"A";
    }
    else if(B>A&&B>C){
        cout<<"B";
    }
    else if(C>A&&C>B){
        cout<<"C";
    }
    return 0;


    

}