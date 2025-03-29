#include <iostream>
using namespace std;
struct jump
{
    long long a;
    long long b;
    long long k;
};
long long situation(long long a, long long b, long long k)
{
    long long result = 0;
    if (k % 2 != 0)
    {
        result = (a - b) * (k / 2) + a;
    }
    else
        result = (a - b) * (k / 2);
    return result;
}
int main()
{
    long long n;
    cin >> n;
    struct jump s[n];
    for (long long i = 0; i < n; i++)
    {
        cin >> s[i].a >> s[i].b >> s[i].k;
    }
    for (long long i = 0; i < n; i++)
    {
        cout << situation(s[i].a, s[i].b, s[i].k) << endl;
    }
    return 0;
}