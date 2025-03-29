#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    if(n%3==0&&n%5==0&&n%7==0){
        cout<<"It's divisible by 3,5,7";
    }
     else if(n%3==0&&n%5==0){
        cout<<"It's divisible by 3,5";
     }
     else if(n%5==0&&n%7==0){
        cout<<"It's divisible by 5,7";
     }
     else if(n%3==0&&n%7==0){
        cout<<"It's divisible by 3,7";
     }
     else if(n%3==0){
        cout<<"It's divisible by 3";
     }
     else if(n%5==0){
        cout<<"It's divisible by 5";
     }
     else if(n%7==0){
        cout<<"It's divisible by 7";
     }
     else cout<<"null";
     return 0;

}