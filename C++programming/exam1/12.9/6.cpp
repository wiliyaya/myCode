#include <iostream>
using namespace std;
int **renew(int **M1, int n, int m, int p, int q);
int **rev(int **M1, int n, int m) ;
int main()
{
    int n, m, t;
    cin >> n >> m >> t;
    int **M = new int *[n];
    for (int i = 0; i < n; i++)
    {
        M[i] = new int[m];
    }

    for (int i = 0; i < t; i++)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int p, q;
            cin >> p >> q;
            // int **M2 = new int *[p];
            // for (int i = 0; i < p; i++)
            // {
            //     M2[i] = new int[q];
            // }
            M = renew(M, n, m, p, q);
            // for (int i = 0; i < p; i++)
            // {
            //     delete[] M2[i];
            // }
            // delete[] M2;
        }
        else if (op == 2)
        {
            // int **M3 = new int *[m];
            // for (int i = 0; i < m; i++)
            // {
            //     M3[i] = new int[n];
            // }
             M = rev(M, n, m);
            //  for (int i = 0; i < n; i++)
            //  {
            //      delete[] M3[i];
            //  }
            //  delete[] M3;
        }
        else if (op == 3)
        {
            int I, J;
            cin >> I >> J;
            cout << M[I][J] << endl;
        }
    }

    for (int i = 0; i < n; i++)
    {
        delete[] M[i];
    }
    delete[] M;

    return 0;
}

int **renew(int **M1, int n, int m, int p, int q)
{
    int **M2 = new int *[p];
    for (int i = 0; i < p; i++)
    {
        M2[i] = new int[q];
    }
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < q; j++)
        {

            for (int i1 = 0; i1 < n; i1++)
            {
                for (int j1 = 0; j1 < m; j1++)
                {
                    if ((i1 * m + j1) == (i * q + j))
                    {
                        M2[i][j] = M1[i1][j1];
                    }
                }
            }
        }
    }
    return M2;
}
int **rev(int **M1, int n, int m)
{

    int **M3 = new int *[m];
    for (int i = 0; i < m; i++)
    {
        M3[i] = new int[n];
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            M3[i][j] = M1[j][i];
        }
    }
    return M3;
}