#include <iostream>
#include <string>
using namespace std;
int main()
{
    string tablecard;
    cin >> tablecard;
    string playercard[5];
    string result="NO";
    for (int i = 0; i < 5; i++)
    {
        cin >> playercard[i];
    }
    for (int i = 0; i < 5; i++)
    {
        if (tablecard[0] == playercard[i][0])
        {
            result="YES";
            break;
        }
        else if(tablecard[1]==playercard[i][1]){
            result="YES";
            break;
        }
    }
    cout<<result<<endl;
    return 0;
}