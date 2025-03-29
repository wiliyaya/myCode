#include <iostream>
using namespace std;
int main()
{
    int n = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int a=i;
        if (i % 7 == 0)
        {
            cout << i << endl;
            continue;
        }
        else
        //int a=i;
        while (a)
        {
            if (a % 10 == 7)
            {
                cout << a << endl;
                break;
            }
            else
                a = a / 10;
        }
    }
}