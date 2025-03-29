#include <iostream>
using namespace std;
int main()
{
    int T;cin>>T;
    while(T--)
    {
        int L,v,l,r;
        cin>>L>>v>>l>>r;
        int num=0;
        for(int V=v;V<=L;V+=v)
        {
            if(V<l||V>r)
            {
                num++;
            }
        }

        cout<<num<<endl;
    }

    return 0;
}