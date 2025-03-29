#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    char a[100];
    char t;
    for(int i=0;i<n;i++){
        cin>>a[i];
    } 
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]<a[j]){
                t=a[i];
                a[i]=a[j];
                a[j]=t;
            }
        }
    }
    int count=1;
    for(int i=1;i<n;i++){
        if(a[i]==a[i-1]){
            count++;

        }else {cout<<a[i-1]<<":"<<count<<" ";
        count=1;}
        count<<a[n-1]<<":"<<count<<endl;
        return 0;
    }
}