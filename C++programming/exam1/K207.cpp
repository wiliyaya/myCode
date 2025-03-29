#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int begin=0,end;
    int time=0;
    while(n--){
        cin>>end;
        if(end>begin){
            time+=(end-begin)*6+5;
        }
        else time+=(begin-end)*4+5;
        begin=end;
    }
    cout<<time;
}