// 2024/9/12    21:46:55
//�Ҳ�֪�����´�����������������ǣ�����ʲô�����ˣ�������ô���ˣ���һ��������һ����дһ��ʱ���
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
		" *****  1�������ϵ��  *****\n"
		" *****  2����ʾ��ϵ��  *****\n"
		" *****  3��ɾ����ϵ��  *****\n"
		" *****  4��������ϵ��  *****\n"
		" *****  5���޸���ϵ��  *****\n"
		" *****  6�������ϵ��  *****\n"
		" *****  0���˳�ͨѶ¼  *****\n"
		" ***************************"
		<< endl;
}
void add_contact(contact *contact,int * len)
{
	int select;
	cout << "������������" << endl;
	cin >> contact[*len].name;
	again:
	cout << "�������Ա�\n"
		"1 -- ��\n"
		"2 -- Ů" << endl;
	cin >> select;
	if (select == 1)
	{
		contact[*len].gender = { "��" };
	}
	else if (select == 2)
	{	
		contact[*len].gender = { "Ů" };
	}
	else
	{
		cout << "��������" << endl;
		goto again;
	}
	cout << "���������䣺" << endl;
	cin >> contact[*len].age;
	cout << "��������ϵ�绰��" << endl;
	cin >> contact[*len].phone;
	cout << "�������ͥסַ��" << endl;
	cin >> contact[*len].address;
	contact[*len].size++;
	cout << "��ӳɹ�" << endl;
}
void display_contact(contact * contact, int  * len)
{
	if (*len == -1)
	{
		(*len) = 0;
	}
	if (*len == 0)
	{
	
		cout << "��ǰ��¼Ϊ��" << endl;

	}
	else
	{
		for (int i = 0; i < *len; i++)
		{
			cout << "������" << contact[i].name <<
				"\t�Ա�" << contact[i].gender <<
				"\t���䣺" << contact[i].age <<
				"\t�绰��" << contact[i].phone <<
				"\tסַ��" << contact[i].address << endl;
		}
	}	
}
void del_contact(contact * contact, int * len)
{
	int retun_value = 0;
	int deliver;
	string select_name;
	cout << "��������Ҫɾ������ϵ�ˣ�" << endl;
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
				//cout << "��ǰ����" << *len << endl;
			}
		}
		(*len) --;
		cout << "ɾ���ɹ�" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
}
void select_comtact(contact* contact, int* len)
{
	string select_name;
	int select =0;
	int select_name_addr = 0;
	cout << "������Ҫ���ҵ���ϵ�ˣ�" << endl;
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
		cout << "������" << contact[select_name_addr].name <<
			"\t�Ա�" << contact[select_name_addr].gender <<
			"\t���䣺" << contact[select_name_addr].age <<
			"\t�绰��" << contact[select_name_addr].phone <<
			"\tסַ��" << contact[select_name_addr].address << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
}
void update_comtact(contact* contact, int* len)
{
	string select_name;
	int addr = 0 ;
	cout << "��������Ҫ�޸ĵ���ϵ��" << endl;
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
		cout << "���޴���" << endl;
	}
	else
	{
		int select_age;
		cout << "������������" << endl;
		cin >> contact[addr].name;
	again:
		cout << "�������Ա�\n"
			"1 -- ��\n"
			"2 -- Ů" << endl;
		cin >> select_age;
		if (select_age == 1)
		{
			contact[addr].gender = { "��" };
		}
		else if (select_age == 2)
		{
			contact[addr].gender = { "Ů" };
		}
		else
		{
			cout << "��������" << endl;
			goto again;
		}
		cout << "���������䣺" << endl;
		cin >> contact[addr].age;
		cout << "��������ϵ�绰��" << endl;
		cin >> contact[addr].phone;
		cout << "�������ͥסַ��" << endl;
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
			cout << "�����Ҫ���������[y/n]" << endl;
			cin >> select_del;
			if (select_del == 'y')
			{
				len = 0;
				cout << "ͨѶ¼�����" << endl;
			}
			else
			{
				cout << "ֹͣɾ��" << endl;
			}
			break;
		case 0:
			cout << "��ӭ�´�ʹ��" << endl;
			goto exit;
			break;
			

		default:
			cout << "��������ȷ��ֵ" << endl;
			break;
		}
		
		
		 system("pause");
		 system("cls");
	}
	exit:
	system("pause");
	return 0;
}
