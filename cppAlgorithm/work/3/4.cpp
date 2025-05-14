#include <bits/stdc++.h>
using namespace std;
class heap
{
private:
    int n;  //堆的元素个数
    int *elem; //储存元素的数组
    void shiftdown(int pos)
    {

      if(this->isLeaf(pos)){ return ;}
          int left=leftChild(pos);
          int right=rightChild(pos);

          int largest=pos;
          if(left<n&&elem[left]>elem[largest]){
            largest=left;
          }
          if(right<n&&elem[right]>elem[largest]){
              largest=right;
            }
          

          //交换值
          if(largest!=pos){
            swap(elem[pos],elem[largest]);
            shiftdown(largest);
          }

    }
public:
    heap(){}
    heap(int m)
    {
        n=m;
        elem=new int[n];
    }
    ~heap()
    {
        delete[] elem;
    }
    void initial()
    {
        for(int i=0; i<n; i++)
            cin>>elem[i];
    }

    void out()
    {
        for(int i=0; i<n; i++)
        {
            cout<<elem[i];
            if (i<=n-2)
                cout<<" ";
            else
                cout<<endl;
        }
    }

    bool isLeaf(int pos) const
    {
        return ((pos>=n/2) && pos<n);
    }

    int leftChild(int pos)
    {
        return 2*pos+1;
    }

    int rightChild(int pos)
    {
        return 2*pos+2;
    }

    void arrange()
    {
        for(int i=(n-1)/2;i>=0; i--)
        {
            shiftdown(i);
        }
    }

    void insertElem(int x)
    {
        int* new_elem=new int[n+1];
        copy(elem,elem+n,new_elem);
        new_elem[n]=x;
        n++;
        delete[] elem;
        elem=new_elem;
        this->arrange();

    }
};

int main()
{
    int m;
    cin>>m;
    heap *ex=new heap(m);
    ex->initial();
    ex->arrange();
    ex->out();
    int insData;
    cin>>insData;
    ex->insertElem(insData);
    ex->out();
    return 0;
}