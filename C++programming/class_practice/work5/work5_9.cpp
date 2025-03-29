#include <iostream>
using namespace std;
int main()
{
    int n = 0, k = 0;
    cin >> n >> k;
    int r[n];
    int num[n];
    for (int i = 0; i < n; i++)
    {
        cin >> r[i];
        num[i] = 0;
    }
    int problem[k][2];
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> problem[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (r[i] > r[j])
            {
                for (int I = 0; I < n; I++)
                {
                    bool A = problem[I][0] == i && problem[I][1] == j;
                    bool B = problem[I][0] == j && problem[I][1] == i;
                    if (A || B)
                    {
                        continue;
                    }
                    else
                        num[i]++;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << num[i] << ' ';
    }
    return 0;
}