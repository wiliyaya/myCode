#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    int mny,sub;
    double up=0.0;
    cin>>mny>>sub;
    if(mny<5001){
        cout<<'0';
    }
    else if(mny-5000<3001){
        up=(mny-5000-sub)*0.03;
    }
    else if(mny-5000<12001){
        up=(mny-5000-sub)*0.1-210;
    }
    else if(mny-5000<25001){
        up=(mny-5000-sub)*0.2-1410;
    }
    else if(mny-5000<35001){
        up=(mny-5000-sub)*0.25-2660;
    }
    else if(mny-5000<55001){
        up=(mny-5000-sub)*0.3-4410;
    }
    else if(mny-5000<80001){
        up=(mny-5000-sub)*0.35-7160;
    }
    else up=(mny-5000-sub)*0.45-15160;
    cout<<fixed<<setprecision(0)<<up;
    return 0;
}