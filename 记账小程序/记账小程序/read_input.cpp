#include "common.h"


//读取菜单输入，进行合法校验
char readMenuSelection(int options)
{
	string str;
			while (true)
			{
				getline(cin, str);//读取键盘输入

				//进行合法性校验

				if (str.size() != 1 || str[0] - '0' <= 0 || str[0] - '0' > options)	
					cout << "输入错误，请重新选择：";
				else
					break;
			}

			//输入合法
			return str[0];
}

//读取确认信息，进行合法性确认

char readQuitConfirm()
{
	string str;

	while (true)
	{
		getline(cin, str);//读取键盘输入

		//进行合法性校验

		if (str.size() != 1 || toupper (str[0]) !='Y'&&  str[0]!= 'N')
			cout << "输入错误，请重新选择(Y/N):";
		else
			break;
	}

	//输入合法
	return str[0];
}

//读取键盘收入金额，并作合法校验

int readAmount()
{
	int amount;
	string str;

	while (true)
	{
		getline(cin, str);//读取键盘输入

		//进行合法性校验
		try
		{
			amount = stoi(str);

			break;
		}
		catch (invalid_argument e)
		{
			cout<< "输入错误，请正确收入数字：";
		}
	}

	//输入合法
	return amount;
}