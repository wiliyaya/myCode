#include <iostream>
using namespace std;
int main()
{
    int x1,C,k;
    cin>>x1>>C>>k;
    long long ans=x1;
    for(int i=1;i<k;i++)
    {
        ans=(ans*ans+C)%10000;
    }
    cout<<ans;
    
}
