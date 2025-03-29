#include <iostream>
using namespace std;
int main()
{
    int n,m,p,q;
    cin>>n>>m>>p>>q;
    int **M1=new int*[n];
    for(int i=0;i<n;i++)
    {
        M1[i]=new int [m];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>M1[i][j];
        }
    }

    int **M2=new int*[p];
    for(int i=0;i<p;i++)
    {
        M2[i]=new int [q];
    }
    for(int i=0;i<p;i++)
    {
        for(int j=0;j<q;j++)
        {

            for(int i1=0;i1<n;i1++)
            {
                for(int j1=0;j1<m;j1++)
                {
                    if((i1*m+j1)==(i*q+j))
                    {
                        M2[i][j]=M1[i1][j1];
                    }
                }
            }
        }
    }

    for(int i=0;i<p;i++)
    {
        for(int j=0;j<q;j++)
        {
            cout<<M2[i][j]<<' ';
        }
        cout<<endl;
    }
    
    for(int i=0;i<p;i++)
    {
        delete[] M2[i];
    }
    delete[] M2;
    for(int i=0;i<n;i++)
    {
        delete[] M1[i];
    }
    delete[] M1;
    return 0;
}