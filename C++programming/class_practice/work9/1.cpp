#include <iostream>
#include <cstdlib>
using namespace std;
class matrix
{
private:
    int rows, cols;
    int **p;
public:
    matrix();
    matrix(int &M, int &N);
    matrix(matrix &A, int &&m, int &n);
    ~matrix();

    matrix multi(int x);   // 数乘
    int det();           // 计算行列式
    void out();    //输出矩阵
    void input();

    matrix operator+(matrix &another); //重载加法运算实现矩阵相加
    matrix operator*(matrix &another); //重载乘法运算实现矩阵相乘
};
matrix::matrix(int &M, int &N)
{
    rows=M, cols=N;
    p=new int*[rows];
    for(int i=0;i<M;i++)
    {
        p[i]=new int[cols];
    }
}//构建一个矩阵

matrix::matrix(matrix &A, int &&m, int &n)   //从矩阵A中删除第m行第n列后得到新的矩阵
{
    this->rows = A.rows - 1;
    this->cols = A.cols - 1;
    this->p = new int *[this->rows];
    for (int i = 0; i < this->rows; i++)
    {
        p[i] = new int[this->cols];
    }
    for (int i = 0, k = 0; i < A.rows; i++)
    {
        if (i != m)
        {
            for (int j = 0, g = 0; j < A.cols; j++)
            {
                if (j != n)
                {
                    p[k][g] = A.p[i][j];
                    g++;
                }
            }
            k++;
        }
    }
}

matrix::~matrix()
{
    for(int i=0; i<rows; i++)
        delete[] p[i];

    delete[] p;
}

matrix matrix::multi(int x)   // 数乘
{
    matrix tmp(rows, cols);//临时变量储存矩阵
    for(int i=0;i<tmp.rows;i++)
    {
        for(int j=0;j<tmp.cols;j++)
        {
            tmp.p[i][j]=(this->p[i][j])*x;
        }
    }

    return tmp;
}

void matrix::out()    //输出矩阵
{
     /* 逐行输出，数据间用空格分隔 */
     for(int i=0;i< this->rows;i++)
     {
        for(int j=0;j< this->cols;j++)
        {
            cout<<this->p[i][j]<<' ';
        }
        cout<<endl;
     }
}

void matrix::input()
{
    for(int i=0; i<rows; i++)
        for(int j=0; j<cols; j++)
            cin>>p[i][j];

}

matrix matrix::operator+(matrix &another) //重载加法运算实现矩阵相加
{
    matrix tmp(rows, cols);
    /* 矩阵对应位置元素相加 */
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            tmp.p[i][j]=this->p[i][j]+another.p[i][j];
        }
    }
    return tmp;
}

matrix matrix::operator*(matrix &another)  //重载乘法运算实现矩阵相乘
{
    matrix tmp(rows, another.cols);
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<another.cols; j++)
        {
           /* 计算A矩阵的第i行与B矩阵的第j列元素对应相乘后之和，作为新矩阵的第i行第j列元素的值 */
           tmp.p[i][j]=0;
           for(int k=0;k<cols;k++)
           {
            tmp.p[i][j]+=(this->p[i][k])*another.p[k][j];
           }
        }
    }
    return tmp;
}

int matrix::det()
{
    if (rows==1)
        return p[0][0];
    else
    {
        int result=0, flag;
        for(int i=0; i<cols; i++)
        {
            flag=(i%2)?-1:1;
            matrix tmp(*this, 0, i);
            result=result+flag*p[0][i]*tmp.det();    // 使用代数余子式求行列式的值, 递归
        }
        return result;
    }
}
int main()
{
    int M,N;

    // A矩阵的行和列
    cin>>M>>N;

    matrix mA(M, N);    //生成A矩阵

    // 输入矩阵值

    mA.input();

    // 输入数乘值

    int x;
    cin>>x;

    matrix mm1=mA.multi(x);

    mm1.out();

    //B矩阵的行和列
    int K, L;
    cin>>K>>L;

    matrix mB(K, L);  //生成B矩阵
    mB.input();

    /* 求矩阵A和矩阵B的和 */

    if (M==K && N==L)
    {
        matrix mm2=mA+mB;
        mm2.out();
    }

   /* 求矩阵A和矩阵B的乘积矩阵 */
    if (N==K)
    {
        matrix mm3=mA*mB;
        mm3.out();
    }

    /* 矩阵A的行列式的值 */
    if (M==N)
        cout<<mA.det()<<endl;

    if (K==L)
        cout<<mB.det()<<endl;

    return 0;
}