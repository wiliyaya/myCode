#include <iostream>
#include <vector>
using namespace std;
long long Number(int n,vector<long long>& vec)
{
    if(n<=2)
    {
        return n;
    }
    vec[n-2]=Number(n-1,vec);
    vec[n-3]=Number(n-2,vec);
    long long result=vec[n-2]+vec[n-3];
    return result;
}
int main()
{
    int n;
    cin>>n;
    vector<long long> vec(n);
    long long result=Number(n,vec);
    cout<<result<<endl;
    return 0;

}