#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
using namespace std;

char* fileName;

struct Item
{
	Item(int k, const char* ch, Item* n = NULL)
		:key(k), info(new char[strlen(ch) + 1]), next(n), length(strlen(ch) + 1)
	{
		strcpy(info, ch); //����������� ������� � ����������� � ���������
	}
	int key;//����
	char* info;//����������
	Item* next;//��������� ������� ������
	int length;//����� ����������
	int shift;//�������� � ����� (����)
};


//��������� ����������� �� ���� ������
bool Belong(Item*& list, int key)
{
	Item* temp(list);
	while (temp && temp->key != key)//���� ���� �������� � ������ � ���� �������� ������� �� ����� ����� ��� �� ����
		temp = temp->next;

	return (temp ? true : false);//���������� true ���� temp!=NULL, �� ���� ���� ������ � ������
}

//��������� � ������ �������
void Add(Item * &list, int key, const char* val)
{
	if (Belong(list, key))//��������� ��� �� � ��� �������� ��� � ����� ������
	{
		cerr << "Element with key = " << key << " already exist\n";
		return;
	}

	if (!list)//���� ������ ���� �� ������� � ������ ������ �������
		list = new Item(key, val, NULL);
	else//����� ����� ����� � ������� ����� ���� �������
	{
		Item* temp(list);
		while (temp->next)
			temp = temp->next;
		temp->next = new Item(key, val, NULL);
	}
}

//�������� �������� � �������� ������
bool Delete(Item * &list, int key)
{
	Item* temp(list);
	while (temp && temp->key != key)//���� ������� � ����� ������ ��� ��� ������
		temp = temp->next;

	if (temp)//���� ������� � ����� ������ ����������
	{
		//���� ������� ��� ����� ������� ��� ������ ������
		if (temp == list)
		{
			Item* toDel(list);
			list = list->next;
			delete toDel;
			return true;
		}
		//����� ������� ���-�� � �������� ��� � �����
		else
		{
			Item* toDel(temp);
			Item* newElem(list);

			//����� ������� ����� ��� ��� ��������� �������
			while (newElem->next != temp)
				newElem = newElem->next;
			//����� ��������� ������� �� ������
			newElem->next = temp->next;

			delete toDel;//������ �������
			return true;
		}
	}
	else//����� �������� ���. ���������� ������������ �� ������
	{
		cerr << "Can't delete element with key = " << key << endl;
		return false;
	}
}

//����� �������� �� �����
Item* Find(Item * &list, int key)
{
	Item* result;//���������. ���� ��������� �� � ����� ������������
	Item* temp(list);
	while (temp && temp->key != key)//���� ���������� ���� �� ����� ������� ���������� ����� (��� ���� �� �������� ������)
		temp = temp->next;

	if (temp)//���� ������ �� �������� - �� ����� ����, ��������� ���� ������� � ����� ��� ��� ��������
		return (result = new Item(temp->key, temp->info, NULL));

	else//����� ������ ���������� ������� ��� �� ����� ������ �������. �������� ������������ �� ������ � ����� ��������� �� NULL
		cerr << "Can't find element with key = " << key << endl;
	return (result = NULL);
}


//�������� ����� ������, ���������� ����� ����� ���� ���������� ������
void DeleteList(Item * &list)
{
	Item* toDel(list);
	while (list)//���� ���� ��� ������� - ������� ��������
	{
		list = list->next;
		delete toDel;
		toDel = list;
	}
}

//����� � ����� ������
ostream& operator<<(ostream & os, const Item * print)
{
	const Item* temp(print);
	if (!temp)//���� ��������� � ������ ��� (list = NULL) �� �� ����� ������ �������� ��������
		os << "List is empty.";
	else//����� ����������� ��������� ����� � �������������� ����� ���������
		while (temp)
			os << temp->key << " -> " << temp->info << '\n', temp = temp->next;
	return (os << endl);//����� ����� ������ ����� ������������ ��� ���� ��� ���-�� �������� (��������� ������ ��� cout<<list1<<list2<<list3)
}

void WriteList(Item * &list)
{
	FILE* file = fopen(fileName, "w");
	Item* temp = list;
	int Shift = 0;
	int* count = new int(0);
	while (temp)
		temp = temp->next, count++;

	Shift += sizeof(Item) * (*count);
	temp = list;
	while (temp)
	{
		temp->shift = Shift;
		Shift += temp->length;
		temp = temp->next;
	}
	temp = list;
	fwrite(count, 1, sizeof(int), file);

	while (temp)
	{
		fwrite(temp, 1, sizeof(Item), file);
		temp = temp->next;
	}
	temp = list;
	while (temp)
	{
		fwrite(temp->info, temp->length, sizeof(char), file);
		temp = temp->next;
	}
	fclose(file);
}

Item* ReadList()
{
	int* count = new int(-1);
	Item * lst = NULL;
	Item * temp = (Item*)malloc(sizeof(Item));
	FILE * file = fopen(fileName, "r");
	fread(count, 1, sizeof(int), file);
	for (int i = 0; i < (*count); i++)
	{
		fread(temp, 1, sizeof(Item), file);
		temp->info = new char[temp->length];
		fseek(file, temp->shift, SEEK_SET);
		fread(temp->info, temp->length, sizeof(char), file);

		Add(lst, temp->key, temp->info);

		fseek(file, sizeof(int) + (i + 1) * sizeof(Item), SEEK_SET);
	}
	return lst;
}





int main()
{
	fileName = new char[strlen("out.txt") + 1];
	strcpy(fileName, "out.txt");
	Item* lst = NULL;
	Add(lst, 2, "value2");
	Add(lst, 3, "zzzzzz4");
	//Add(lst,3,"value3");
	cout << lst;
	WriteList(lst);
	Item* lst2 = ReadList();
	cout << lst2;


}

/*
int main()
{
	int choice=1;//����� ������������. ���� ����������� ����� ���� ��� ������ ������������
	int key;//���� ������� ��� ������������ ��� ����������/��������/������
	char str[256];//������ ��� ���������� ��� ����� ������� ������������ ��� ����������/��������/������
	Item* forFind=NULL;//��������� ������. ���� ������ ������� ���
	Item* lst=NULL;//��� ������. ���� ��� �� ����

	while(choice)
	{
		system("cls");
		cout<<"Main Menu\n"
		"1 - Add new element\n"
		"2 - Find element\n"
		"3 - Delete element\n"
		"4 - Print list\n"
		"5 - Exit\n";
		cin>>choice;
		cout<<endl;
		if(cin.fail() || (choice<1 || choice>5))//�������� �� ��������� ����� ������������� ������ ����
		{
			cin.clear();//������� ��������� ������
			choice=1;
			continue;
		}
		else
		 switch (choice)
		 {
			case 1:
			cout<<"Enter key:\n";
			 cin>>key;
			if(cin.fail())
			{
				cin.clear();
				cout<<"Try again.\n";
				_flushall();//������� ������ �� ������ ��� �������� ������������
				break;
			}
			cin.ignore();
			cout<<"Enter info:\n";
			cin.getline(str,256);
			Add(lst,key,str);
			break;

			case 2:
			cout<<"Enter key:\n";
			cin>>key;
			if(cin.fail())
			{
				cin.clear();
				cout<<"Try again.\n";
				_flushall();
				break;
			}
			cin.ignore();
			forFind=Find(lst,key);
			if(forFind)
			 cout<<forFind;
			break;

			case 3:
			cout<<"Enter key:\n";
			cin>>key;
			if(cin.fail())
			{
				cin.clear();
				cout<<"Try again.\n";
				_flushall();
				break;
			}
			cin.ignore();
			if(Delete(lst,key))
			 cout<<"Done\n";
			break;

			case 4:
			cout<<lst;
			break;

			case 5:
			break;

			default:
			cout<<"Wrong selection.\n";
		 }
		 if(choice==5)
		  break;
		 cout<<"Press any key to continue...\n";
		 getch();
	}
	DeleteList(lst);
	return 0;
}
*/
