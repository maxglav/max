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
	printf("Введите фамилию для поиска\n");
	scanf_s("%s", str, 20);
	int k;
	for (int i = 0; i < n; i++)
	{
		k = strncmp(arr[i].fam, str, 1);
		if (k == 0)
		{
			printf("Фамилия %d\n", i + 1);
			printf("%s\n", arr[i].fam);
			printf(" Имя %d\n", i + 1);
			printf("%s\n", arr[i].name);
			printf("Отчество %d\n", i + 1);
			printf("%s\n", arr[i].otch);
			printf("Адрес %d\n", i + 1);
			printf("%s\n", arr[i].adress);
			printf("Номер медкарты %d\n", i + 1);
			printf("%s\n", arr[i].medkart);
			printf("Номер страхового полюса %d\n", i + 1);
			printf("%s\n", arr[i].strah);
		}

	}
	if (k != 0)
	{
		printf("Нет такого пациента\n");
	}

	fclose(F1);
}
void print(FILE * F1, int& n, Data * arr, int& s)
{
	errno_t err;
	err = fopen_s(&F1, "f1.txt", "r+b");
	for (int i = 0; i < n + s; i++)
	{
		printf("Фамилия %d\n", i + 1);
		printf("%s\n", arr[i].fam);
		printf(" Имя %d\n", i + 1);
		printf("%s\n", arr[i].name);
		printf("Отчество %d\n", i + 1);
		printf("%s\n", arr[i].otch);
		printf("Адрес %d\n", i + 1);
		printf("%s\n", arr[i].adress);
		printf("Номер медкарты %d\n", i + 1);
		printf("%s\n", arr[i].medkart);
		printf("Номер страхового полюса %d\n\n", i + 1);
		printf("%s\n", arr[i].strah);

	}
	fclose(F1);

}
void dop(FILE * F1, int& s)
{
	errno_t err;
	//int s;
	printf("Введите количество добавлений\n");
	scanf_s("%d", &s);
	Data* arr1 = (Data*)malloc(s * sizeof(Data));

	printf("Добавить\n");
	err = fopen_s(&F1, "f1.txt", "a+b");
	for (int i = 0; i < s; i++)
	{
		fflush(stdin);
		printf("Введите фамилию %d\n", i + 1);
		gets_s(arr1[i].fam);
		fputs(arr1[i].fam, F1);
		fputs("\n", F1);
		printf("Введите имя %d\n", i + 1);
		gets_s(arr1[i].name);
		fputs(arr1[i].name, F1);
		fputs("\n", F1);
		printf("Введите отчество\n");
		gets_s(arr1[i].otch);
		fputs(arr1[i].otch, F1);
		fputs("\n", F1);
		printf("Введите адресс\n");
		gets_s(arr1[i].adress);
		fputs(arr1[i].adress, F1);
		fputs("\n", F1);
		printf("Введите номер медкарты\n");
		gets_s(arr1[i].medkart);
		fputs(arr1[i].medkart, F1);
		fputs("\n", F1);
		printf("Введите номер страхового полюса\n");
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
		printf("Ошибка открытия\n");
	}
	int n;
	printf("Введите количество человек\n");
	scanf_s("%d", &n);
	Data* arr = (Data*)malloc(n * sizeof(Data));
	for (int i = 0; i < n; i++)
	{
		fflush(stdin);
		printf("Введите фамилию %d\n", i + 1);
		gets_s(arr[i].fam);
		fputs(arr[i].fam, F1);
		fputs("\n", F1);
		printf("Введите имя %d\n", i + 1);
		gets_s(arr[i].name);
		fputs(arr[i].name, F1);
		fputs("\n", F1);
		printf("Введите отчество\n");
		gets_s(arr[i].otch);
		fputs(arr[i].otch, F1);
		fputs("\n", F1);
		printf("Введите адресс\n");
		gets_s(arr[i].adress);
		fputs(arr[i].adress, F1);
		fputs("\n", F1);
		printf("Введите номер медкарты\n");
		gets_s(arr[i].medkart);
		fputs(arr[i].medkart, F1);
		fputs("\n", F1);
		printf("Введите номер страхового полюса\n");
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
		printf("Меню:\n");
		printf("1. Печать\n");
		printf("2. Добавление элементов\n");
		printf("3. Поиск\n");
		printf("4. Выход\n");
		printf("Ваш выбор:\n");
		scanf_s("%d", &a);
	} while (a > 3);
	return a;

}
