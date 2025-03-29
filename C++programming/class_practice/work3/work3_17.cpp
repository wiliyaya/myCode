#include <iostream>
using namespace std;
int main(){
    int t=0,distance=0;
    cin>>t>>distance;
    switch(distance/250){
        case 0:cout<<t*distance;break;
        case 1:cout<<t*distance*0.98;break;
        case 2:
        case 3:cout<<t*distance*0.95;break;
        case 4:
        case 5:
        case 6:
        case 7:cout<<t*distance*0.92;break;
        case 8:
        case 9:
        case 10:
        case 11:cout<<t*distance*0.9;break;
        default:cout<<t*distance*0.85;
    }
    return 0;

}