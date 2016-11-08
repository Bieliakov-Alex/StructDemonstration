#include <iostream>
#include <conio.h>
#include <string.h>

using namespace std;

//���������� ���������
struct MyStruct
{
	int firstField;
	char secondField[11];
};

//���������� ��������� ���������
struct
{
	int firstAnonimParam;
	double secondAnonimParam;
} firstAnonimVar, secondAnonimVar;

//��������� � �������������
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

//��������� � ���������� �� ���� ����
struct strWithPointer
{
	int data;
	strWithPointer* next;
};

//��������� � ���������
struct strWithStr
{
	int data;
	strWithPointer someOtherData;
};

//������������ ��������� ��� ������ � ��������� �������
struct strAsClass
{
	int data; //��-��������� - �������� ����
private:
	int secretData; //�������� ����
public:
	int publicData; //����-�������� ����

	//�������-���� ������ ���������
	int someFunction()
	{
		return data;
	}
};


int main()
{
	//���������� ���������� ���� ���������
	MyStruct m;
	//������ � ����� ���������
	m.firstField=2;
	strcpy_s(m.secondField, "abc");

	//������������� ����� ����������
	MyStruct m1 = { 2,"def" };
	cout << m1.firstField << " " << m1.secondField << endl << endl;

	//���������� ��������� ���� ���������
	MyStruct newM = m;
	cout << m.firstField << " " << m.secondField << endl << newM.firstField << " " << newM.secondField << endl << endl;
	m.secondField[0] = 'A';
	cout << m.firstField << " " << m.secondField << endl << newM.firstField << " " << newM.secondField << endl << endl;

	//������������� ��������� � �������������
	strWithConstr v1, v2(3);
	cout << "v1: " << v1.firstField << endl << "v2: " << v2.firstField << endl<<endl;

	//����� �������-����� �� ���������� ���� ���������
	strAsClass sClass;
	sClass.data = -4;
	cout << "sClass.someFunction: " << sClass.someFunction() << endl << endl;

	_getch();
	return 0;
}