#include <iostream>
using namespace std;
int main()
{
    int n = 0, m = 0;
    cin >> n >> m;
    int min = 0;
    int num = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> min;
        for (int j = 0; j < m - 1; j++)
        {
            cin >> num;
            min = (num < min ? num : min);
        }
        cout << min << endl;
    }
    return 0;
}