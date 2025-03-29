#include <iostream>
using namespace std;
int main()
{
    int n = 0;
    cin >> n;
    if (n == 1 || n == 2)
    {
        cout << n;
    }
    else
    {
        long long n3 = 1, n2 = 2, n1 = 1;
        for (int i = 3; i <= n; i++)
        {
            n3 = n1 + n2;
            n1 = n2;
            n2 = n3;
        }
        cout << n2;
    }
    return 0;
}