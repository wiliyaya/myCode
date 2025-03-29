#include <iostream>
using namespace std;
class person
{
private:
    int no;      /* 人的编号 */
    person *next;   /* 指向相邻的下一个人 */
public:
    person(int num)
    {
        no=num;
        next=NULL;
    }
    void setNext(person *p)//定义“下一个人”的地址
    {
        next=p;
    }
    int getNo()//用于读取私有属性no
    {
        return no;
    }
    person *getNext()//读取下一个的地址
    {
        return next;
    }
};

class cycle
{
private:
    person *start;    /* 开始数数的位置 */
    int out;          /* 数到几出列 */
    int inQueue;      /* 队伍中现有人数 */
public:
    cycle(int num, int from, int whoOut)
    {
        inQueue=num, out=whoOut;
        person *prv=NULL, *first=NULL;
        for(int i=1; i<=num; i++)
        {
            person *p=new person(i);//创建一个person类型的动态数组
            if (i==1)
                first=p;
            if (i==from)
                start=p;
            if (i>1)
                prv->setNext(p);

            prv=p;
        }
        prv->setNext(first);//循环结束后回到起始点，形成闭环
    }
    int getInQueue()
    {
        return inQueue;
    }
    void cnt()   /* 根据题目要求数数，确定出列的人，将该人从圈中剔除 */
    {
        person *prev=NULL;
        person *current=start;
        int k=1;
        do
        {
            if(inQueue==0){return ;}
            if(k==out)
            {
                k=1;
                if(prev)
                {
                    inQueue--;
                    prev->setNext(current->getNext());
                    current=current->getNext();
                }
                else current=current->getNext();
            }
            else
            {
                k++;
                prev=current;
                current=current->getNext();
            }
        } while (inQueue>0);
        
    }

    person *getStart()
    {
        return start;
    }

    ~cycle()
    {
        delete start;
    }
};

int main()
{
    int n,k, m ;   /* n 圈内人数  k 开始数数 m 可数出列 */
    cin>>n>>k>>m;

    cycle *p=new cycle(n,k,m);

    while(p->getInQueue()>1)
        p->cnt();

    person *winer=p->getStart();
    cout<<winer->getNo()<<endl;

    delete p;

    return 0;
}