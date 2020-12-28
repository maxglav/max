#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <iostream>
#include <string.h>
typedef struct Data
{
	char fam[20];
	char name[20];
	char otch[20];
	char adress[20];
	char medkart[10];
	char strah[10];
};
int menu();
void poisk(FILE* F1, int& n, Data* arr)
{
	errno_t err;
	err = fopen_s(&F1, "f1.txt", "r+b");
	char str[20];
	printf("������� ������� ��� ������\n");
	scanf_s("%s", str, 20);
	int k;
	for (int i = 0; i < n; i++)
	{
		k = strncmp(arr[i].fam, str, 1);
		if (k == 0)
		{
			printf("������� %d\n", i + 1);
			printf("%s\n", arr[i].fam);
			printf(" ��� %d\n", i + 1);
			printf("%s\n", arr[i].name);
			printf("�������� %d\n", i + 1);
			printf("%s\n", arr[i].otch);
			printf("����� %d\n", i + 1);
			printf("%s\n", arr[i].adress);
			printf("����� �������� %d\n", i + 1);
			printf("%s\n", arr[i].medkart);
			printf("����� ���������� ������ %d\n", i + 1);
			printf("%s\n", arr[i].strah);
		}

	}
	if (k != 0)
	{
		printf("��� ������ ��������\n");
	}

	fclose(F1);
}
void print(FILE * F1, int& n, Data * arr, int& s)
{
	errno_t err;
	err = fopen_s(&F1, "f1.txt", "r+b");
	for (int i = 0; i < n + s; i++)
	{
		printf("������� %d\n", i + 1);
		printf("%s\n", arr[i].fam);
		printf(" ��� %d\n", i + 1);
		printf("%s\n", arr[i].name);
		printf("�������� %d\n", i + 1);
		printf("%s\n", arr[i].otch);
		printf("����� %d\n", i + 1);
		printf("%s\n", arr[i].adress);
		printf("����� �������� %d\n", i + 1);
		printf("%s\n", arr[i].medkart);
		printf("����� ���������� ������ %d\n\n", i + 1);
		printf("%s\n", arr[i].strah);

	}
	fclose(F1);

}
void dop(FILE * F1, int& s)
{
	errno_t err;
	//int s;
	printf("������� ���������� ����������\n");
	scanf_s("%d", &s);
	Data* arr1 = (Data*)malloc(s * sizeof(Data));

	printf("��������\n");
	err = fopen_s(&F1, "f1.txt", "a+b");
	for (int i = 0; i < s; i++)
	{
		fflush(stdin);
		printf("������� ������� %d\n", i + 1);
		gets_s(arr1[i].fam);
		fputs(arr1[i].fam, F1);
		fputs("\n", F1);
		printf("������� ��� %d\n", i + 1);
		gets_s(arr1[i].name);
		fputs(arr1[i].name, F1);
		fputs("\n", F1);
		printf("������� ��������\n");
		gets_s(arr1[i].otch);
		fputs(arr1[i].otch, F1);
		fputs("\n", F1);
		printf("������� ������\n");
		gets_s(arr1[i].adress);
		fputs(arr1[i].adress, F1);
		fputs("\n", F1);
		printf("������� ����� ��������\n");
		gets_s(arr1[i].medkart);
		fputs(arr1[i].medkart, F1);
		fputs("\n", F1);
		printf("������� ����� ���������� ������\n");
		gets_s(arr1[i].strah);
		fputs(arr1[i].strah, F1);
		fputs("\n", F1);
	}
	fclose(F1);
}

int main(void)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	FILE* F1;
	errno_t err;
	err = fopen_s(&F1, "f1.txt", "w+b");
	if (!F1)
	{
		printf("������ ��������\n");
	}
	int n;
	printf("������� ���������� �������\n");
	scanf_s("%d", &n);
	Data* arr = (Data*)malloc(n * sizeof(Data));
	for (int i = 0; i < n; i++)
	{
		fflush(stdin);
		printf("������� ������� %d\n", i + 1);
		gets_s(arr[i].fam);
		fputs(arr[i].fam, F1);
		fputs("\n", F1);
		printf("������� ��� %d\n", i + 1);
		gets_s(arr[i].name);
		fputs(arr[i].name, F1);
		fputs("\n", F1);
		printf("������� ��������\n");
		gets_s(arr[i].otch);
		fputs(arr[i].otch, F1);
		fputs("\n", F1);
		printf("������� ������\n");
		gets_s(arr[i].adress);
		fputs(arr[i].adress, F1);
		fputs("\n", F1);
		printf("������� ����� ��������\n");
		gets_s(arr[i].medkart);
		fputs(arr[i].medkart, F1);
		fputs("\n", F1);
		printf("������� ����� ���������� ������\n");
		gets_s(arr[i].strah);
		fputs(arr[i].strah, F1);
		fputs("\n", F1);
	}
	fclose(F1);
	int s = 0;

	while (3)
		switch (menu())
		{

		case 1:
			print(F1, n, arr, s);
			break;
		case 2:
			dop(F1, s);
			break;
		case 3:
			poisk(F1, n, arr);
			break;
		case 4:
			return 0;
		}
}
int menu()
{
	int a;
	do
	{
		printf("����:\n");
		printf("1. ������\n");
		printf("2. ���������� ���������\n");
		printf("3. �����\n");
		printf("4. �����\n");
		printf("��� �����:\n");
		scanf_s("%d", &a);
	} while (a > 3);
	return a;

}
