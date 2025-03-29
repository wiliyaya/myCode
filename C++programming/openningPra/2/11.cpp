#include <iostream>
using namespace std;
int main()
{
    int s;
    cin >> s;
    
    for (int i = s+1;; i++)
    {
        int num = 0, m_num = 0;
        for (int j = 1; j < i; j++)
        {
            if (i % j == 0)
            {
                num+=j;
            }
        }

        for (int j = 1; j <num; j++)
        {
            if (num % j == 0)
            {
                m_num += j;
            }
        }

        if (i == m_num)
        {
            cout << i << " " << num << endl;
            break;
        }
    }
    return 0;
}