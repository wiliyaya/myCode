#include <iostream>
#include <string>
using namespace std;
bool isoran(const string& str)
{
    int n = str.size();
    for (int i = 0; i < n; i++)
    {
        
        bool I = (str[i] == 'a' || str[i] == 'o' || str[i] == 'u' || str[i] == 'i' || str[i] == 'e'||str[i]=='n'); //|| str[i] == 'n');
        bool nextI=str[i + 1] == 'a' || str[i + 1] == 'o' || str[i + 1] == 'u' || str[i + 1] == 'i' || str[i + 1] == 'e'||str[i+1]=='n';
        if(!I && !nextI){
            return false;
        }
        // if (str[i] == 'a' || str[i] == 'o' || str[i] == 'u' || str[i] == 'i' || str[i] == 'e' || str[i] == 'n')
        /*if (str[i] == 'a' || str[i] == 'o' || str[i] == 'u' || str[i] == 'i' || str[i] == 'e'||str[i] =='n')
        {
            continue;
        }

        // if (str[i + 1] != 'a' && str[i + 1] != 'o' && str[i + 1] != 'u' && str[i + 1] != 'i' && str[i + 1] != 'e')
        else
        
            if (str[i + 1] == 'a' || str[i + 1] == 'o' || str[i + 1] == 'u' || str[i + 1] == 'i' || str[i + 1] == 'e')
            {
                continue;
                // return false;
            }
        

        else return false;*/
    }
    return true;
}
int main()
{
    string str;
    cin >> str;
    cout << (isoran(str) ? "YES" : "NO") << endl;
    return 0;
}