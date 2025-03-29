#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
struct Foul
{
    int min;
    char team;
    int m;
    char color;
    string teamname;
};
bool cmp(const Foul &a, const Foul &b)
{
    if (a.min == b.min)
    {
        if (a.team == b.team)
        {
            return a.m > b.m;
        }
        else
            return a.team > b.team;
    }
    else
        return a.min < b.min;
}
bool ifhasr(const Foul *a,int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i].color == 'r')
        {
            return true;
        }
    }
    return false;
}
int main()
{
    string H;
    string A;
    cin >> H;
    cin >> A;
    int n;
    cin >> n;
    Foul *foul = new Foul[n];
    for (int i = 0; i < n; i++)
    {
        cin >> foul[i].min >> foul[i].team >> foul[i].m >> foul[i].color;
        if (foul[i].team == 'h')
        {
            foul[i].teamname = H;
        }
        else
            foul[i].teamname = A;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if ((foul[i].team == foul[j].team && foul[i].m == foul[j].m) && (foul[i].color == 'y' && foul[j].color == 'y'))
            {
                foul[i].color = 'r';
                break;
            }
        }
    }
    sort(foul, foul + n, cmp);
    if (ifhasr(foul,n))
    {
        for (int i = 0; i < n; i++)
        {
            if (foul[i].color == 'r')
            {
                cout << foul[i].teamname << ' ' << foul[i].m << ' ' << foul[i].min << endl;
            }
        }
    }
    else cout<<"No Red Card"<<endl;
    delete[] foul;
    return 0;
}