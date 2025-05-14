#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <sstream>
#include <vector>
#include <algorithm>
#include <thread>
#include <mutex>

using namespace std;

// trie节点类
class trieNode {
public:
    trieNode *children[26];
    bool is_end;
    int count;
    trieNode() : is_end(false), count(0) {
        for (int i = 0; i < 26; i++) children[i] = nullptr;
    }
};

// Trie树类
class Trie {
public:
    trieNode *root;
    Trie() { root = new trieNode(); }
    ~Trie() { deleteSubtree(root); }
    void insert(const string &word) {
        trieNode *current = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (!current->children[index])
                current->children[index] = new trieNode();
            current = current->children[index];
        }
        current->is_end = true;
        current->count++;
    }
    void collectWord(trieNode *node, string current_word, vector<pair<string, int>> &result) {
        if (!node) return;
        if (node->is_end) result.emplace_back(current_word, node->count);
        for (int i = 0; i < 26; i++)
            if (node->children[i])
                collectWord(node->children[i], current_word + char('a' + i), result);
    }
    vector<pair<string, int>> getAllWord() {
        vector<pair<string, int>> result;
        collectWord(root, "", result);
        sort(result.begin(), result.end(),
            [](const auto &a, const auto &b) {
                return a.second > b.second || (a.second == b.second && a.first < b.first);
            });
        return result;
    }
    // 合并另一棵Trie到当前Trie
    void mergeTrie(trieNode *node, string current_word = "") {
        if (!node) return;
        if (node->is_end) {
            for (int i = 0; i < node->count; ++i)
                insert(current_word);
        }
        for (int i = 0; i < 26; i++)
            if (node->children[i])
                mergeTrie(node->children[i], current_word + char('a' + i));
    }
private:
    void deleteSubtree(trieNode *Node) {
        if (!Node) return;
        for (int i = 0; i < 26; i++)
            if (Node->children[i]) deleteSubtree(Node->children[i]);
        delete Node;
    }
};

// 把大写字母转化为小写
string cleanWord(const string &raw_word) {
    string cleaned;
    for (char ch : raw_word)
        if (isalpha(ch)) cleaned += tolower(ch);
    return cleaned;
}

// 线程处理函数
void process_lines(const vector<string> &lines, Trie &trie) {
    for (const string &line : lines) {
        string mod_line = line;
        for (char &ch : mod_line)
            if (!isalpha(ch)) ch = ' ';
        istringstream iss(mod_line);
        string raw_word;
        while (iss >> raw_word) {
            string cleaned = cleanWord(raw_word);
            if (!cleaned.empty())
                trie.insert(cleaned);
        }
    }
}

int main() {
    ifstream file("in.txt");
    if (!file.is_open()) {
        cerr << "Error" << endl;
        return 1;
    }
    vector<string> all_lines;
    string line;
    while (getline(file, line)) all_lines.push_back(line);
    file.close();

    // 分成4份
    size_t total = all_lines.size();
    size_t part = (total + 3) / 4;
    vector<string> part1(all_lines.begin(), all_lines.begin() + min(part, total));
    vector<string> part2(all_lines.begin() + min(part, total), all_lines.begin() + min(2 * part, total));
    vector<string> part3(all_lines.begin() + min(2 * part, total), all_lines.begin() + min(3 * part, total));
    vector<string> part4(all_lines.begin() + min(3 * part, total), all_lines.end());

    Trie trie1, trie2, trie3, trie4;
    thread t1(process_lines, cref(part1), ref(trie1));
    thread t2(process_lines, cref(part2), ref(trie2));
    thread t3(process_lines, cref(part3), ref(trie3));
    thread t4(process_lines, cref(part4), ref(trie4));
    t1.join(); t2.join(); t3.join(); t4.join();

    // 合并4棵Trie
    Trie final_trie;
    final_trie.mergeTrie(trie1.root);
    final_trie.mergeTrie(trie2.root);
    final_trie.mergeTrie(trie3.root);
    final_trie.mergeTrie(trie4.root);

    vector<pair<string, int>> word_count = final_trie.getAllWord();
    int n = 0;
    for (auto &elem : word_count) {
        if (n == 100) break;
        n++;
        cout << elem.first << ' ' << elem.second << endl;
    }
    return 0;
}