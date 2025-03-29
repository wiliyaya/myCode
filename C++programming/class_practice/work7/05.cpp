#include <iostream>
#include <string>
using namespace std;
int main(){
    string s;
    cin>>s;
    string t;
    cin>>t;
    int times=0;
    while(t!=s){
        if(t.size()>s.size()){
            t=t.erase(0,1);
        }
        else {
            s=s.erase(0,1);
        }
        times++;
    }
    cout<<times<<endl;
    return 0;
}