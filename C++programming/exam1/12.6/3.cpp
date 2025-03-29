#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int maxlen=0;
    int n=s.size();
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            int len=j-i+1;
            string subString =s.substr(i,j-i+1);
            string reversedString=subString;
            reverse(reversedString.begin(),reversedString.end());

            if(subString==reversedString && len >maxlen)
            {
                maxlen=len;
            }
        }
    }
    cout<<maxlen<<endl;
    return 0;
}
