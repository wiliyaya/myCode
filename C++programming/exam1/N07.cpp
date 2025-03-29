#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    int a,b,c,d,e,f,A,B,C;
    char g;
        cin>>a>>g>>b>>g>>c
    >>d>>g>>e>>g>>f;
    C=d*3600+e*60+f-a*3600-b*60-c;
    A=C/3600;
    B=(C-A*3600)/60;
    C=C-A*3600-B*60;
    cout<<A<<':'<<setfill('0')<<setw(2)<<B<<':'<<setfill('0')<<setw(2)<<C<<endl;
    return 0;
}