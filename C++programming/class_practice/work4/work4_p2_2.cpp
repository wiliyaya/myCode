#include <iostream>
using namespace std;
int gcd(int,int);
int lcm(int,int);
int main()
{
    int x, y;
    cin >> x >> y;
    cout << gcd(x, y) << " " << lcm(x, y) << endl;
    return 0;
}

int gcd(int u, int v)
{
    int i = 1,a=0;
    for (; i <= u && i <= v; i++)
    {
        if (u % i == 0 && v % i == 0)
        {
            a=i;
        }
    }
    return a;
}
int lcm(int u,int v){
    return v*u/gcd(u,v);
}
