#include <iostream>
using namespace std;
int main(){
    int y1,y3,y2,m1,m2,m3,d1,d2,d3,c1,c2,c3;
    cin>>y1>>m1>>d1
    >>y2>>m2>>d2 
    >>y3>>m3>>d3;
    c1=y1*365+m1*30+d1;
    c2=y2*365+m2*30+d2;
    c3=y3*365+m3*30+d3;
    if(c1<c2&&c1<c3){
        if(c2<c3)cout<<"ABC";
        else cout<<"ACB";
    }
    if(c2<c1&&c2<c3){
        if(c1<c3)cout<<"BAC";
        else cout<<"BCA";
    }
    if(c3<c1&&c3<c2){
        if(c1<c2)cout<<"CAB";
        else cout<<"CBA";
    }
    return 0;

}