#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int T;
    cin >> T;
    for (int I = 0; I < T; I++)
    {
        int n, m;
        cin >> n >> m;
        char **chr = new char *[n];
        for (int i = 0; i < n; i++)
        {
            chr[i] = new char[m];
        }

        int **arr = new int *[n];
        for (int i = 0; i < n; i++)
        {
            arr[i] = new int[m];
        }

        bool any = false;
        int i1=0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> chr[i][j];
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (chr[i][j] == '.')
                {
                    arr[i][j] = 0;
                }
                else if (!any)
                {
                    arr[i][j] = 1;
                    any=true;
                    i1=i;
                    for (int k = j + 1; k < m; k++)
                    {
                        arr[i][k] = 0;
                    }
                    break;
                }
                else
                    arr[i][j] = 1;
            }
        }
        long long *sum = new long long[n];
        for (int i = 0; i < n; i++)
        {
            sum[i] = 0;
            for (int j = 0; j < m; j++)
            {
                sum[i] += (arr[i][j] << (m - 1 - j));
            }
        }

        bool a = true;
        for (int i = i1 + 1; i < n; i++)
        {
            if (sum[i] != sum[i1] && sum[i] != 0)
            {
                a = false;
            }
        }
        cout << (a ? "YES" : "NO") << endl;

        for (int i = 0; i < n; i++)
        {
            delete[] chr[i];
            delete[] arr[i];
        }
        delete[] chr;
        delete[] arr;
        delete[] sum;
    }
}