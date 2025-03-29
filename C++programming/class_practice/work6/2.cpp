#include <iostream>
#include <cstring>
# include <string>
using namespace std;
void reverseStr(char *s);
int main()
{
    char str[201];
    cin.getline(str,200);
    reverseStr(str);
    puts(str);

    return 0;
}

void reverseStr(char *s)
{
    char *p=s,*q=s;
    while(*q) 
                    /* 将指针q移动到字符串末尾 */
    
    
            //q=s[strlen(s)];                       /* 指针q指向最后一个字符 */             

    while(p<q)                           /* 将指针p、q所指向位置的字符进行交换，之后指针p、q相向移动 */
    {
        


    }
}

