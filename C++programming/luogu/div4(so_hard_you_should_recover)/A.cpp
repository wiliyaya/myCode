#include <iostream>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    if(a%10<b)
    {
        cout<<b-a%10;
    }
    else if(a%10==b)
    {
        cout<<'0';
    }
    else {
        cout<<b+10-a%10;
    }
    return 0;
}