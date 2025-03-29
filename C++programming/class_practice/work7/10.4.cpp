#include <iostream>
using namespace std;
bool candestroy(int sum, char **chr, int n, int m)
{
    int num = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < n; k++) // 找该列上的‘*’
            {
                if (k != i && chr[k][j] == '*')
                {
                    num++;
                }
            }
            for (int k = 0; k < m; k++)
            {
                if (k != j && chr[i][k] == '*')
                {
                    num++;
                }
            }
            if (chr[i][j] == '*')
            {
                num++;
            }
            if (num == sum)
            {
                return true;
            }
        }
    }
    return false;
}
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

        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> chr[i][j];
                if (chr[i][j] == '*')
                {
                    sum++;
                }
            }
        }
        cout << ((candestroy(sum, chr, n, m)) ? "YES" : "NO") << endl;

        for (int i = 0; i < n; i++)
        {
            delete[] chr[i];
        }
        delete[] chr;
    }
    return 0;
}