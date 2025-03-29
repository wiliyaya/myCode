#include <iostream>
using namespace std;
int main(){
    char word;
    cin>>word;
    if(word>='A'&&word<='Z'){
        cout<<char(word+32);
    }
    else cout<<char(word-32);
    return 0;
}