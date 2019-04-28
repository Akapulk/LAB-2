#include <iostream>
#include <locale>
#include "Queue.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "ru"); 
	srand(time(NULL)); 

	int size = rand() % 8 + 3; //������ �� 3 �� 10

	//������� ������ � �������� ��� ������ �������
	Queue objA(size);
	//������� ������ � ������� ������������ �����������, � ���� ����� ���������� ���������� ���������� ������� ��������
	Queue objB(objA);
	int menu; //���������� ��� switch
	bool flag = true; //bool ���������� ��� ����� while

	while (flag)
	{
		system("cls");
		//������� ����� ���� ������ �� �������
		cout << "������ �������: " << objA.getSize() << endl << endl; //getSize ���������� int, ������ � ����� �������� � <<
		cout << "������� �� ��������" << endl << endl;
		cout << "ObjA: ";
		objA.show(); //���������� ������� � objA
		cout << endl << endl << "ObjB: ";
		objB.show(); //���������� ������� � objB
		cout << endl << endl;

		//���� �������
		cout << "1) ObjB = ++ObjA" << endl;
		cout << "2) ObjB = ObjA++" << endl;
		cout << "3) ObjB = --ObjA" << endl;
		cout << "4) ObjB = ObjA--" << endl;
		cout << "5) ObjB = !ObjA" << endl;
		cout << "0) ����� �� ���������" << endl;
		cout << "�������� �������: ";
		cin >> menu; //���� ������
		if (cin.fail()) { //�������� �� ������������ ����
			menu = -1; //������������� �������� figure ������ -1
			cin.clear(); //������� ���� ������ cin (��� ��� ������� �������� �����-������ ����� �������� ���������)

			/*��� ����: ��������� � ��������� ����� ������(����� ������������ ��� - ���� ��� � ��� �� ������,
			����� ��� �� �������� ������� ���� �������). �� ����� ���������� ������ �� 10000 ��������,
			������� ��� ������������, ��� ������������ �� ����� ������� ����� ������� ������������ ������. */
			cin.ignore(10000, '\n');
		}

		//���� ��������� ��� ������� ������������� ������������� ���������� ����������, ���������� � ��������� � ��������
		switch (menu)
		{
		case 1:	objB = ++objA; break; //� � b ����� ���������
		case 2: objB = objA++; break; //a ���������, b ����� ����� ������� a
		case 3: objB = --objA; break; //� � b ����� ���������
		case 4: objB = objA--; break; //a ���������, b ����� ����� ������� a
		case 5: objB = !objA; break;  //b ����� ����� ��������� a
		case 0: flag = false; break; //�����
		default: cout << "������������ ����" << endl; system("pause");
		}

		//���� �� �� ����� �� ���������, ������ ����� �������� �������� ���������� ��������, ����� �������� � ������������ �������
		//� ��������������, ��� ��������� ��������� ��������
		if (menu > 0 && menu < 6)
		{
			cout << endl << "������� ����� ��������" << endl << endl;
			cout << "ObjA: ";
			objA.show();
			cout << endl << endl << "ObjB: ";
			objB.show();
			cout << endl << endl;
			system("pause");
		}
	}
}