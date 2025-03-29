#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
struct Man
{
    string name;
    int money;
};
bool cmp(Man &a,Man &b)
{
    return a.money>b.money;
}
int main()
{
    int n;
    cin>>n;
    Man *man=new Man[n];
    for(int i=0;i<n;i++)
    {
        cin>>man[i].name>>man[i].money;
    }
    sort(man,man+n,cmp);
    cout<<man[0].name<<' '<<man[0].money<<endl;
    delete[] man;
    return 0;
}