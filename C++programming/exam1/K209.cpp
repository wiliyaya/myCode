#include <iostream>
using namespace std;
int main(){
    int t=0,I=0;
    cin>>t;
    int s[t];
    int N,K;
    while(t--){
        cin>>N>>K;
        int T[N];
        int D[N];
        int sum=0;
        for(int i=0;i<N;i++){
            cin>>T[i]>>D[i];
            sum+=T[i]*D[i];
        }
        s[I]=sum-K;
        I++;
    }
    for(int i=0;i<I;i++){
        cout<<s[i]<<endl;
    }
    return 0;
}