#include <iostream>
#include <algorithm>
using namespace std;
struct Film
{
    long long no;
    int speak;
    int word;
    long long happy;
    long long satisfy;
};
bool cmp(const Film &a, const Film &b)
{
    if (a.happy == b.happy)
    {
        if (a.satisfy == b.satisfy)
        {
            return a.no < b.no;
        }
        else
            return a.satisfy > b.satisfy;
    }
    else
        return a.happy > b.happy;
}
int main()
{
    long long n;
    cin >> n;
    long long *scientist = new long long[n];
    for (long long i = 0; i < n; i++)
    {
        cin >> scientist[i];
    }
    long long m;
    cin >> m;
    Film *film = new Film[m];
    for (long long i = 0; i < m; i++)
    {
        film[i].no = i + 1;
        film[i].happy = 0;
        film[i].satisfy = 0;
        cin >> film[i].speak;
    }
    for (long long i = 0; i < m; i++)
    {
        cin >> film[i].word;
    }
    for (long long i = 0; i < n; i++)
    {
        for (long long j = 0; j < m; j++)
        {
            if (scientist[i] == film[j].speak)
            {
                film[j].happy += 1;
            }
            else if (scientist[i] == film[j].word)
            {
                film[j].satisfy += 1;
            }
        }
    }
    sort(film, film + m, cmp);
    if (film[0].happy == 0)
    {
        cout << "unsatisfied" << endl;
    }
    else
    {
        cout << film[0].no << ' ';
        for (long long i = 1; i < m; i++)
        {
            if (film[i].happy < film[0].happy || film[i].satisfy < film[0].satisfy)
            {
                break;
            }
            else
                cout << film[i].no << ' ';
        }
    }
    delete[] scientist;
    delete[] film;
    return 0;
}