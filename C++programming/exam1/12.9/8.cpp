#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n;
    cin>>n;
    //string str[n-1];
    string *str=new string[n-1];
    for(int i=0;i<n-1;i++)
    {
        cin>>str[i];
    }
    string t;
    cin>>t;
    int num=0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(i!=j)
            {
                if(str[i]+str[j]==t)
                {
                    num++;
                }
            }
        }
    }
    cout<<num<<endl;
    delete[] str;
    return 0;
}