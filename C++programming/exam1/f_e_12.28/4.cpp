#include <iostream>
using namespace std;

int SucceedUp(int n)
{
    if(n<=0)
    {return n;}
    if(n%2!=0)
    {
        n=n-1;
    }
    n=n/2;
    int n1=n;
     n=SucceedUp(n);
    return n1+n;
}

int main()
{
    int T;
    cin>>T;
    for(int I=0;I<T;I++)
    {
        int n,k;
        cin>>n>>k;
        for(int i=1;i<k;i++)
        {
            if(n<=0)
            {
                break;
            }
            else
            {
                n=SucceedUp(n);
            }
        }
        cout<<n<<endl;

    }
    return 0;
}