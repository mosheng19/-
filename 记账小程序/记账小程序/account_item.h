#pragma once
#include "common.h"

//定义结构体

struct  AccountItem
{
	string itemType;
	int amount;
	string detail;

};

//针对账目数据进行操作的函数

//加载账目数据
void loadDataFromFile	(vector<AccountItem>& items);

//记账
void accounting(vector<AccountItem>& items);
void insertIntoFile(const AccountItem& item);
void expand(vector<AccountItem>& items);
void income(vector<AccountItem>& items);

//查询
void query(const vector<AccountItem>& items);
void queryItems(const vector<AccountItem>& items);
void printItem(const AccountItem& item);
void queryItems(const vector<AccountItem>& items, const string itemType);