#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    long long n,m;
    cin>>n>>m;
    vector<long long> vec;
    for(long long i=0;i<n;i++)
    {
        long long a,b;
        cin>>a>>b;
        vec.push_back(a);
        vec.push_back(b);
    }

    sort(vec.begin(),vec.end());

    cout<<((vec[0]<=0&&m<=vec[vec.size()-1])? "Yes":"No")<<endl;
    return 0;

}