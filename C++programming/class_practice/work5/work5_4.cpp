#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n][2];
    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
            cin>>arr[i][j];
        }
    }
    int right=arr[0][1],left=arr[0][0];
    for(int i=0;i<n;i++){
        if(arr[i][0]<left){
            left=arr[i][0];
        }
    }
    for(int i=0;i<n;i++){
        if(arr[i][1]>right){
            right=arr[i][1];
        }
    }
    int num[right-left+1];
    for(int i=0;i<right-left+1;i++){
        num[i]=0;
    }
    for(int i=0;i<n;i++){
        int k=arr[i][0];
        while(k<=arr[i][1]){
            num[k-left]++;
            k++;
        }
    }
    int cover[n];
    for(int i=0;i<n;i++){
        cover[i]=0;
    }
    for(int i=0;i<right-left+1;i++){
        for(int j=0;j<n;j++){
            if(num[i]==j+1){
                cover[j]++;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<cover[i]<<" ";
    }
    return 0;

}