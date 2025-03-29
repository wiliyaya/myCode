#include <iostream>
#include <vector>
using namespace std;

bool isBEsame(vector<long long>& vec)
{
    for(long long i=1;i<vec.size();i++)
    {
        if(vec[0]==vec[i])
        {
            return true;
        }
    }
    for(long long i=0;i<vec.size()-1;i++)
    {
        if(vec[i]==vec[vec.size()-1])
        {return true;}
    }
    return false;
}


int main()
{
    int T;
    cin>>T;
    while(T--)
    {
    long long n;
    cin>>n;
    vector<long long>vec;
    for(long long i=0;i<n;i++)
    {
        int x;
        cin>>x;
        vec.push_back(x);
    }
    if(vec[0]==vec[vec.size()-1])
    {
        cout<<'1'<<endl;
        continue;
    }
    if(isBEsame(vec))
    {
        cout<<'2'<<endl;
        continue;
    }
    else cout<<'3'<<endl;
    //忘了还有各不相同的情况了


    }
}