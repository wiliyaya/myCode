#include <iostream>
using namespace std;
int main(){
    int N,n;
    cin>>N;
    int day[6];
    for(int i=0;i<N;i++){
        cin>>n;
        switch(n){
            case 1:day[0]++;break;
            case 2:day[1]++;break;
            case 3:day[2]++;break;
            case 4:day[3]++;break;
            case 5:day[4]++;break;
            case 6:day[5]++;break;
        }
    }
    cout<<"晴天："<<day[0]<<endl
    <<"多云："<<day[1]<<endl
    <<"阴天："<<day[2]<<endl
    <<"小雨："<<day[3]<<endl 
    <<"中雨："<<day[4]<<endl
    <<"大雨："<<day[5]<<endl;
    return 0;
}