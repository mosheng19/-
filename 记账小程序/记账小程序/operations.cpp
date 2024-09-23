#include"account_item.h"
#include"common.h"

//��ȡ�ļ��е���Ŀ����
void loadDataFromFile(vector<AccountItem>& items)
{
	ifstream input(FILENAME);


	//���ж�ȡÿһ����Ŀ��Ȼ���װ��accountitem
	AccountItem item;

	while (input >> item.itemType >> item.amount >> item.detail)
	{
		items.push_back(item);

	}

	input.close();
}

//----------------------����------------------------
//���˲���

void accounting(vector<AccountItem>& items)
{

	//��ʾ���˵�
	showMainMenu();


	//��ȡ�������룬�����Ϸ���У��
	char key = readMenuSelection(3);

	switch (key)
	{
	case	'1'://1-����
		income(items);

		break;

	case	'2'://2-֧��
		

		expand(items);

		break;
	case	'3'://3-�������˵�
		break;

	default:
		break;
	}

}

//��¼����
void income(vector<AccountItem>& items)
{
	//�¹���һ��AccountItem����
	AccountItem item;

	//��������
	item.itemType = INCOME;

		//���û�����������������ͱ�ע��Ϣ
		cout << "\n���������";
	item.amount = readAmount();

	cout << "\n��ע��";
	getline(cin, item.detail);

	//��ӵ�vector��
	items.push_back(item);

	//д���ļ�������
	insertIntoFile(item);

	//��ʾ�ɹ���Ϣ
	cout << "\n-----------------���˳ɹ�--------------------\n" << endl;
	cout << "\n���س��������˵�...." << endl;

	string line;
	getline(cin, line);

}
//��¼֧��
void expand(vector<AccountItem>& items)
{
	//�¹���һ��AccountItem����
	AccountItem item;

	//֧������
	item.itemType = EXPAND;

	//���û�����������������ͱ�ע��Ϣ
	cout << "\n����֧����";
	item.amount = - readAmount();

	cout << "\n��ע��";
	getline(cin, item.detail);

	//��ӵ�vector��
	items.push_back(item);

	//д���ļ�������
	insertIntoFile(item);

	//��ʾ�ɹ���Ϣ
	cout << "\n-----------------���˳ɹ�--------------------\n" << endl;
	cout << "\n���س��������˵�...." << endl;

	string line;
	getline(cin, line);

}

//д����Ŀ�ļ�
void insertIntoFile(const AccountItem& item)
{
	//����ofstream����,��׷�ӷ�ʽд��
	ofstream output(FILENAME, ios::out | ios::app );

	output << item.itemType << "\t" << item.amount << "\t" << item.detail << endl;

	output.close();
}

//----------------------��ѯ------------------------

//��ѯ����
void query(const vector<AccountItem>& items)
{

	//��ȡ�������룬�����Ϸ���У��
	char key = readMenuSelection(4);

	switch (key)
	{
	case	'1'://1-��ѯ������Ŀ����ͳ��
		queryItems(items);

		break;

	case	'2'://2-��ѯ��������


		queryItems(items,INCOME);

		break;
		case	'3'://3-��ѯ����֧��
			queryItems(items, EXPAND);
			break;
		case	'4'://4-�˳���ѯ
			
			break;

	default:
		break;
	}
}

//��ѯ��Ŀ����
void queryItems(const vector<AccountItem>& items)
{
	cout << "-------------------��ѯ���------------------" << endl;
	cout << "\n����\t\t���\t\t��ע\n" << endl;


	//����������Ŀ
	int total = 0;
	for (auto item : items)
	{
		printItem(item);
		total += item.amount;
		
	}


	//�����Ϣ
	cout << "========================================\n" << endl;
	cout << "�����룺" << total << endl;
	cout << "\n���س��������˵�...." << endl;

	string line;
	getline(cin, line);
}
//��������
void queryItems(const vector<AccountItem>& items,const string itemType)
{
	cout << "-------------------��ѯ���------------------" << endl;
	cout << "\n����\t\t���\t\t��ע\n" << endl;


	//����������Ŀ
	int total = 0;
	for (auto item : items)
	{
		if (item.itemType != itemType)
			continue;
		
			printItem(item);
			total += item.amount;
		
	}


	//�����Ϣ
	cout << "========================================\n" << endl;
	cout << ((itemType==INCOME)?"�����룺":"��֧��") << total << endl;
	cout << "\n���س��������˵�...." << endl;

	string line;
	getline(cin, line);
}

//��ӡ�����Ŀ��Ϣ
void printItem(const AccountItem& item)
{
	cout<< item.itemType << "\t\t" << item.amount << "\t\t" << item.detail << endl;
}