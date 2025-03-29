#include <iostream>
using namespace std;
int main()
{
    int n = 0;
    cin >> n;
    int sum = 0;
    int i = 1;
    int coin = 0;
    for (; sum < n; i++)
    {
        sum += i;
    }
    for (int j = 1; j < i; j++)
    {
        coin += j * j;
    }
    if (n != sum)
    {
        coin += (n - sum + i) * i;
    }
    cout << coin << endl;
}