#include <iostream>
#include <vector>
using namespace std;
struct WB
{
    long long w;
    long long b;
};
int main()
{
    long long T;
    cin>>T;
    while(T--)
    {
        long long litter=0,no_litter=0;
        long long N,minX,maxX;
        cin>>N>>minX>>maxX;

        vector<WB>vec(N);
        for(long long i=0;i<N;i++)
        {
            cin>>vec[i].w>>vec[i].b;
        }

        for(long long i=minX;i<=maxX;i++)
        {
            long long y=0,X=i;

            for(long long j=0;j<N;j++)
            {
                y=vec[j].w*X+vec[j].b;
                X=y;
            }
            if(y%2==0)
            {
                no_litter++;
            }
            else litter++;
        }
        cout<<no_litter<<' '<<litter<<endl;

    }
    return 0;
}