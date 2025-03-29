#include <iostream>
using namespace std;
int main(){
    int m,n,a,min;
    cin>>m>>n;
    int miny[m];
    for(int i=0;i<m;i++){
        cin>>min;
        for(int I=1;I<n;I++){
            cin>>a;
            if(a<min){
                min=a;
            }
        }
        miny[i]=min;
    }
    for(int k=0;k<m;k++){
        cout<<miny[k]<<endl;
    }
    return 0;
}