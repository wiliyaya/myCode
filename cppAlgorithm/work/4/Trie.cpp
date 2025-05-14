#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

// trie节点类
class trieNode
{
  // private:
public:
  // char c;
  trieNode *children[26];
  bool is_end; // 是否为一个单词的末尾
  int count;   // 记录该单词的数量
  trieNode() : is_end(false), count(0)
  {
    for (int i = 0; i < 26; i++)
    {
      children[i] = nullptr;
    }
  }
};

// Tire树类
class Trie
{
private:
  trieNode *root;

public:
  Trie()
  {
    // 通过构造函数强制创建一个根节点
    root = new trieNode();
  }

  ~Trie()
  {
    deleteSubtree(root);
  }

private:
  void deleteSubtree(trieNode *Node)
  {
    if (!Node)
    {
      return;
    }
    for (int i = 0; i < 26; i++)
    {
      if (Node->children[i])
      {
        deleteSubtree(Node->children[i]);
      }
    }
  }

public:
  // 插入单词
  void insert(string &word)
  {
    trieNode *current = root; // 用current，表示当前节点，初始化为根节点
    for (char ch : word)
    {                       // 对word里的每一个字符遍历
      int index = ch - 'a'; // 获取字符对应的索引
      if (!current->children[index])
      {
        // 如果对应位置为空（先前没有单词的前缀是这个）。强制创建一个新的节点
        current->children[index] = new trieNode();
      }
      current = current->children[index]; // current下移到index对应的子树
    }
    current->is_end = true; // 结束遍历，标记单词结束
    current->count++;       // 单词数量++
  }

  // 递归遍历Trie树 收集单词及其词频
  void collectWord(trieNode *node, string current_word, vector<pair<string, int>> &result)
  {
    if (!node)
      return;

    if (node->is_end)
    {
      result.emplace_back(current_word, node->count); // 察觉到一个单词结束，把该单词和词频加入result数组中
    }

    for (int i = 0; i < 26; i++)
    { // 对该节点的子节点进行遍历
      if (node->children[i])
      {                                                            // 对应的子树不为空
        char ch = 'a' + i;                                         // 实现从数字到字符串的转化
        collectWord(node->children[i], current_word + ch, result); // 递归，current_word+ch相当于新的前缀，查找以这个为前缀的单词
      }
    }
  }

  // 输出词频的函数
  vector<pair<string, int>> getAllWord()
  {
    vector<pair<string, int>> result; // 先创一个用来储存词频的数组
    collectWord(root, "", result);    // 收集单词及其词频
                                   // 排序
    sort(result.begin(), result.end(),
         [](const auto &a, const auto &b)
         {
           return a.second > b.second || (a.second == b.second && a.first < b.first);
         });
    return result;
  }
};

// 把大写字母转化为小写
string cleanWord(const string &raw_word)
{
  string cleaned;
  for (char ch : raw_word)
  {
    if (isalpha(ch))
    {
      cleaned += tolower(ch);
    }
  }
  return cleaned;
}

// 对文件的读取在主函数中
int main()
{
  Trie trie;
  // fstream file("D:/a_CPPCODE/cppAlgorithm/work/4/in.txt");
  ifstream file("in.txt"); // 创建文件流的对象，通过文件流对象读取文件

  if (!file.is_open())
  {
    cerr << "Error" << endl;
    return 1;
  }

  string line;
  while (getline(file, line))
  { // 每行每行地从文件中读取字符串，并存放在line中
    for (char &ch : line)
    { // 处理这行字符串，把所有的标点都替换成空格
      if (!isalpha(ch))
      {
        ch = ' ';
      }
    }

    istringstream iss(line); // istringstream对象
    string raw_word;
    while (iss >> raw_word)
    { // 用raw_word来储存iss从line中读取的字符
      string cleaned = cleanWord(raw_word);
      if (!cleaned.empty())
      {
        trie.insert(cleaned); // 把读入的单词加入到树中
      }
    }
  }

  file.close(); // 对文本处理好之后要关闭文件

  vector<pair<string, int>> word_count = trie.getAllWord();
  int n = 0;
  for (auto &elem : word_count)
  {
    if (n == 100)
      break;
    n++;
    cout << elem.first << ' ' << elem.second << endl;
  }

  return 0;
}
