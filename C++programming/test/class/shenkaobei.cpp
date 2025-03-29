#include <iostream>
#include <cstring>
#include <cassert>
using namespace std;
// StringWrapper 类定义
class StringWrapper
{
private:
    char *str;

public:
    // 构造函数
    StringWrapper(const char *s = "")
    {
        if (s)
        {

            str = new char[strlen(s) + 1];
            strcpy(str, s);
        }
        else
        {
            str = new char[1];
            *str = '\0';
        }
    }

    StringWrapper(const StringWrapper&other){
        str = new char[strlen(other.str)+1];
        strcpy(str,other.str);
    }

    StringWrapper &operator=(const StringWrapper &other)
    {
        if (this != &other)
        {
            delete[] str;
            str = new char[strlen(other.str) + 1];
            strcpy(str, other.str);
        }
        return *this;
    }

    // 析构函数
    ~StringWrapper()
    {
        delete[] str;
    }

    // 获取字符串内容
    const char *getStr() const
    {
        return str;
    }
};

// 测试函数
void testDeepCopy()
{
    StringWrapper sw1("Hello, World!");
    StringWrapper sw2 = sw1; // 使用拷贝构造函数

    char ch;
    cin >> ch;
    const char *temp = sw1.getStr();
    const_cast<char *>(temp)[7] = ch; // 修改 sw1 的字符串内容（不推荐这样做）

    // 打印两个 StringWrapper 的内容以验证深拷贝
    cout << "sw1: " << sw1.getStr() << endl;
    cout << "sw2: " << sw2.getStr() << endl;

    // 验证两个 StringWrapper 是否独立（应该输出 false，因为原始字符串被修改了，
    // 但由于我们进行了深拷贝，所以 sw2 的内容应该保持不变）
}

int main()
{
    testDeepCopy();
    return 0;
}
