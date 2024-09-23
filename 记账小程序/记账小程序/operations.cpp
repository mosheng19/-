#include"account_item.h"
#include"common.h"

//读取文件中的账目数据
void loadDataFromFile(vector<AccountItem>& items)
{
	ifstream input(FILENAME);


	//逐行读取每一条账目，然后包装成accountitem
	AccountItem item;

	while (input >> item.itemType >> item.amount >> item.detail)
	{
		items.push_back(item);

	}

	input.close();
}

//----------------------记账------------------------
//记账操作

void accounting(vector<AccountItem>& items)
{

	//显示主菜单
	showMainMenu();


	//读取键盘输入，并作合法性校验
	char key = readMenuSelection(3);

	switch (key)
	{
	case	'1'://1-输入
		income(items);

		break;

	case	'2'://2-支出
		

		expand(items);

		break;
	case	'3'://3-返回主菜单
		break;

	default:
		break;
	}

}

//记录收入
void income(vector<AccountItem>& items)
{
	//新构建一个AccountItem对象
	AccountItem item;

	//收入类型
	item.itemType = INCOME;

		//与用户交互，键盘收入金额和备注信息
		cout << "\n本次收入金额：";
	item.amount = readAmount();

	cout << "\n备注：";
	getline(cin, item.detail);

	//添加到vector中
	items.push_back(item);

	//写入文件并保存
	insertIntoFile(item);

	//显示成功信息
	cout << "\n-----------------记账成功--------------------\n" << endl;
	cout << "\n按回车返回主菜单...." << endl;

	string line;
	getline(cin, line);

}
//记录支出
void expand(vector<AccountItem>& items)
{
	//新构建一个AccountItem对象
	AccountItem item;

	//支出类型
	item.itemType = EXPAND;

	//与用户交互，键盘收入金额和备注信息
	cout << "\n本次支出金额：";
	item.amount = - readAmount();

	cout << "\n备注：";
	getline(cin, item.detail);

	//添加到vector中
	items.push_back(item);

	//写入文件并保存
	insertIntoFile(item);

	//显示成功信息
	cout << "\n-----------------记账成功--------------------\n" << endl;
	cout << "\n按回车返回主菜单...." << endl;

	string line;
	getline(cin, line);

}

//写入账目文件
void insertIntoFile(const AccountItem& item)
{
	//建立ofstream对象,以追加方式写入
	ofstream output(FILENAME, ios::out | ios::app );

	output << item.itemType << "\t" << item.amount << "\t" << item.detail << endl;

	output.close();
}

//----------------------查询------------------------

//查询操作
void query(const vector<AccountItem>& items)
{

	//读取键盘输入，并作合法性校验
	char key = readMenuSelection(4);

	switch (key)
	{
	case	'1'://1-查询所有账目，并统计
		queryItems(items);

		break;

	case	'2'://2-查询所有收入


		queryItems(items,INCOME);

		break;
		case	'3'://3-查询所有支出
			queryItems(items, EXPAND);
			break;
		case	'4'://4-退出查询
			
			break;

	default:
		break;
	}
}

//查询账目函数
void queryItems(const vector<AccountItem>& items)
{
	cout << "-------------------查询结果------------------" << endl;
	cout << "\n类型\t\t金额\t\t备注\n" << endl;


	//遍历所有账目
	int total = 0;
	for (auto item : items)
	{
		printItem(item);
		total += item.amount;
		
	}


	//输出信息
	cout << "========================================\n" << endl;
	cout << "总收入：" << total << endl;
	cout << "\n按回车返回主菜单...." << endl;

	string line;
	getline(cin, line);
}
//函数重载
void queryItems(const vector<AccountItem>& items,const string itemType)
{
	cout << "-------------------查询结果------------------" << endl;
	cout << "\n类型\t\t金额\t\t备注\n" << endl;


	//遍历所有账目
	int total = 0;
	for (auto item : items)
	{
		if (item.itemType != itemType)
			continue;
		
			printItem(item);
			total += item.amount;
		
	}


	//输出信息
	cout << "========================================\n" << endl;
	cout << ((itemType==INCOME)?"总收入：":"总支出") << total << endl;
	cout << "\n按回车返回主菜单...." << endl;

	string line;
	getline(cin, line);
}

//打印输出账目信息
void printItem(const AccountItem& item)
{
	cout<< item.itemType << "\t\t" << item.amount << "\t\t" << item.detail << endl;
}