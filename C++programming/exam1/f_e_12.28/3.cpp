#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int num=0;
    for(int i=0;i<n;i++)
    {
        int C,S;
        cin>>C>>S;
        if(C<S)
        {num++;}
    }
    cout<<num<<endl;
    return 0;
}