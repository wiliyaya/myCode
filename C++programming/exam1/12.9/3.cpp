#include <iostream>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int *inpassage=new int[m];
    int *times=new int[m];
    for(int i=0;i<m;i++)
    {
        inpassage[i]=0;
        times[i]=0;
    }
    for(int i=0;i<n;i++)//第i篇文章
    {
        int m_word;
        cin>>m_word;
        int *p=new int [m_word];
        int *b=new int[m];
        for(int j=0;j<m;j++)
        {
            b[j]=0;
        }
        for(int j=0;j<m_word;j++)//储存每篇中的词
        {
            cin>>p[j];
        }
        for(int j=0;j<m_word;j++)
        {
            for(int k=0;k<m;k++)
            {
                if(k+1==p[j])
                {
                    times[k]++;
                    b[k]=1;
                }
            }
        }
        for(int k=0;k<m;k++)
        {
            if(b[k])
            {
                inpassage[k]++;
            }
        }
        delete[] p;
        delete[] b;
    }

    for(int i=0;i<m;i++)
    {
        cout<<inpassage[i]<<' '<<times[i]<<endl;
    }
    delete[] inpassage;
    delete[] times;
    return 0;
}