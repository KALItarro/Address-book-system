// 2024/9/12    21:46:55
//我不知道你下次再拉下来这个代码是，技术什么样子了，过的怎么样了，拉一次向上面一样，写一次时间吧
#include <iostream>
using namespace std;
#include <string>
#define MAX 1000

struct contact 
{
	string name;
	string gender;
	int age;
	string phone;
	string address;
	int size ;
};
void home()
{
	cout <<
		" ***************************\n"
		" *****      TARRO      *****\n"
		" ***************************\n"
		" *****  1、添加联系人  *****\n"
		" *****  2、显示联系人  *****\n"
		" *****  3、删除联系人  *****\n"
		" *****  4、查找联系人  *****\n"
		" *****  5、修改联系人  *****\n"
		" *****  6、清空联系人  *****\n"
		" *****  0、退出通讯录  *****\n"
		" ***************************"
		<< endl;
}
void add_contact(contact *contact,int * len)
{
	int select;
	cout << "请输入姓名：" << endl;
	cin >> contact[*len].name;
	again:
	cout << "请输入性别\n"
		"1 -- 男\n"
		"2 -- 女" << endl;
	cin >> select;
	if (select == 1)
	{
		contact[*len].gender = { "男" };
	}
	else if (select == 2)
	{	
		contact[*len].gender = { "女" };
	}
	else
	{
		cout << "输入有误" << endl;
		goto again;
	}
	cout << "请输入年龄：" << endl;
	cin >> contact[*len].age;
	cout << "请输入联系电话：" << endl;
	cin >> contact[*len].phone;
	cout << "请输入家庭住址：" << endl;
	cin >> contact[*len].address;
	contact[*len].size++;
	cout << "添加成功" << endl;
}
void display_contact(contact * contact, int  * len)
{
	if (*len == -1)
	{
		(*len) = 0;
	}
	if (*len == 0)
	{
	
		cout << "当前记录为空" << endl;

	}
	else
	{
		for (int i = 0; i < *len; i++)
		{
			cout << "姓名：" << contact[i].name <<
				"\t性别：" << contact[i].gender <<
				"\t年龄：" << contact[i].age <<
				"\t电话：" << contact[i].phone <<
				"\t住址：" << contact[i].address << endl;
		}
	}	
}
void del_contact(contact * contact, int * len)
{
	int retun_value = 0;
	int deliver;
	string select_name;
	cout << "请输入您要删除的联系人：" << endl;
	cin >> select_name;
	for (int i = 0; i <= *len + 1; i++)  
	{
		if (contact[i].name == select_name)
		{
			retun_value = 1;
			deliver = i;
			break;
		}
		else
		{
			retun_value = 0;
		}
	}
	if (retun_value == 1)
	{
		if ((*len) == 1)
		{
			(*len) = 0;
		}
		else
		{
			for (int i = deliver + 1 ; i <= *len + 1   ; i++) //2    4
			{
				//cout << i << "--" << *len << endl;
				/*int temp = i;*/
				contact[i - 1] = contact[i];
				//cout << "当前人数" << *len << endl;
			}
		}
		(*len) --;
		cout << "删除成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
}
void select_comtact(contact* contact, int* len)
{
	string select_name;
	int select =0;
	int select_name_addr = 0;
	cout << "请输入要查找的联系人：" << endl;
	cin >> select_name;
	for (int i = 0; i < *len; i++)//
	{
		if (select_name == contact[i].name)
		{
			select = 1;
			select_name_addr = i;
			break;
		}
		else
		{
			select = 0;
		}
	}
	if (select == 1)
	{
		cout << "姓名：" << contact[select_name_addr].name <<
			"\t性别：" << contact[select_name_addr].gender <<
			"\t年龄：" << contact[select_name_addr].age <<
			"\t电话：" << contact[select_name_addr].phone <<
			"\t住址：" << contact[select_name_addr].address << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
}
void update_comtact(contact* contact, int* len)
{
	string select_name;
	int addr = 0 ;
	cout << "请输入您要修改的联系人" << endl;
	cin >> select_name;
	int select = 0;
	int temp = 0;
	for (int i = 0; i < *len; i++)
	{
		if (select_name == contact[i].name)
		{
			select = 1;
			int addr = i;
			break;
		}
		else
		{
			select = 0;
		}	
	}
	if (select == 0)
	{
		cout << "查无此人" << endl;
	}
	else
	{
		int select_age;
		cout << "请输入姓名：" << endl;
		cin >> contact[addr].name;
	again:
		cout << "请输入性别\n"
			"1 -- 男\n"
			"2 -- 女" << endl;
		cin >> select_age;
		if (select_age == 1)
		{
			contact[addr].gender = { "男" };
		}
		else if (select_age == 2)
		{
			contact[addr].gender = { "女" };
		}
		else
		{
			cout << "输入有误" << endl;
			goto again;
		}
		cout << "请输入年龄：" << endl;
		cin >> contact[addr].age;
		cout << "请输入联系电话：" << endl;
		cin >> contact[addr].phone;
		cout << "请输入家庭住址：" << endl;
		cin >> contact[addr].address;

	}
}
int main()
{
	struct contact contact[MAX];
	contact[0].size = 0;
	int select  ;
	int len = 0;
	while (true)
	{
		home();
		cin >> select;
		switch (select)
		{
		case 1:
			add_contact(&contact[0], &len);
			len ++ ;
			break;
		case 2:
			display_contact(&contact[0], &len);
			break;
		case 3:
			del_contact(&contact[0], &len);
			break;
		case 4:
			select_comtact(&contact[0], &len);
			break;
		case 5:
			update_comtact(&contact[0], &len);
			break;
		case 6:
			char select_del;
			cout << "你真的要清空数据吗？[y/n]" << endl;
			cin >> select_del;
			if (select_del == 'y')
			{
				len = 0;
				cout << "通讯录已清空" << endl;
			}
			else
			{
				cout << "停止删除" << endl;
			}
			break;
		case 0:
			cout << "欢迎下次使用" << endl;
			goto exit;
			break;
			

		default:
			cout << "请输入正确数值" << endl;
			break;
		}
		
		
		 system("pause");
		 system("cls");
	}
	exit:
	system("pause");
	return 0;
}
