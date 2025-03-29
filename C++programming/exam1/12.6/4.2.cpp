#include <iostream>
using namespace std;
struct word
{
    int no;
    int inp;
    int nums;
};
int main()
{
    int n, m;
    cin >> n >> m;
    word *p = new word[m];
    for (int i = 0; i < m; i++)
    {
        p[i].no=i+1;
        p[i].inp = 0;
        p[i].nums = 0;
    }

    for (int i = 0; i < n; i++)
    {
        int w_num;
        cin >> w_num;
        bool ifinp=false;
        bool hasadd=false;
        int *arr = new int[w_num];
        for (int i = 0; i < w_num; i++)
        {
            cin >> arr[i];
            for(int j=0;j<m;j++)
            {
                if(arr[i]==p[j].no)
                {
                    p[j].nums++;
                    ifinp=true;
                    if(!hasadd)
                    {
                        if(ifinp)
                        {
                            p[j].inp++;
                            hasadd=true;
                        }
                    }
                }
            }
        }
        delete[] arr;
    }
    
    for(int i=0;i<m;i++)
    {
        cout<<p[i].inp<<' '<<p[i].nums<<endl;
    }
    delete[] p;
    return 0;
}