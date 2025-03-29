#include <iostream>
#include <string>
using namespace std;
int expandAroundCenter(string& s,int left,int right)
{
    while(left>=0&&right<=s.length()&&s[left]==s[right])
    {
        left--;
        right++;
    }
    return right-left-1;
}
int longestLength(string& s)
{
    int maxLength=0;
    int n=s.length();
    for(int i=0;i<n;i++)
    {
        int len1=expandAroundCenter(s,i,i);
        int len2=expandAroundCenter(s,i,i+1);
        maxLength=max(maxLength,max(len1,len2));
    }
    return maxLength;
}

int main()
{
    string s;
    cin>>s;
    int num=longestLength(s);
    cout<<num;
    return 0;
}