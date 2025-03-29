
typedef long long ll;
bool check(int a[],)
void solve(ll n,ll,k)
{
    int *a=new int[k+1];
    for(in ti=0;i<k;i++)
    {
        a[i]=0;
    }
    a[1]=n;
    while(check(a,k))
    {
        for(int i=1;i<k;i++)
        {
            if(a[i]>=2)
            {
                a[i+1]+=a[i]/2;
                a[i-1]+=a[i]/2;
                a[i]%=2;
                break;
            }
        }
    }
    cout<<a[k];
}



int main()
{
    int T;
    cin>>T;
    ll n
}