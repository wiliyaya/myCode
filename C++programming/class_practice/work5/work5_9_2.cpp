#include <iostream>
using namespace std;
int main(){
    int n=0,c=0;
    cin>>n>>c;
    int *r=new int[n];
    for(int i=0;i<n;i++){
        cin>>r[i];
    }
    int *conflict=new int[c][2];
    for(int i=0;i<c;i++){
        for(int j=0;j<2;j++){
            cin>>conflict[i][j];
        }
    }
    

}