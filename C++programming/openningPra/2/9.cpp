#include <iostream>
#include <vector>
using namespace std;
struct doctor
{
    int s;
    int d;
};

int main()
{
    int n;
    cin>>n;
    vector<doctor>doc(n);
    for(int i=0;i<n;i++)
    {
        cin>>doc[i].s>>doc[i].d;
    }
    int date=doc[0].s;
    for(int i=1;i<n;i++)
    {
        for(int j=doc[i].s;;j+=doc[i].d)
        {
            if(j>date)
            {
                date=j;
                break;
            }
        }
    }
    cout<<date;
}