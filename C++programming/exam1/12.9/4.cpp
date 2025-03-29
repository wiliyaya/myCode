#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int longestlen(const string& s)
{
    int n=s.size();
    if(n<2)
    {
        return n;
    }
    int maxlen=1;
    auto findmax=[&](int left,int right)
    {
        while(left>=0&&right<n&&s[left]==s[right])
        {
            left--;
            right++;
        }
        return right-left-1;
    };
    for(int i=0;i<n;i++)
    {
        int dan=findmax(i,i);
        int suan=findmax(i,i+1);
        maxlen=max(maxlen,max(dan,suan));
    }
    return maxlen;
}
int main()
{
    string s;
    cin>>s;
    int n=longestlen(s);
    cout<<n<<endl;
    return 0;

}