#include <iostream>
#include <conio.h>
#include <string.h>

using namespace std;

//Объявление структуры
struct MyStruct
{
	int firstField;
	char secondField[11];
};

//Объявление анонимной структуры
struct
{
	int firstAnonimParam;
	double secondAnonimParam;
} firstAnonimVar, secondAnonimVar;

//Структура с конструктором
struct strWithConstr
{
	int firstField;
	strWithConstr(int f)
	{
		firstField = f;
	}
	strWithConstr()
	{
		firstField = 0;
	}
};

//Структура с указателем на саму себя
struct strWithPointer
{
	int data;
	strWithPointer* next;
};

//Структура в структуре
struct strWithStr
{
	int data;
	strWithPointer someOtherData;
};

//демонстрация структуры как класса с открытыми членами
struct strAsClass
{
	int data; //по-умолчанию - открытый член
private:
	int secretData; //закрытый член
public:
	int publicData; //явно-открытый член

	//функция-член внутри структуры
	int someFunction()
	{
		return data;
	}
};


int main()
{
	//Объявление переменной типа структура
	MyStruct m;
	//Доступ к полям структуры
	m.firstField=2;
	strcpy_s(m.secondField, "abc");

	//Инициализация одним выражением
	MyStruct m1 = { 2,"def" };
	cout << m1.firstField << " " << m1.secondField << endl << endl;

	//Присвоение элементов типа структура
	MyStruct newM = m;
	cout << m.firstField << " " << m.secondField << endl << newM.firstField << " " << newM.secondField << endl << endl;
	m.secondField[0] = 'A';
	cout << m.firstField << " " << m.secondField << endl << newM.firstField << " " << newM.secondField << endl << endl;

	//Инициализация структуры с конструктором
	strWithConstr v1, v2(3);
	cout << "v1: " << v1.firstField << endl << "v2: " << v2.firstField << endl<<endl;

	//Вызов функции-члена из переменной типа структура
	strAsClass sClass;
	sClass.data = -4;
	cout << "sClass.someFunction: " << sClass.someFunction() << endl << endl;

	_getch();
	return 0;
}