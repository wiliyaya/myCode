#include <iostream>
using namespace std;
int main()
{
    int T;
    cin >> T;
    int n=0;
    //char *ch=new char[];
    for (int b = 0; b < T; b++)
    {
        //int n;
        cin >> n;
        char *ch = new char[n];
        for (int i = 0; i < n; i++)
        {
            cin >> ch[i];
        }
        int stot = 0, ttos = 0;
        for (int i = 1; i < n; i++)
        {
            if (ch[i] != ch[i - 1])
            {
                if (ch[i] == 'T')
                {
                    stot++;
                }
                else
                {
                    ttos++;
                }
            }
        }
        cout<<(stot>ttos ? "YES":"NO")<<endl;
        delete[] ch;
    }
    return 0;
}