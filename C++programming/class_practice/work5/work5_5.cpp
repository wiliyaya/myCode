#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int sum=0;
    int gift[n];
    for(int i=0;i<n;i++){
        cin>>gift[i];
        if(gift[i]%4==0||gift[i]%7==0){
            sum+=gift[i];
        }
    }
    cout<<sum<<endl;
    return 0;

}