#include <iostream>
using namespace std;
void getMaxSum(int a[], int n, int &Left, int &Right);

int main()
{
    int n;
    cin >> n;

    int *p = new int[n];

    for (int i = 0; i < n; i++)
        cin >> p[i];

    int Left, Right;
    getMaxSum(p, n, Left, Right);

    cout << Left << " " << Right << endl;
    delete[] p;

    return 0;
}

void getMaxSum(int a[], int n, int &Left, int &Right)
{
    Left = 0;
    Right = 0;

    int max = a[0];
    int sum = 0;
    int max_Left = 0, max_Right = 0;

    // bool jixu=true;

    for (int sb = 0; sb < n; sb++)
    {
        Left=sb;
        Right=sb;
        
    bool LeftAdd = true, RightAdd = true;
        while (Left >= 0 && Right < n)
        {
            if (Left >= 0)
            {
                LeftAdd = false;
            }
            if (Right <= n)
            {
                RightAdd = false;
            }

            sum = 0;

            if (LeftAdd)
            {
                for (int i = Left - 1; i < Right; i++)
                {
                    sum += a[i];
                }

                if (sum > max)
                {
                    max = sum;
                    max_Left = Left--;
                    max_Right = Right;
                }
                Left--;
                sum = 0;
            }

            sum = 0;
            if (RightAdd)
            {
                for (int i = Left; i <= Right ; i++)
                {
                    sum += a[i];
                }

                if (sum > max)
                {
                    max = sum;
                    max_Left = Left;
                    max_Right = Right + 1;
                }
                Right++;
                sum = 0;
            }
            sum = 0;
        }
    }

    Left=max_Left;
    Right=max_Right;
}