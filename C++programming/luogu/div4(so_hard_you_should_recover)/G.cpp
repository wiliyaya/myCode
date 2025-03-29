#include <iostream>
#include <string>
using namespace std;
int main()
{
    string S;
    cin>>S;
    int type;
    cin>>type;
    int c_num=0,b=0;
    for(int i=0;i<S.size();i++)
    {
        if(S[i]=='L'||S[i]=='R')
        {
            c_num++;
        }
        else if(S[i]=='(')
        {b++;}
    }
    cout<<c_num-b;
    


}