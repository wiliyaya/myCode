#include <iostream>
using namespace std;
int main(){
    int mny,sub,jiao=0;
    cin>>mny>>sub;
    if(mny>5000){
        if((mny-5000)<3001){
            jiao=(mny-5000-sub)*0.03;
        }
        else if((mny-5000)<12001){
            jiao=(mny-5000-sub)*0.1-210;
        }
        else if((mny-5000)<25001){
            jiao=(mny-5000-sub)*0.2-1410;
        }
        else if((mny-5000)<35001){
            jiao=(mny-5000-sub)*0.25-2660;
        }
        else if((mny-5000)<55001){
            jiao=(mny-5000-sub)*0.3-4410;
        }
        else if((mny-5000)<80001){
            jiao=(mny-5000-sub)*0.35-7160;
        }
        else jiao=(mny-5000-sub)*0.45-15160;
    }
    cout<<jiao;
    return 0;
}