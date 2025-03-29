#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct CITY
{
    vector<long long> man;
    // man.reserve(100);
    int win;
}; // 结构体——每个城市及其代表win
int themax(const vector<long long> &man,int n)
{

    int imax = 0;
    long long max = man[0];
    for (int i = 0; i < n; i++)
    {
        if (man[i] > max)
        {
            max = man[i];
            imax = i;
        }
    }
    return imax;
} // 找出每个城市的win的号码
int main()
{
    long long n;
    int m;
    cin >> n >> m;
    vector<long long> sum(n, 0);
    CITY *city = new CITY[m];

    for (int i = 0; i < m; i++)
    {
        city[i].man.reserve(n);
    }
    for (int i = 0; i < m; i++)
    {
        for (long long j = 0; j < n; j++)
        {
            cin >> city[i].man[j];
        }
        city[i].win = themax(city[i].man,n);
    }
    /*for(int i=0;i<m;i++){
        cout<<city[i].win<<" ";
    }
    cout<<endl;*/
    /*for (int i = 0; i < m; i++)
    {
        for (long long j = 0; j < n; j++)
        {
            if (city[i].win == j + 1)
            {
                sum[j]++;
            }
        }
    }*/
   for(int i=0;i<m;i++)
   {
    sum[city[i].win]++;
   }
   /*for(int i:sum){
    cout<<i<<" ";
   }*/
   //cout<<endl;
    int max1 = themax(sum,n);
    cout << max1+1 << endl;
    delete[] city;
    return 0;
}