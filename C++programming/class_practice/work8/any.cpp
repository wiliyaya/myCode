#include <iostream>
using namespace std;
struct key
{
    int no;
    int stime;//动作执行的时间
    int op; // 1-j借 2-还
};

bool cmp(const key &a, const key &b)
{
    if (a.stime == b.stime)
    {
        if (a.op == b.op)//时间相等看动作
        {
            return a.no < b.no; // action 相同编号优先
            //每个key的编号是唯一的
        }
        else return a.op>b.op;
    }
    else return a.stime<b.stime;

}
int main()
{
    int n, k;
    cin >> n >> k;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = i + 1; // 钥匙编号
    }

    key *p = new key[2 * k];
    for (int i = 0; i < k; i++)
    { // k次动作，每次都有借和还
        int no, start, end;
        cin >> no >> start >> end;
        p[2 * i].no = no, p[2 * i].stime = start , p[2 * i].op = 1;
        p[2 * i + 1].no = no, p[2 * i + 1].stime =start+end,p[i*2+1].op=2;
    }
    sort(p,p+2*k,cmp);
    
}