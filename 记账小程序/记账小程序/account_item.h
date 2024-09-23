#pragma once
#include "common.h"

//����ṹ��

struct  AccountItem
{
	string itemType;
	int amount;
	string detail;

};

//�����Ŀ���ݽ��в����ĺ���

//������Ŀ����
void loadDataFromFile	(vector<AccountItem>& items);

//����
void accounting(vector<AccountItem>& items);
void insertIntoFile(const AccountItem& item);
void expand(vector<AccountItem>& items);
void income(vector<AccountItem>& items);

//��ѯ
void query(const vector<AccountItem>& items);
void queryItems(const vector<AccountItem>& items);
void printItem(const AccountItem& item);
void queryItems(const vector<AccountItem>& items, const string itemType);