#include <iostream>
using namespace std;
int main(){
    int n,u,d;
    while(cin>>n)
    {
        if(n==0)
        {return 0;}
        cin>>u>>d;
        int w=0;
        int time=0;
        w=((n-u)+(u-d)-1)/(u-d);
        time=w*2+1;
        cout<<time<<endl;
    }
}