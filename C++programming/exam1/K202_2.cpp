#include <iostream>
using namespace std;
int reserve(long long a)
{
    long long result = 0;
    /*if (a < 0)
    {
        a = -a;
        cout << '-';
    }*/
    while (a)
    {
        result = result * 10 + a % 10;
        a = a / 10;
    }
    if(result<-2147483648||result>2147483647){
        return 0;
    }
    else return result;
}
int main()
{
    long long n;
    cin >> n;
    if (n == 0)
    {
        cout << '0';
    }
    else
    {
        cout << reserve(n) << endl;
    }
    return 0;
}