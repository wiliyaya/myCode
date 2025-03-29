#include <iostream>
#include <string>
using namespace std;
int main(){
    string s;
    string t;
    getline(cin,s);
    getline(cin,t);
    int found=s.find(t);
    if(found!=string::npos){
        cout<<found;
    }
    else {
        cout<<"-1"<<endl;
    }
    return 0;
    
}