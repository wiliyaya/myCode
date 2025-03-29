#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>vec(n,vector<int>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>vec[i][j];
        }
    }
    int c_max,c_grade=0;
    for(int j=0;j<m;j++)
    {
        int grade;
        for(int i=0;i<n;i++)
        {
            grade+=vec[i][j];
        }

        if(grade>=c_grade)
        {
            c_grade=grade;
            c_max=j;
        }
    }

    int Max=0;
    for(int i=0;i<n;i++)
    {
        if(vec[i][c_max]>Max)
        {
            Max=vec[i][c_max];
        }
    }
    cout<<Max<<' ';
    int num=0;
    for(int i=0;i<n;i++)
    {
        if(vec[i][c_max]==Max)
        {
            num++;
        }
    }
    cout<<num;
    cout<<endl;


}