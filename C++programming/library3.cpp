//此文件不可编译

#include<iostream>
#include<vector>
#include <time.h>
#include <sstream>
#include<fstream>
#include<string.h>
#include<conio.h>


结构体
struct LendBook
{   //被借出去的书
    string time;   //借阅时间
    string name;   //书名
};
 
struct LendList
{   //借阅的书的链表
    string stuNum;  //学号
    LendList *next;  //指针
    vector<LendBook>v;  //向量，存储借阅的书
};
 
struct Book{      //图书文件
    string name;   //书名
    double price;  //价格
    string author;  //作者
    double allStock; //所有库存
    double nowStock; //现有库存
    bool isLend;     //借阅与否
    vector<string>record;  //存储借阅记录的向量
};
 
struct List{    //图书链表
    Book *book;  //Book类结构体
    List *next;  //指针
};

//函数
//管理员模块
string timeNow(){  //得到现在的时间 
	time_t rawtime;
    time(&rawtime);   
    struct tm * timeinfo;
    timeinfo = localtime(&rawtime);
    timeinfo = gmtime(&rawtime);
    char   pblgtime[20];
    strftime(pblgtime, 20, "%Y-%m-%d-%X", localtime(&rawtime));
    int i=0;
    string str="";
    while(pblgtime[i]!='\0'){
    	str+=pblgtime[i];
    	i++;
	}
    return str;
}
List * fileToList(){   //将图书的信息转换为链表 
	List *list = new List;
	list->next=NULL;
	List *r = list;
	ifstream myfile;
	myfile.open("LibraryDate.txt",ios::in);   //读文件 
    string temp; 
    if (!myfile.is_open())
    {
        cout << "未成功打开文件" << endl;
    } 
    while(getline(myfile,temp)) 
    {
//        cout<<temp<<endl;
		stringstream is(temp);    //将is绑定到str
    	string s;
    	int i=0;
    	Book *book = new Book();
    	vector<string>v;
   	 	while (is >> s)
    	{
    		switch(i){
    			case 0:{
    				book->name = s;
					break;
				}
				case 1:{
					double nums;
					stringstream ss;
					ss<<s;
					ss>>nums;
					book->price = nums;
					break;
				}
				case 2:{
					book->author = s;
					break;
				}
				case 3:{
					double nums;
					stringstream ss;
					ss<<s;
					ss>>nums;
					book->allStock = nums;
					break;
				}
				case 4:{
					double nums;
					stringstream ss;
					ss<<s;
					ss>>nums;
					book->nowStock = nums;
					break;
				}
				case 5:{
					int ret = s.compare("true");
					switch(ret){
						case 0:{
							book->isLend = true;
							break;
						}
						default:{
							book->isLend = false;
							break;
						}
					}
					break;
				}
				default:{
					v.push_back(s);
					break;
				}
			}
			i++;
   		}
   		List *p = new List;
   		book->record=v;
   		p->book = book;
   		r->next = p;
   		p->next = NULL;
   		r = p;
    }
    myfile.close();
    return list;
}



void reviseFile(List *&m){     //修改图书文件信息 
	if(m==NULL){
		cout<<"修改文件失败！！！"<<endl; 
		return ;
	}
	ofstream ofs;
	ofs.open("LibraryDate.txt",ios::out);
	List *r = m->next;
	while(r!=NULL){
		string yes;
		if(r->book->isLend){
			yes = "true";
		}
		else{
			yes = "false";
		}
		ostringstream ost;
		vector<string>v;
		v = r->book->record;
		for (vector<string>::iterator it = v.begin(); it != v.end(); it++) {
			ost<<*it;
		}
		ost<<" "<<"\n";
    	ostringstream oss;
		oss<<r->book->name<<" "<<r->book->price<<" "<<r->book->author<<" "<<r->book->allStock<<" "<<r->book->nowStock<<" "<<yes<<" ";
		ofs<<oss.str();
		ofs<<" ";   //在每个信息的后面插入空格
		ofs<<ost.str();
		r=r->next;
	}
	ofs.close();
}


void changeElement(List *&m){   //修改图书个别信息 
	if(m==NULL){
		cout<<"修改失败！"<<endl;
		return ;
	}
	else{
		cout<<"-----现在您是在修改数据界面！-----"<<endl<<"在下一项输入”999999“以退出"<<endl; 
		cout<<"您需要先输入书名"<<"或许您需要先预览一下书目？输入“1”预览，输入“0”直接进入修改：";
		int choice;
		while (!(cin >>choice))
			{
				cin.clear();
				while (cin.get() != '\n')
				{
					continue;
				}//跳过错误输入
				cout << "请输入一个数字："<<endl;
			}
		List *r = m->next;
		List *pre=m;
		
		if(choice==999999){
			cout<<"退出成功！"<<endl;
			return ;
		}
		
		if(choice==1){
			int i=0;
			while(r!=NULL){
				if(i%5==0){
					cout<<endl;
				}
				cout<<r->book->name<<" ";
				i++;
				r=r->next;
			}
		}
		string str;
		cout<<"请输入你需要修改的书的书名：";
		cin>>str;
		
		r = m->next;
		while(r!=NULL){
			if(r->book->name==str){
				break;
			}
			r=r->next;
		}
		if(r==NULL){
			cout<<"您想修改的书不存在！此项即将退出，试一试重新输入吧！"<<endl;
			return ;
		}
		
		cout<<"您可以自由选择需要修改的项目，输入相应的序号即可！如果想修改数项，请输入“0”"<<endl;
		cout<<"1.书名 2.价格 3.作者 4.总库存 5.现库存 6是否借出："<<endl;
		while (!(cin >>choice)){
			cin.clear();
			while (cin.get() != '\n')
			{
				continue;
			}//跳过错误输入
			cout << "请输入一个数字："<<endl;
		}
		while(choice>6||choice<0){
			cout<<"检查一下是不是序号输错了,再输一遍吧"<<endl;
			while (!(cin >>choice)){
				cin.clear();
				while (cin.get() != '\n'){
					continue;
				}//跳过错误输入
				cout << "请输入一个数字："<<endl;
			}
		}
		string tarStr;
		double tarNum;
		switch(choice){
			case 1:{
				cout<<"请输入您想修改的名字：";
				cin>>tarStr;
				r->book->name=tarStr;
				break;
			}
			case 2:{
				cout<<"请输入您想修改的价格：";
				while (!(cin >>tarNum)){
					cin.clear();
					while (cin.get() != '\n'){
						continue;
					}//跳过错误输入
					cout << "请输入一个数字："<<endl;
				}
				r->book->price=tarNum; 
				break;
			}
			case 3:{
				cout<<"请输入您想修改的作者：";
				cin>>tarStr;
				r->book->author = tarStr;
				break;
			}
			case 4:{
				cout<<"请输入您想修改的总库存量：";
				while (!(cin >>tarNum)){
					cin.clear();
					while (cin.get() != '\n'){
						continue;
					}//跳过错误输入
					cout << "请输入一个数字："<<endl;
				}
				r->book->allStock=tarNum;
				break;
			}
			case 5:{
				cout<<"请输入您想修改的现库存量：";
				while (!(cin >>tarNum)){
					cin.clear();
					while (cin.get() != '\n'){
						continue;
					}//跳过错误输入
					cout << "请输入一个数字："<<endl;
				}
				r->book->nowStock=tarNum;
				break;
			}
			case 6:{
				cout<<"输入”1“代表借出，输入“0”代表未借出：";
				while (!(cin >>tarNum)){
					cin.clear();
					while (cin.get() != '\n'){
						continue;
					}//跳过错误输入
					cout << "请输入一个数字："<<endl;
				}
				bool is;
				if(tarNum==1){
					is = true;
				} 
				else{
					is=false;
				}
				r->book->isLend=is;
				break;
			}
			case 0:{
				cout<<"请输入您想修改的名字：";
				cin>>tarStr;
				r->book->name=tarStr;
				
				cout<<"请输入您想修改的价格：";
				while (!(cin >>tarNum)){
					cin.clear();
					while (cin.get() != '\n'){
						continue;
					}//跳过错误输入
					cout << "请输入一个数字："<<endl;
				}
				r->book->price=tarNum; 
				
				cout<<"请输入您想修改的作者：";
				cin>>tarStr;
				r->book->author = tarStr;
				
				cout<<"请输入您想修改的总库存量：";
				while (!(cin >>tarNum)){
					cin.clear();
					while (cin.get() != '\n'){
						continue;
					}//跳过错误输入
					cout << "请输入一个数字："<<endl;
				}
				r->book->allStock=tarNum;
				
				cout<<"请输入您想修改的现库存量：";
				while (!(cin >>tarNum)){
					cin.clear();
					while (cin.get() != '\n'){
						continue;
					}//跳过错误输入
					cout << "请输入一个数字："<<endl;
				}
				r->book->nowStock=tarNum;
				
				cout<<"输入”1“代表借出，输入“0”代表未借出：";
				while (!(cin >>tarNum)){
					cin.clear();
					while (cin.get() != '\n'){
						continue;
					}//跳过错误输入
					cout << "请输入一个数字："<<endl;
				}
				bool is;
				if(tarNum==1){
					is = true;
				} 
				else{
					is=false;
				}
				r->book->isLend=is;
				break;
			}
			default:{
				
				break;
			}
		}
		reviseFile(m);
		cout<<"修改成功！！"<<endl;
	}
}


void addElement(List *&m){   //添加图书 
	if(m!=NULL){
		List *r = m;
		while(r->next!=NULL){
			r=r->next;
		}
		cout<<endl<<"TIPS: 你正在进行添加操作，输入“999999”即可终止此操作!!"<<endl;
		cout<<"新增的书默认没有借出记录"<<endl;
		string pause = "999999";
		
		string str01;
		cout<<"请输入书籍名：";
		cin>>str01;
		if(str01==pause){
			cout<<"-----退出成功！-----"<<endl;
			return ;
		}
		
		double price;
		cout<<"请输入价格：";
		while (!(cin >>price))
		{
			cin.clear();
			while (cin.get() != '\n')
			{
				continue;
			}//跳过错误输入
			cout << "请输入一个数字："<<endl;
		}
		
		if(price == 999999){
			cout<<"-----退出成功！-----"<<endl;
			return ;
		}
		
		string str02;
		cout<<"请输入作者名：";
		cin>>str02;
		
		if(str02==pause)
        {
			cout<<"-----退出成功！-----"<<endl;
			return ;
		}
		
		double nums01;
		cout<<"请输入总库存量：";
		while (!(cin >>nums01))
		{
			cin.clear();
			while (cin.get() != '\n')
			{
				continue;
			}//跳过错误输入
			cout << "请输入一个数字："<<endl;
		}
		if(nums01==999999){
			cout<<"退出成功！"<<endl;
			return ;
		}
		
		double nums02;
		cout<<"请输入现有库存量：";
		while (!(cin >>nums02))
		{
			cin.clear();
			while (cin.get() != '\n')
			{
				continue;
			}//跳过错误输入
			cout << "请输入一个数字："<<endl;
		}
		
		if(nums02==999999){
			cout<<"退出成功！"<<endl;
			return ;
		}
		
		Book *book = new Book;
		List *p = new List;
		book->name = str01;
		book->price = price;
		book->author = str02;
		book->isLend = false;
		book->allStock = nums01;
		book->nowStock = nums02;
		p->book = book;
		r->next = p;
		p->next = NULL;
		cout<<"添加新书成功！"<<endl;
		
		reviseFile(m);
	}
}

void moveElement(List *&m){     //删除图书 
	cout<<"默认是根据书名来进行删除！"<<endl<<"您或许需要现预览一遍全部书籍名称？输入“1”预览或输入“0”直接进入删除：";
	long choice;
	while (!(cin >>choice))
		{
			cin.clear();
			while (cin.get() != '\n')
			{
				continue;
			}//跳过错误输入
			cout << "请输入一个数字："<<endl;
		}
	List *r = m->next;
	List *pre=m;
	
	if(choice==999999){
		cout<<"退出成功！"<<endl;
		return ;
	}
	
	if(choice==1){
		int i=0;
		while(r!=NULL){
			if(i%5==0){
				cout<<endl;
			}
			cout<<r->book->name<<" ";
			i++;
			r=r->next;
		}
	}
	string str;
	cout<<endl<<"请输入你想删除的书的书名（区分大小写）：";
	cin>>str;
	
	if(str=="999999"){
		cout<<"退出成功！"<<endl;
		return ;
	}
	
	pre=m;
	r=m->next;
	while(r!=NULL){
		if(r->book->name==str){
			pre->next=r->next;
			delete r;
			break;
		}
		pre=r;
		r=pre->next;
	}
	cout<<"-----删除成功！-----"<<endl;
	reviseFile(m);
}

void clearRecord(List *&m){    //清除图书借阅记录 
	cout<<"您确定清除所有借阅记录吗？此项操作不可恢复！  输入“1”确认，输入“0”退出："<<endl;
	int choice;
	while (!(cin >>choice)){
		cin.clear();
		while (cin.get() != '\n'){
			continue;
		}//跳过错误输入
		cout << "请输入一个数字："<<endl;
	}
	if(choice==1){
		List *r = m->next;
		while(r!=NULL){
			r->book->record.clear();
			r=r->next;
		}
		reviseFile(m);
		cout<<"-----清除完毕！-----"<<endl;
		return ;
	}
	else{
		cout<<"-----退出成功！！------"<<endl;
		return ;
	}
}

void dispReader(LendList *&m){    //展示读者文件信息 
	if(m==NULL){
		cout<<"无数据！输出失败！！"<<endl;
		return ;
	}
	LendList *r = m->next;
	cout<<endl<<"--------借阅者信息如下：----------"<<endl;
	while(r!=NULL){
		vector<LendBook>v;
		LendBook lendbook;
		v = r->v;
		cout<<"学号为"<<r->stuNum<<"的同学的借阅记录如下："<<endl;
		int i=0;
		for (vector<LendBook>::iterator it = v.begin(); it != v.end(); it++) {
			lendbook = *it;
			cout<<"   于"<<lendbook.time<<"借阅《"<<lendbook.name<<"》一书"<<endl; 
		}
		r=r->next;
		cout<<endl;
	}
	cout<<"----------借阅者信息输出完毕！！----------"<<endl;
}


//借阅者模块
LendList * LendDataToList(){   //将读者的借阅信息转换为链表 
	LendList *allList = new LendList;
	allList->next = NULL;
	LendList *r = allList;
	ifstream myfile;
	myfile.open("ReaderDate.txt",ios::in);
	string temp;
	if(!myfile.is_open()){
		cout<<"文件打开失败！"<<endl;
		return NULL;
	}
	//先判断一下文件是否为空
	ifstream judge;
	judge.open("ReaderDate.txt",ios::in);
	char ch;
	judge>>ch;
	if(judge.eof()){
		return allList;
	}
	//判断完毕 
	while(getline(myfile,temp)){
		LendList *list = new LendList;
		vector<LendBook> v;
		list->next =NULL;
		string s;
		stringstream is(temp);
		int i=0;
		LendBook lendbook;
		while(is>>s){
			if(i==0){
				list->stuNum = s;
			}
			else{
				lendbook.time = s.substr(0,19);
				lendbook.name = s.substr(19,s.length());
				v.push_back(lendbook);
			}
			i++;
		}
		list->v=v;
		r->next = list;
		list->next = NULL;
		r = list;
	}
	myfile.close();
	return allList;
}


void reviceReaderDate(LendList *&m){     //修改读者文件信息 
	if(m==NULL){
		cout<<"存储失败！！"<<endl;
		return ;
	}
	ofstream myfile;
	myfile.open("ReaderDate.txt",ios::out);
	LendList *r = m->next;
	while(r!=NULL){
		ostringstream oss;
		oss<<r->stuNum<<" ";
		vector<LendBook>v;
		v = r->v;
		LendBook lendbook;
		for (vector<LendBook>::iterator it = v.begin(); it != v.end(); it++) {
			lendbook = *it;
			oss<<lendbook.time<<lendbook.name<<" ";
		}
		oss<<"\n";
		myfile<<oss.str();
		r=r->next;
	}
}

void Lend(List *&m,LendList *&s,string stuNum){    //读者借书 
	cout<<"-----您正在借书界面-----"<<endl<<"随时输入“999999”即可退出借书界面"<<endl<<"您可能需要先预览书籍？输入“1”预览，输入“0”直接进入借书界面：";
	int choice;
	while (!(cin >>choice)){
		cin.clear();
		while (cin.get() != '\n'){
			continue;
		}//跳过错误输入
		cout << "请输入一个数字："<<endl;
	}
	if(choice==999999){
		cout<<"退出成功！"<<endl;
		return ;
	}
	if(choice==1){
		List *r = m->next;
		while(r!=NULL){
			cout<<r->book->name<<"  现存量为："<<r->book->nowStock<<endl;
			r=r->next;
		}
		cout<<endl;
	}
	cout<<"请输入你想借的书的书名："<<endl;
	string str;
	cin>>str;
	
	if(str=="999999"){
		cout<<"退出成功！！!"<<endl;
		return ;
	}
	
	List *r = m->next;
	while(r!=NULL){
		if(r->book->name==str){
			break;
		}
		r=r->next;
	}
	if(r==NULL){
		cout<<"你想借出的书籍不存在，此项即将退出，试一试重新输入。"<<endl;
		return ;
	}
	if(r->book->nowStock<=0){
		cout<<"很遗憾！您想借出的书籍目前暂时没有库存了，请过几天再来试试看吧。"<<endl<<"或许你还想借另外的书籍，输入“1”即可继续借书，输入0退出此项："<<endl;
		while (!(cin >>choice)){
			cin.clear();
			while (cin.get() != '\n'){
				continue;
			}//跳过错误输入
			cout << "请输入一个数字："<<endl;
		}
		if(choice==1){
			Lend(m,s,stuNum);
		}
		else{
			cout<<"    退出借书界面成功！！"<<endl; 
		}
	}
	else{
		cout<<"一次最多借一本书！"<<endl<<"输入“1”确认借出，输入“0”退出借书功能："<<endl;
		while (!(cin >>choice)){
			cin.clear();
			while (cin.get() != '\n'){
				continue;
			}//跳过错误输入
			cout << "请输入一个数字："<<endl;
		}
		string time = timeNow();  //现在时间 
		ostringstream oss;
		oss<<" 于"<<time<<"被学号为"<<stuNum<<"的同学借走 ";
		string record01 =oss.str();
		
		if(choice==1){
			r->book->nowStock--;
			r->book->isLend=true;
			r->book->record.push_back(record01);
		}
		else{
			return ;
		}
		cout<<"借出成功！借书最大归还时限为一个月，记得及时归还哦。"<<endl;
		reviseFile(m);
		LendList *pp = new LendList;
		//先遍历，查找该学号学生是否有过借书记录
		LendList *rr = s->next;
		LendBook lendbook;
		while(rr!=NULL){
			if(rr->stuNum==stuNum){
				break;
			}
			rr=rr->next;
		}
		lendbook.name = r->book->name;
		lendbook.time = time;
		if(rr!=NULL){
			rr->v.push_back(lendbook);
		}
		else{
			pp->stuNum = stuNum;
			vector<LendBook>vec;
			vec.push_back(lendbook);
			pp->v = vec;
			//遍历至最后一位插入
			rr = s->next;
			while(rr->next!=NULL){
				rr=rr->next;
			}
			rr->next = pp;
			pp->next = NULL;
		}
		reviceReaderDate(s);
	}
}


void Back(List *&m1,LendList *&m2,string stuNum){   //读者还书 
	cout<<"-----您现在在还书界面-----"<<endl<<"任何时候输入“999999”即可退出本界面    "<<endl;
	long stuNumLong;
	LendList *r = m2->next;
	while(r!=NULL){
		if(r->stuNum==stuNum){
			break;
		}
		r=r->next;
	}
	if(r==NULL||r->v.size()==0){
		cout<<"您没有需要归还的书籍！或许你想在此借书？输入”1“可以进入借书界面，输入”0“此项即将退出。"<<endl;
		int choice;
		while (!(cin >>choice)){
			cin.clear();
			while (cin.get() != '\n'){
				continue;
			}//跳过错误输入
			cout << "请输入一个数字："<<endl;
		}
		if(choice==1){
			Lend(m1,m2,stuNum);
		}
		else{
			cout<<"------退出成功！------"<<endl;
			return ;
		}
	}
	else{
		cout<<"您需要归还的书籍如下："<<endl;
		vector<LendBook>v=r->v;
		LendBook lendbook;
		for (vector<LendBook>::iterator it = v.begin(); it != v.end(); it++) {
			lendbook = *it;
			cout<<lendbook.name<<" ";
		}
		bool exit;
		string name;
		isEqual(r,exit,name);
		if(exit){
			return ;
		}
//		cout<<name;
//		return ;   //这里输入的name是正确的 
		vector<LendBook>v1 = r->v;
		vector<LendBook>v2;
		LendBook book;
		for (vector<LendBook>::iterator it = v.begin(); it != v.end(); it++) {
			book = *it;
			if(book.name!=name){
				v2.push_back(book);
			}
		}
		r->v = v2;
		List *r2 = m1->next;
		while(r2!=NULL){
			if(r2->book->name==name){
				r2->book->nowStock++;
				if(r2->book->nowStock>r2->book->allStock){
					r2->book->allStock=r2->book->nowStock;
				}
				ostringstream oss;
				string time = timeNow();
				oss<<" 于"<<time<<"被学号为"<<stuNum<<"的同学归还 ";
				r2->book->record.push_back(oss.str());
				break;
			}
			r2=r2->next;
		}
		reviseFile(m1);
		reviceReaderDate(m2);
		cout<<"------还书成功！------"<<endl;
		return ;
	}
}
 
bool isEqual(LendList *&r,bool &exit,string &name){   //还书函数的辅助函数（判断读者输入的书名是否存在 
	bool pass = false;
	vector<LendBook>v= r->v;
	cout<<endl<<"输入您想归还的书籍的名称：";
	cin>>name;
	
	if(name=="999999"){
		cout<<"退出借书页面成功！";
		exit = true;
		return true;
	}
	
	LendBook lendbook;
	for (vector<LendBook>::iterator it = v.begin(); it != v.end(); it++) {
		lendbook = *it;
		if(lendbook.name == name){
			pass = true;
			break;
		}
	}
	if(pass){
		return true;
	}
	else{
		cout<<"您输入的书名好像不存在哦，试一试重新输入"<<endl; 
		isEqual(r,exit,name);
	}
}

//初始界面模块
void inputPassword(string &str, int size) {   //在登录界面输入密码且让密码不可见 
    char c;
    int count = 0;
    char *password = new char[size]; // 动态申请空间
    while ((c = getch()) != '\r') {
 
        if (c == 8) { // 退格
            if (count == 0) {
                continue;
            }
            putchar('\b'); // 回退一格
            putchar(' '); // 输出一个空格将原来的*隐藏
            putchar('\b'); // 再回退一格等待输入
            count--;
        }
        if (count == size - 1) { // 最大长度为size-1
            continue;
        }
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {  // 密码只可包含数字和字母
            putchar('*');  // 接收到一个字符后, 打印一个*
            password[count] = c;
            count++;
        }
    }
    password[count] = '\0';
    str = password;
    delete[] password; // 释放空间
    cout << endl;
}

void inputInfo(){    //管理员登录界面 
	cout<<"请输入用户名："<<endl;
	string name;
	cin>>name;
	
	if(name=="999999"){
		cout<<"退出成功！" <<endl;
		return ;
	}
	
	cout<<"请输入登录密码：（最大不超过6位数）"<<endl;
	string password;
	inputPassword(password,7);
	
	if(password=="999999"){
		cout<<"退出成功！"<<endl; 
		return ;
	}
	
	ifstream myfile;
	myfile.open("ManagerDate.txt",ios::in);
	string temp;
	bool passOK=false;
	bool nameOK=false;
	while(getline(myfile,temp)){
		passOK = false;
		nameOK = false;
		string s;
    	stringstream is(temp);
    	int i=0;
    	while (is >> s){
    		string str = s;
    		if(i==1){
    			if(password==str){
    				passOK=true;
				}
    			break;
			}
			else if(i==0){
				if(name==str){
					nameOK=true;
				}
			}
			i++;
    	}
    	if(passOK&&nameOK){
    		cout<<"登录成功！"<<endl<<"请选择操作吧！"<<endl;
			return ;
		}
	}
	myfile.close();
	if(!(passOK&&nameOK)){
		cout<<"密码或用户名输入错误！请尝试重新输入："<<endl;
		inputInfo();
	}
}

void inputNum(bool &ok,string &stuNum){  //学生登录界面 
	cout<<"请输入您的学号："<<endl;
	long stuNumLong;
	while (!(cin >>stuNumLong)){
		cin.clear();
		while (cin.get() != '\n'){
				continue;
		}//跳过错误输入
		cout << "请输入一个数字："<<endl;
	}
	
	if(stuNumLong==999999){
		cout<<"退出成功！！"<<endl;
		ok = false;
		return ;
	}
	stringstream sstr;
	sstr<<stuNumLong;
	sstr>>stuNum;
	string regex[] = {"2021","2020","2019","2018"};
	if(stuNum.length()>8){
		cout<<"学号最长为8位数！"<<endl;
		inputNum(ok,stuNum); 
	}
	bool is=false;
	string sub = stuNum.substr(0,4);
//	cout<<sub;
	for(int i=0;i<4;i++){
		if(sub==regex[i]){
			is=true;
			break;
		}
	}
	if(!is){
		cout<<"不存在该学号！！"<<endl;
		inputNum(ok,stuNum);
	}
	if(is){
		ok = true;
		return ;
	}
}