#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int m_g=0,m_b=0;
    for(int i=0;i<n;i++)
    {
        int len;
        cin>>len;
        if(len<=180&&len>=178)
        {
            m_b++;
        }
    }
        for(int i=0;i<n;i++)
    {
        int len;
        cin>>len;
        if(len<=170&&len>=168)
        {
            m_g++;
        }
    }
    cout<<m_b<<' '<<m_g<<endl;
    return 0;
}
