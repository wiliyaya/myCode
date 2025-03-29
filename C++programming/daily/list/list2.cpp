#include <bits/stdc++.h>
using namespace std;

//单链表
struct ListNode
{
    int val;
    ListNode *next;
    ListName(int x):val(x),next(NULL){}
};





class Solution1
{
pubilc:
    ListNode* removeElements(ListNode* head,int val)
    {
        ListNode* dummyHead=new ListNode(0);
        dummyHead->next=head;
        ListNode* cur=dummyHead;
        while(cur->next!=NULL)
        {
            if(cur->next->val==val)
            {
                ListNode* tmp=cur->next;
                cur->next=cur->next->next;
                delete tmp;
            }
            else
            {
                cur=cur->next;
            }
        }
        head=dummyHead->next;
        return head;
    }
};

//删除节点操作2
class Solution2
{
pubilc:
    ListNode* removeElement(ListNode* head,int val)
    {
        //删除头节点
        while(head!=NULL && head->val==val)
        {
            ListNode* tmp=head;
            head=head->next;
            delete tmp;
        }
    }
    //删除非头结点
    ListNode* cur=head;
    while(cur!=NULL&&cur->next!=NULL)
    {
        if(cur->next->val==val)
        {
            ListNode* tmp=cur->next;
            cur->next=cur->next->next;
            delete tmp;
        }
        else{
            cur=cur->next;
        }
    }

};

//设计链表的五个接口
class MyLinkedList
{
public:
    //定义链表的结构体
    struct LinkedNode
    {
        int val;
        LinkedNode* next;
        LinkedNode(int val):val(val),next(nullptr){}
    };

    //初始化链表
    MyLinkedList()
    {
        _dummyHead=new LinkedNode(0);
        //定义虚拟头节点
        _size=0;
    }

    //获取到第index个节点数值，如果index是非法的，直接返回-1，注意index是从0开始的，第0个头节点就是头节点
    int get(int index)
    {
        if(index>(_size-1)||index<0)
        {
            return -1;
        }
        LinkedNode* cur=_dummyHead->next;
        while(index--)
        {
            cur=cur->next;
        }
        return cur->val;
    }

    //在链表最前面插入一个节点，插入完成后，新插入的节点为链表新的头节点
    void addAtHead(int val)
    {
        LinkedNode* NewNode=new LinkedNode(val);
        newNode->next=_dummyHead->next;
        _dummyHead->next=newNode;
        _size++;
    }

    //在链表最后加一个节点
    void addAtTail(int vail)
    {
        LinkedNode* newNode=new LinkedNode(val);
        LinkedNode* cur=_dummyHead;
        while(cur->next!=nullptr)
        {
            cur=cur->next;
        }
        cur->next=newNode;
        _size++;
    }

    //在第index个节点之前插入一个新节点，例如index为0，那么新插入的为新头节点
    //如果index等于链表的长度，则说明新插入的节点为链表的尾节点
    //如果index大于链表的长度，则返回空
    //如果index小于0，在头部插入节点
    void addAtIndex(int index,int val)
    {
        if(index>_size)return ;
        if(index<0) index=0;
        LinkedNode* newNode=new LinkedNode(val);
        LinkedNode* cur=_dummyHead;
        while(index--)
        {
            cur=cur->next;
        }
        newNode->next=cur->next;
        cur->next=newNode;
        _size++;
    }

    //删除第index个节点，注意index从0开始
    void deleteAtIndex(int index)
    {
        if(index>_size||index<0)
        {
            return ;
        }
        LinkedNode* cur=_dummyHead;
        while(index--)
        {
            cur=cur->next;
        }
        LinkedNode* tmp=cur->next;
        cur->next=cur->next->next;
        delete tmp;
        tmp=nullptr;
        _size--;
    }

    //打印链表
    void printLinkedList()
    {
        LinkedNode* cur=_dummyHead;
        while(cur->next!=nullptr)
        {
            cout<<cur->next->val<<" ";
            cur=cur->next;
        }
        cout<<endl;
    }

private:
    int _size;
    LinkedNode* _dummyHead; 
};

//反转链表
//双指针法
class Solution
{
    ListNode* reverseList(ListNode* head)
    {
        ListNode* temp;//保留cur的下一个节点
        ListNode* cur=head;
        ListNode* pre=NULL;
        while(cur)
        {
            temp=cur->next;
            cur->next=pre;
            pre=cur;
            cur=temp;
        }
        return pre;
    }
};

//两两交换链表中的节点
class Solution
{
public:
    ListNode* swapParis(ListNode* head)
    {
        ListNode* dummyHead = new ListNode(0);//设置虚拟头节点
        dummyHead->next=head;
        ListNode* cur=dummyHead;
        while(cur->next!=nullptr&&cur->next->next!=nullptr)
        {
            ListNode* tmp=cur->next;
            ListNode* tmp1=cur->next->next->next;//记录临时节点

            cur->next=cur->next->next;
            cur->next->next=tmp;
            cur->next->next->next=tmp1;

            cur=cur->next->next;//cur移动两位，准备下一次交换
        }
        ListNode* result=dummyHead->next;
        delete dummyHead;
        return result;
    }
};

//删除链表的倒数第N个节点
//双指针的经典运用

class Solution
{
public:
    ListNode* removeNthFromEnd(ListNode* head,int  n)
    {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next=head;
        ListNode* slow=dummyHead;
        ListNode* fast=dummyHead;
        while(n--&&fast!=NULL)
        {
            fast=fast->next;
        }
        fast=fast->next;
        while(fast!=NULL)
        {
            fast=fast->next;
            slow=slow->next;
        }
        slow->next=slow->next->next;

        return dummyHead->next;
    }
};

//链表相交
//求两个链表交点节点
class solution
{
public:
    ListNode* getIntersectionNode(ListNode *headA,ListNode *headB)
    {
        ListNode* curA=headA;
        ListNode* curB=headB;
        int lenA=0,lenB=0;
        while(curA!=NULL)
        {
            lenA++;
            curA=curA->next;
        }
        while(curB!=NULL)
        {
            lenB++;
            curB=curB->next;
        }

        curA=headA;
        curB=headB;

        if(lenB>lenA)
        {
            swap(lenA,lenB);
            sWap(curA,curB);
        }

        //求长度差
        int gap=lenA-lenB;

        while(gap--)
        {
            curA=curA->next;
        }

        //遍历curA和curB,遇到相同值则直接返回
        while(curA!=NULL)
        {
            if(curA==curB)
            {
                return curA;
            }
            curA=curA->next;
            curB=curB->next;
        }
        return NULL;
    }
};




























