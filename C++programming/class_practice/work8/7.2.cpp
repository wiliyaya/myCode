#include <bits/stdc++.h>
using namespace std;

struct key
{
    int id, time, buff;
};

int main()
{
    long long n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        a[i] = i + 1;
    }
    vector<key> p(2 * k);

    for (long long i = 0; i < k; i++)
    {
        int id, starttime, endtime;
        cin >> id >> starttime >> endtime;
        p[2 * i].id = id, p[2 * i].time = starttime, p[2 * i].buff = 1;
        p[2 * i + 1].id = id, p[2 * i + 1].time = starttime + endtime, p[2 * i + 1].buff = 2;
    }
    /*for(int i=0;i<2*k;i++){
         cout << p[i].id << " " << p[i].time << " " << p[i].buff << endl;
    }*/
    //cout<<"/////////////////////"<<endl;
    sort(p.begin(), p.end(), [](const key &a, const key &b)
         {
        if (a.time == b.time) {
            if (a.buff == b.buff) return a.id < b.id; 
            return a.buff > b.buff; 
        } else {
            return a.time < b.time;  
        } });

    /*for(int i=0;i<2*k;i++){
         cout << p[i].id << " " << p[i].time << " " << p[i].buff << endl;
    }*/

    for (long long i = 0; i < 2 * k; i++)
    {
        if (p[i].buff == 1)
        {
            int index = -1;
            for (int j = 0; j < n; j++)
            {
                if (a[j] == p[i].id)
                {
                    index = j;
                    break;
                }
            }
            if (index != -1)
            {
                a[index] = 0;
            }
        }

        if (p[i].buff == 2)
        {
            int index = -1;
            for (int j = 0; j < n; j++)
            {
                if (a[j] == 0)
                {
                    index = j;
                    break;
                }
            }
            if (index != -1)
            {
                a[index] = p[i].id;
            }
        }
    }
    for (const auto &i : a)
    {
        cout << i << " ";
    }
    return 0;
}