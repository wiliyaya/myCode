#include <iostream>
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
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> chr[i][j];
            }
        }

        bool allDestroy = true;
        bool candestroy = false;
        for (int i = 0; i < n; i++)
        {
            //bool candestroy = false;
            for (int j = 0; j < m; j++)
            {
                // 检查其他行,列上有没有“*”
                for (int r = 0; r < n; r++)
                {
                    for (int c = 0; c < m; c++)
                    {
                        if (r != i && c != j && chr[r][j] == '*')
                            allDestroy = false;
                        if (!allDestroy)
                        {
                            break;
                        }
                    }
                    if (!allDestroy)
                    {
                        break;
                    }//这个位置不行得找下个
                    else if (allDestroy)//这个位置可以
                    {
                        candestroy = true;
                    }
                    if (candestroy)
                    {
                        break;
                    }
                }
                if (candestroy)
                {
                    break;
                }
            }
            if(candestroy)
            {
                break;
            }
        }
        cout<<(candestroy ? "YES":"NO")<<endl;

        for (int i = 0; i < n; i++)
        {
            delete[] chr[i];
        }
        delete[] chr;
    }
    return 0;
}