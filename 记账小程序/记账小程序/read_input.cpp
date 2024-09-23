#include "common.h"


//��ȡ�˵����룬���кϷ�У��
char readMenuSelection(int options)
{
	string str;
			while (true)
			{
				getline(cin, str);//��ȡ��������

				//���кϷ���У��

				if (str.size() != 1 || str[0] - '0' <= 0 || str[0] - '0' > options)	
					cout << "�������������ѡ��";
				else
					break;
			}

			//����Ϸ�
			return str[0];
}

//��ȡȷ����Ϣ�����кϷ���ȷ��

char readQuitConfirm()
{
	string str;

	while (true)
	{
		getline(cin, str);//��ȡ��������

		//���кϷ���У��

		if (str.size() != 1 || toupper (str[0]) !='Y'&&  str[0]!= 'N')
			cout << "�������������ѡ��(Y/N):";
		else
			break;
	}

	//����Ϸ�
	return str[0];
}

//��ȡ��������������Ϸ�У��

int readAmount()
{
	int amount;
	string str;

	while (true)
	{
		getline(cin, str);//��ȡ��������

		//���кϷ���У��
		try
		{
			amount = stoi(str);

			break;
		}
		catch (invalid_argument e)
		{
			cout<< "�����������ȷ�������֣�";
		}
	}

	//����Ϸ�
	return amount;
}