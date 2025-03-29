#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    int total = 0;
    bool judged = false; // 记录这个@是不是已经算过的@
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '@')
        {
            judged = false;
        }
        if (isalpha(s[i]) && !judged)
        { // 如果s[i]是字母，这是string库的语法
            int precount = 0;
            int prepos = 0;
            for (int j = i; j < n; j++)
            {
                if (isalnum(s[j]) || s[j] == '_')
                { // 判断是s[j]是不是数字或者字母或者那个符号'_'
                    if (isalpha(s[j]))
                        precount++;
                    prepos++; // 找位置和找字母还是不一样的，得注意一下
                }
                else
                    break;
            }
            int atpos = prepos + i;
            if (atpos >= n || s[atpos] != '@')
                continue; // 说明这个后面没有@了，做不了邮箱开头，跳过，从后面找

            int next = atpos + 1; // 计算后面的有效可能，找'.'，如果后面直接接上点，也是错的
            int dotcount = 0;
            for (int j = next; j < n; j++)
            {
                if (isalnum(s[j]))
                {
                    dotcount++; // 如果@后面是字母或者数字，加上，其实没什么用，只是用来找'.'的位置
                }
                else
                    break;
            }
            int dotpos = dotcount + next; // 与找@相同，一样流程，判断后面有没有'.'，如果该位置没有点，就跳过，从后面找
            if (dotpos >= n || s[dotpos] != '.')
                continue;

            int end = dotpos + 1;
            int endcount = 0;
            for (int j = end; j < n; j++)
            {
                if (isalpha(s[j]))
                {
                    endcount++; //'.'后面是字母，不能含有数字等其他东西，有就污染字串了，得赶快break
                }
                else
                    break;
            }
            total += endcount * precount;
            judged = true;
        }
    }
    cout << total << endl;
    return 0;
} // 我本来不想写注释的，但这个题目不写注释的话，我以后可能就永远看不懂了...