#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    char *arr=new char[n];
    for(int i=0;i<n;i++){
        cin>>char[i];
    }
    sort(arr,arr+n);
    reverse(arr,arr+n);
    int count=1;
    for(int i=1;i<n;i++){
        if(arr[i]==arr[i-1]){
            count++;
        }
        else {cout<<arr[i-1]<<":"<<count<<' ';
        count=1;}
    }
    cout<<arr[n-1]<<':'<<count<<' '<<endl;
    return 0;

}