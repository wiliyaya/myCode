#include <iostream>
//#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string s;
    string t;
    cin>>s>>t;
    size_t pos;
    bool is=true;
    for(int i=0;i<s.size();i++)
    {
        pos=s.find(s[i],i+1);
        if(pos!=string::npos)
        {
            if(t[i]!=t[pos])
            {
                is=false;
                break;
            }
        }
    }
    cout<<(is ? "true":"false")<<endl;
    return 0;

}
