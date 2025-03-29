#include <iostream>
#include<vector>
using namespace std;

struct Student
{
    int l;
    int r;
    //int a;
};

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        vector<Student> stu(n);
        for(int i=0,sec=1;i<n;i++)
        {
            cin>>stu[i].l>>stu[i].r;
            //stu[k].a=k+1;
            if(sec<=stu[i].r)
            {
                if(sec<stu[i].l)
                {
                    sec=stu[i].l;
                }
                cout<<sec<<' ';
                sec++;
            }
            else cout<<"0 ";
        }
        cout<<endl;
    }
    return 0;
}