#include <iostream>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int L_max,B_max;
        cin>>L_max>>B_max;
        int L_num=0,B_num=0;
        int i=0;
        while(true)
        {
            i++;
            L_num+=i;
            if(L_num>L_max)
            {
                cout<<"Bob"<<endl;
                break;
            }
            i++;

            B_num+=i;
            if(B_num>B_max)
            {
                cout<<"Limak"<<endl;
                break;
            }
        }
    }

    return 0;
}