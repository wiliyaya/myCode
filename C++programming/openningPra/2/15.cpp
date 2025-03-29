#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    vector<int>A;
    vector<int>B;
    while(a)
    {
        A.push_back(a%2);
        a=a/2;
    }
    while(b)
    {
        B.push_back(b%2);
        b=b/2;
    }
    if(A.size()>B.size())
    {
        B.resize(A.size());
    }
    else
    {
        A.resize(B.size());
    }
    int i=0;
    int temp1=0,temp2=0;
    bool aaa=true;
    for(vector<int>::iterator ait=A.begin(),bit=B.begin();ait!=A.end();ait++,bit++)
    {
        if(*ait!=*bit)
        {
            temp1=i;
            if(aaa)
            {
                temp2=i;
                aaa=false;
            }
        }
        i++;
    }
    cout<<(temp1-temp2+1)<<endl;
    return 0;

}