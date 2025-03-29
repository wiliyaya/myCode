#include <iostream>
using namespace std;
int main(){
    int distance=0;
    double biketime=0.0,walktime=0.0;
    cin>>distance;
    biketime=(distance*1.0)/3.0+50;
    walktime=(distance*1.0)/1.2;
    if (biketime>walktime){
        cout<<"Walk";
    }
    else if(biketime<walktime){
        cout<<"Bike";
    }
    else cout<<"All";
    return 0;
}