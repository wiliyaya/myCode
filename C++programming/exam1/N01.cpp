#include <iostream>
using namespace std;
int main(){
    int n=0,a=0,min;
    cin>>n;
    cin>>min;
    for(int i=1;i<n;i++){
        cin>>a;
        if(a<min){
            min=a;
        }
    }
    cout<<min<<endl;
    return 0;
}