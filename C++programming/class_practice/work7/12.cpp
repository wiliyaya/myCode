#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main(){
    string str;
    getline(cin,str);
    int posa;

    for(int i=0;i<str.size();i++)
    {
        posa=str.find("@",posa);
    }
    return 0;
}