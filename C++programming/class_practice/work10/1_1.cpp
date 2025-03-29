#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cctype>
using namespace std;
string rmspace(const string &str)
{
    size_t start=0;
    size_t end=str.size()-1;

    while(start<=end&&(isspace(str[start])||str[start]=='\t'))
    {
        start++;
    }//找第一个非空格的数
    while(end>=start&&(isspace(str[end])||str[end]=='\t'))
    {
        end--;
    }
    if(start>end)
    // 如果 start 大于 end，表示字符串为空，直接返回空字符串
    {
        return "";
    }
    return str.substr(start,end-start+1);
}

string remainspace(const string&str)
{
    string result;
    bool spaced=true;
    for(size_t i=0;i<str.size();i++)
    {
        char c=str[i];

        if(isspace(c))
        {
            if(!spaced&&(result.empty()||!isspace(result.back())))
            {
                result+=' ';
                spaced=true;
            }
            else continue;
        }
        else{
            result+=c;
            spaced=false;
        }
    }
    return result;
}

void formatstr(const string&line,int num,ofstream& fout)
{
    size_t pos=line.find(':');
    if(pos==string::npos)
    {
        fout<<line<<endl;
        return ;
    }
    string left=rmspace(line.substr(0,pos));
    string right=rmspace(line.substr(pos+1));
    left=remainspace(left);
    right=remainspace(right);

    while(left.length()<num-1)
    {
        left+=' ';
    }
    fout<<left<<": "<<right<<endl;
}
int main()
{
    ifstream fin("listin.txt");
    ofstream fout("listout.txt");

    int num;
    cin>>num;
    string line;

    while(getline(fin,line))
    {
        formatstr(line,num,fout);
    }
    fin.close();
    fout.close();
}

