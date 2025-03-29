#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int *boy=new int[n];
    int *girl=new int[n];
    int m_boy=0,m_girl=0;
    for(int i=0;i<n;i++)
    {
        cin>>boy[i];
        if(boy[i]>=178&&boy[i]<=180)
        {
            m_boy++;
        }
    }
    
    for(int i=0;i<n;i++)
    {
        cin>>girl[i];
        if(girl[i]>=168&&girl[i]<=170)
        {
            m_girl++;
        }
    }
    cout<<m_boy<<' '<<m_girl<<endl;
    delete[] boy;
    delete[] girl;
    return 0;
}