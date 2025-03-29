#include <iostream>
#include <string>
using namespace std;
int main(){
    string s;
    string t;
    getline(cin,s);
    getline(cin,t);
    if(s.find(t,0)!=string::npos){
        cout<<s.find(t,0);
    }
    else cout<<"-1";
}