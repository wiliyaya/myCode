#include <iostream>
using namespace std;
class person
{
private:
    int no;       /* 人的编号 */
    person *next; /* 指向相邻的下一个人 */
public:
    person(int num)
    {
        no = num;
        next = NULL;
    }
    void setNext(person *p)
    {
        next = p;
    }
    int getNo()
    {
        return no;
    }
    person *getNext()
    {
        return next;
    }
};

class cycle
{
private:
    person *start; /* 开始数数的位置 */
    int out;       /* 数到几出列 */
    int inQueue;   /* 队伍中现有人数 */
public:
    cycle(int num, int from, int whoOut)
    {
        inQueue = num, out = whoOut;
        person *prv = NULL, *first = NULL;
        for (int i = 1; i <= num; i++)
        {
            person *p = new person(i);
            if (i == 1)
                first = p;
            if (i == from)
                start = p;
            if (i > 1)
                prv->setNext(p);

            prv = p;
        }
        prv->setNext(first);
    }
    int getInQueue()
    {
        return inQueue;
    }
    void cnt() /* 根据题目要求数数，确定出列的人，将该人从圈中剔除 */
    {
        person *pre=NULL;
        person *cur=start;

        for(int i=1;i<out;i++)
        {
            pre=cur;
            cur=cur->getNext();
        }
        if(cur==start)
        {
            start=start->getNext();
        }
        if(pre!=NULL)
        {
            pre->setNext(cur->getNext());
        }
        inQueue--;

        delete cur;

        if(inQueue==1)
        {
            return ;
        }
        else{
            start=pre->getNext();
        }







        // person *temp=cur;
        // cur->setNext(cur->getNext()->getNext());
        // cur=temp;
        // delete temp;


        /*if (inQueue == 0)
        {
            return;
        }
        person *pre = new person(0);
        // person *pre=NULL;
        pre->setNext(start);
        person *cur = start;
        int num = 1;
        while (inQueue > 1)
        {
            if (num == out)
            {
                person *temp = cur; //->getNext();
                pre->setNext(cur->getNext());

                if (cur == start)
                {
                    start = start->getNext();
                }
                // cur->setNext(cur->getNext()->getNext());
                // cur->setNext(cur->getNext()->getNext()->getNext());
                cur = cur->getNext();
                delete temp;
                // temp=NULL;
                inQueue--;
                num = 1;
                // break;
            }
            else
            {
                pre = cur;
                cur = cur->getNext();
                num++;
            }
        }
        delete pre;*/
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
    int n, k, m; /* n 圈内人数  k 开始数数 m 可数出列 */
    cin >> n >> k >> m;

    cycle *p = new cycle(n, k, m);

    while (p->getInQueue() > 1)
        p->cnt();

    person *winer = p->getStart();
    cout << winer->getNo() << endl;

    delete p;

    return 0;
}