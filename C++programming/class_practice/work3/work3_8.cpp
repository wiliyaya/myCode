#include <iostream>
using namespace std;
int main(){
    int n,num=0;
    int arr[4]={0};
    char symbol;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>symbol;
        if(symbol>64&&symbol<91){
            arr[0]++;
        }
        else if(symbol>96&&symbol<123){
            arr[1]++;
        }
        else if(symbol>47&&symbol<58){
            arr[2]++;
            num+=int(symbol)-48;
        }
        else arr[3]++;
    }
    cout<<arr[0]<<' '<<arr[1]<<' '<<arr[2]<<' '<<arr[3]<<endl;
    if(num!=0){cout<<num;}
    return 0;

}