#include <iostream>
using namespace std;
int main()
{
    int X;
    cin>>X;
    int sum=0;
    for(int i=1;i<=X;i++)
    {
        if(X%i==0)
        {sum+=i;}
    }
    cout<<sum<<endl;
    return 0;
}