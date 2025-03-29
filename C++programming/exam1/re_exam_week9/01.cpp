#include <iostream>
#include <string>
using namespace std;
int main(){
    string s,t;
    getline(cin,s);
    getline(cin,t);
    size_t pos=s.find(t);
    if(pos!=string::npos){
        cout<<pos<<endl;
    }
    else cout<<"-1"<<endl;
    return 0;
}