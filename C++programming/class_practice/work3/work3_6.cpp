#include <iostream>
using namespace std;
int main(){
    int N;
    cin>>N;
    switch(N/10){
        case 6:cout<<'D';break;
        case 7:cout<<'C';break;
        case 8:cout<<'B';break;
        case 9:
        case 10:cout<<'A';break;
        default:cout<<'E';
    }
    return 0;
}