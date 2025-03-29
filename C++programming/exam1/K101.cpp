#include <iostream>
using namespace std;
int main(){
    int k=0,n,w,need=0;
    cin>>k>>n>>w;
    for(int i=1;i<w+1;i++){
        need=need+i*k;
    }
    if(need-n<0){
        cout<<'0'<<endl;
    }
    else cout<<need-n<<endl;
    return 0;

}