#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
 
using namespace std;
 
// 定义图书信息类
class BookInfo
{
public:
    int ID; // 登录号
    string name; // 书名
    string author; // 作者名
    int category; // 分类号
    string publisher; // 出版单位
    string publishDate; // 出版时间
    double price; // 价格
 
    // 构造函数
    BookInfo(int id, string n, string a, int c, string p, string pd, double pr)
    {
        ID = id;
        name = n;
        author = a;
        category = c;
        publisher = p;
        publishDate = pd;
        price = pr;
    }
 
    // 打印图书信息
    void print() {
        cout << "登录号：" << ID << endl;
        cout << "书名：" << name << endl;
        cout << "作者名：" << author << endl;
        cout << "分类号：" << category << endl;
        cout << "出版单位：" << publisher << endl;
        cout << "出版时间：" << publishDate << endl;
        cout << "价格：" << price << endl;
    }
 
    // 将图书信息转为字符串
    string toString()
    {
        string str = to_string(ID) + "," + name + "," + author + "," + to_string(category) + "," + publisher + "," + publishDate + "," + to_string(price);
        return str;
    }
};
 
// 定义图书信息管理
class BookManager
{
private:
    vector<BookInfo> books; // 图书信息数组
    string filename; // 保存图书信息的文件名
 
public:
    // 构造函数
    BookManager(string fn)
    {
        filename = fn;
        loadBooks();
    }
 
    // 添加图书信息
    void addBook()
    {
        int id, category;
        string name, author, publisher, publishDate;
        double price;
        cout << "请输入登录号：";
        cin >> id;
        cout << "请输入书名：";
        cin >> name;
        cout << "请输入作者名：";
        cin >> author;
        cout << "请输入分类号：";
        cin >> category;
        cout << "请输入出版单位：";
        cin >> publisher;
        cout << "请输入出版时间：";
        cin >> publishDate;
        cout << "请输入价格：";
        cin >> price;
        BookInfo book(id, name, author, category, publisher, publishDate, price);
        books.push_back(book);
        saveBooks();
        cout << "添加成功！" << endl;
    }
 
    // 查找图书信息
    void findBookByName()
    {
        string name;
        cout << "请输入要查找的书名：";
        cin >> name;
        vector<BookInfo> results;
        for (int i = 0; i < books.size(); i++)
        {
            if (books[i].name == name)
            {
                results.push_back(books[i]);
            }
        }
        if (results.size() == 0)
        {
            cout << "未找到该书名的图书信息！" << endl;
        }
        else
        {
            cout << "共找到" << results.size() << "本书：" << endl;
            for (int i = 0; i < results.size(); i++)
            {
                results[i].print();
                cout << endl;
            }
        }
    }
 
    // 查找图书信息
    void findBookByAuthor()
    {
        string author;
        cout << "请输入要查找的作者名:";
        cin >> author;
        vector<BookInfo> results;
        for (int i = 0; i < books.size(); i++)
        {
            if (books[i].author == author)
            {
                results.push_back(books[i]);
            }
        }
        if (results.size() == 0)
        {
            cout << "未找到该作者名的图书信息！" << endl;
        }
        else
        {
            cout << "共找到" << results.size() << "本书：" << endl;
            for (int i = 0; i < results.size(); i++)
            {
                results[i].print();
                cout << endl;
            }
        }
    }
 
    // 删除图书信息
    void deleteBook()
    {
        int id;
        cout << "请输入要删除的登录号：";
        cin >> id;
        for (int i = 0; i < books.size(); i++)
        {
            if (books[i].ID == id)
            {
                books.erase(books.begin() + i);
                saveBooks();
                cout << "删除成功！" << endl;
                return;
            }
        }
        cout << "未找到该图书信息！" << endl;
    }
 
    // 修改图书信息
    void modifyBook()
    {
        int id;
        cout << "请输入要修改的登录号：";
        cin >> id;
        for (int i = 0; i < books.size(); i++)
        {
            if (books[i].ID == id)
            {
                cout << "请输入新的书名：";
                cin >> books[i].name;
                cout << "请输入新的作者名：";
                cin >> books[i].author;
                cout << "请输入新的分类号：";
                cin >> books[i].category;
                cout << "请输入新的出版单位：";
                cin >> books[i].publisher;
                cout << "请输入新的出版时间：";
                cin >> books[i].publishDate;
                cout << "请输入新的价格：";
                cin >> books[i].price;
                saveBooks();
                cout << "修改成功！" << endl;
                return;
            }
        }
        cout << "未找到该图书信息！" << endl;
    }
 
    // 按价格排序
    void sortByPrice()
    {
        sort(books.begin(), books.end(), [](BookInfo a, BookInfo b) {
            return a.price < b.price;
            });
        cout << "按价格排序成功！" << endl;
    }
 
    // 显示所有图书信息
    void showAllBooks()
    {
        for (int i = 0; i < books.size(); i++)
        {
            books[i].print();
            cout << endl;
        }
    }
 
    // 显示菜单
    void showMenu()
    {
        cout << "|------------------------------------|" << endl;
        cout << "|||||||||欢迎使用图书管理系统|||||||||" << endl;
        cout << "|------------------------------------|" << endl;
        cout << "|____________________________________|" << endl;
        cout << "|***********1. 添加图书信息**********|" << endl;
        cout << "|***********2. 按书名查询************|" << endl;
        cout << "|***********3. 按作者名查询**********|" << endl;
        cout << "|***********4. 删除图书信息**********|" << endl;
        cout << "|***********5. 修改图书信息**********|" << endl;
        cout << "|***********6. 按价格排序************|" << endl;
        cout << "|***********7. 显示所有图书信息******|" << endl;
        cout << "|***********0. 退出******************|" << endl;
        cout << "|____________________________________|" << endl;
    }
 
    // 从文件中加载图书信息
    void loadBooks()
    {
        ifstream file(filename);
        if (file.is_open())
        {
            string line;
            while (getline(file, line))
            {
                int id = stoi(line.substr(0, line.find(",")));
                line = line.substr(line.find(",") + 1);
                string name = line.substr(0, line.find(","));
                line = line.substr(line.find(",") + 1);
                string author = line.substr(0, line.find(","));
                line = line.substr(line.find(",") + 1);
                int category = stoi(line.substr(0, line.find(",")));
                line = line.substr(line.find(",") + 1);
                string publisher = line.substr(0, line.find(","));
                line = line.substr(line.find(",") + 1);
                string publishDate = line.substr(0, line.find(","));
                line = line.substr(line.find(",") + 1);
                double price = stod(line);
                BookInfo book(id, name, author, category, publisher, publishDate, price);
                books.push_back(book);
            }
            file.close();
        }
    }
 
    // 将图书信息保存到文件
    void saveBooks()
    {
        ofstream file(filename);
        if (file.is_open())
        {
            for (int i = 0; i < books.size(); i++)
            {
                file << books[i].toString() << endl;
            }
            file.close();
        }
    }
 
    // 运行图书信息管理系统
    void run()
    {
        int choice;
        while (true)
        {
            showMenu();
            cout << "请输入选项：";
            cin >> choice;
            switch (choice)
            {
            case 1:
                addBook();
                break;
            case 2:
                findBookByName();
                break;
            case 3:
                findBookByAuthor();
                break;
            case 4:
                deleteBook();
                break;
            case 5:
                modifyBook();
                break;
            case 6:
                sortByPrice();
                break;
            case 7:
                showAllBooks();
                break;
            case 0:
                cout << "谢谢使用！" << endl;
                return;
            default:
                cout << "无效选项，请重新输入！" << endl;
            }
        }
    }
};
 
int main()
{
    BookManager manager("books.txt");
    manager.run();
    return 0;
}