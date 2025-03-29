#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        if (i % 7 == 0)
        {
            cout << i << endl;
            continue;
        }
        int temp = i;
        while (temp)
        {
            if (temp % 10 == 7)
            {
                cout << i << endl;
                break;
            }
            else
            {
                temp = temp / 10;
            }
        }
    }
    return 0;
}