#include <iostream>
using namespace std;
struct man
{
    int K;
    int I;
    int E;
};
bool isout(man &a, man &b)
{
    if (a.K < b.K && a.I < b.I && a.E < b.E)
    {
        return true;
    }
    return false;
}
int main()
{
    long long N;
    cin >> N;
    man *Man = new man[N];
    long long num = 0;
    for (long long i = 0; i < N; i++)
    {
        cin >> Man[i].K;
    }
    for (long long i = 0; i < N; i++)
    {
        cin >> Man[i].I;
    }
    for (long long i = 0; i < N; i++)
    {
        cin >> Man[i].E;
    }
    for (long long i = 0; i < N; i++)
    {
        for (long long j = 0; j < N; j++)
        {
            if (isout(Man[i], Man[j]))
            {
                num++;
                break;
            }
        }
    }
    cout<<num<<endl;
    delete[] Man;
    return 0;
}