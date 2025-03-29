#include <bits/stdc++.h>
using namespace std;



// 单链表
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {} // 节点的构造函数
    // 注意构造函数后面没有';'
};

// 移除节点操作1
class Solution1
{
public:
    ListNode* removeElements(ListNode *head, int val)
    {
        ListNode* dummyHead=new ListNode(0);//创建一个虚拟头节点
        dummyHead->next = head;//将虚拟头节点指向head，方便后面的删除操作
        ListNode* cur=dummyHead;
        while(cur->next!=NULL)
        {
            if(cur->next ->val==val)//直接判断current的下一个
            {
                ListNode* tmp=cur->next;
                cur->next=cur->next->next;
                delete tmp;    //既然最后都是要改变cur->的指向，为什么还要创建tmp
            }
            else 
            {
                cur=cur->next;//链表往后移一位
            }
        }
        head=dummyHead->next;
        return  head;
    }
};

//删除节点操作2
class Solution2
{
public: 
    ListNode* removeElement(ListNode* head,int val)
    {
        //删除头节点
        while(head != NULL && head ->val==val)//注意这里不是if,因为可能有多个val都在头部要被删除
        {
            ListNode* tmp=head;
            head=head->next;
            delete tmp;
        }

        //删除非头节点
        ListNode* cur = head ;
        while(cur!=NULL&&cur->next!=NULL)
        {
            if(cur->next->val==val)
            {
                ListNode* tmp=cur->next;
                cur->next=cur->next->next;
                delete tmp;
            }
            else {
                cur=cur->next;//链表往后移一位
            }
        }
    }
};

//移除节点操作3//看不懂//不管
class Solution
{
public:
    ListNode* removeElements(ListNode* head,int val)
    {
        //基础情况：空链表
        if(head==nullptr)
        {
            return nullptr;
        }

        //递归处理
        if(head->val==val)
        {
            ListNode* newHead=removeElements(head->next,val);
            delete head;
            return newHead;
        }
        else{
            head->next=removeElements(head->head,val);
            return head;
        }
    }
};



//设计链表的五个接口
class MyLinkedList
{
pubilc:
    //定义链表的结构体
    struct LinkedNode
    {
        int val ;
        LinkedNode* next;
        LinkedNode(int val):val(val),next(nullptr){}
    };

    //初始化链表
    MyLinkedList()
    {
         _dummyHead = new LinkedNode(0);
        //定义虚拟头节点
        _size=0;
    }

    //获取到第index个节点数值，如果index是非法的，直接返回-1，注意index 是从0开始的，第0个节点就是头节点
    int get(int index){
        if(index>(_size-1)||index<0)
        {
            return -1;
        }
        LinkedNode* cur =_dummyHead->next;
        while(index--)//如果--index 就会陷入死循环
        {
            cur=cur->next;
        }
        return cur->val;
    }

    //在链表最前面插入一个节点，插入完成后，新插入的节点为链表的新的头节点
    void addAtHead(int val)
    {
        LinkedNode* newNode=new LinkedNode(val);
        newNode->next=_dummyHead->next;
        _dummyHead->next=newNode;
        _size++;
    }

    //在链表最后面加一个节点
    void addAtTail(int val)
    {
        LinkedNode* newNode=new LinkedNode(val);
        LinkedNode* cur=_dummyHead;
        while(cur->next!=nullptr)
        {
            cur = cur->next;
        }
        cur->next=newNode;
        _size++;
    }

    //在第index个节点之前插入一个新节点，例如index为0，那么新插入的为新头节点
    //如果index等于链表的长度，则说明是新插入的节点为链表的尾节点
    //如果index大于链表的长度，则返回空
    //如果index小于0，在头部插入节点
    void addAtIndex(int index,int val)
    {
        if(index>_size) return ;
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

    //删除第index个节点，如果index大于等于链表的长度，直接return，注意index是从0开始的
    void deleteAtIndex(int index)
    {
        if(index>=_size||index<0)
        {
            return ;
        }
        LinkedNode* cur =_dummyHead;
        while(index--)
        {
            cur=cur->next;
        }
        LinkedNode* tmp=cur->next;
        cur->next=cur->next->next;
        delete tmp;
        //delete命令指示释放了tmp指针原本所指的那部分内存
        //被delete释放后的指针tmp的值（地址）并非就是NULL，而是随机值
        //也就是如果不加一句tmp=nullptr,tmp会成为乱指的野指针
        //如果之后的程序不小心使用了tmp，会指向难以预想的内存空间
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
public:
    ListNode* reverseList(ListNode* head)
    {
        ListNode* temp;//保存cur的下一个节点
        ListNode* cur=head;
        ListNode* pre=NULL;
        while(cur)
        {
            temp=cur->head;//保存cur的下一个节点，因为接下来要改变cur->next
            cur->next=pre;//翻转操作
            //更新pre和cur指针
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
        ListNode* dummyHead = new ListNode(0);//设置一个虚拟头节点
        dummyHead->next=head;//将虚拟头节点指向head。方便后面做删除操作
        ListNode* cur =dummyHead;
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
//双指针的经典运用（fast & slow）

class Solution
{
public:
   ListNode* removeNthFromEnd(ListNode* head,int n)
   {
    ListNode* dummyHead = new ListNode(0);
    dummyHead->next=head;
    ListNode* slow = dummyHead;
    ListNode* fast=dummyHead;
    while(n--&&fast!=NULL)
    {
        fast=fast->next;
    }
    fast=fast->next;//fast再提前走一步，因为需要让slow指向删去节点的上一个节点
    while(fast!=NULL)
    {
        fast=fast->next;
        slow=slow->next;
    }
    slow->next=slow->next->next;

    //ListNode *tmp=slow->next;  C++释放内存的逻辑
    //slow->next=tmp->next;
    //delete tmp;

    return dummyHead->next;
   }
};

//链表相交
//求两个链表交点节点的指针，交点是指 指针相等
class Solution
{
public:
    ListNode* getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode* curA=headA;
        ListNode* curB=headB;
        int lenA=0,lenB =0;
        while(curA != NULL)
        {
            //求链表A的长度
            lenA++;
            curA=curA->next;
        }while(curB!=NULL)
        {
            //求链表B的长度
            lenB++;
            curB=curB->next;
        }

        //更新状态
        curA=headA;
        curB=headB;

        //让curA为最长链表的头，lenA为其长度
        if(lenB>lenA)
        {
            swap(lenA,lenB);
            swap(curA,curB);
        }

        //求长度差
        int gap=lenA-lenB;
        //让curA和curB在同一起点上（末尾位置对齐）
        while(gap--)
        {
            curA=curA->next;
        }

        //遍历curA和curB，遇到相同值则直接返回
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
}

//环形链表
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            // 快慢指针相遇，此时从head 和 相遇点，同时查找直至相遇
            if (slow == fast) {
                ListNode* index1 = fast;
                ListNode* index2 = head;
                while (index1 != index2) {
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index2; // 返回环的入口
            }
        }
        return NULL;
    }
};




void test()
{
    // 初始化的两种方式
    ListNode *head1 = new ListNode(5);

    // ListNode* head2 = new ListNode();
    // head2->val=5;   //如果不定义构造函数，那么在初始化的时候就不能给变量赋值
}
