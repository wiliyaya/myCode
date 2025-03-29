# include <iostream>
using namespace std;
typedef long long int ll;
ll getMod(ll a, ll b, ll p);
int main()
{
    ll a, b, p;
    cin>>a>>b>>p;
    ll ans=getMod(a,b,p);
    ans=ans%p;
    cout<<ans<<endl;

    return 0;
}

ll getMod(ll a, ll b, ll p)
{
    if(b==1)
    {
        return a%p;
    }

    else if(b%2!=0)
    {
        return getMod(a%p,b-1,p)*a%p;
    }
    else return getMod(a*a%p,b/2,p);
}
