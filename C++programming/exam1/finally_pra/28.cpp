#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

struct Nstr
{
    char n;
    string s;
};

bool cmp(Nstr& a,Nstr& b)
{
    return a.n<b.n;
}
int main()
{
    vector<Nstr>vec;
    string a;
    while(cin>>a)
    {
        Nstr A;
        A.n=a[a.length()-1];
        A.s=a.substr(0,a.length()-1);
        vec.push_back(A);
    }
    sort(vec.begin(),vec.end(),cmp);
    for(vector<Nstr>::iterator it=vec.begin();it!=vec.end();it++)
    {
        cout<<it->s;//<<((it+1==vec.end())? '':' ');
        if(it+1!=vec.end())
        {
            cout<<' ';
        }
    }
    return 0;


}