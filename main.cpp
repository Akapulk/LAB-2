#include <iostream>
#include <locale>
#include "Queue.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "ru"); 
	srand(time(NULL)); 

	int size = rand() % 8 + 3; //рандом от 3 до 10

	//создаем объект и передаем ему размер очереди
	Queue objA(size);
	//создаем объект с помощью конструктора копирования, в него будем записывать результаты выполнения унарных операций
	Queue objB(objA);
	int menu; //переменная для switch
	bool flag = true; //bool переменная для цикла while

	while (flag)
	{
		system("cls");
		//простой вывод всех данных на консоль
		cout << "Размер очереди: " << objA.getSize() << endl << endl; //getSize возвращает int, значит её можно записать в <<
		cout << "Объекты до операций" << endl << endl;
		cout << "ObjA: ";
		objA.show(); //показываем очередь в objA
		cout << endl << endl << "ObjB: ";
		objB.show(); //показываем очередь в objB
		cout << endl << endl;

		//Сама менюшка
		cout << "1) ObjB = ++ObjA" << endl;
		cout << "2) ObjB = ObjA++" << endl;
		cout << "3) ObjB = --ObjA" << endl;
		cout << "4) ObjB = ObjA--" << endl;
		cout << "5) ObjB = !ObjA" << endl;
		cout << "0) Выход из программы" << endl;
		cout << "Выберите команду: ";
		cin >> menu; //Ввод пункта
		if (cin.fail()) { //проверка на некорректный ввод
			menu = -1; //устанавливаем значение figure равным -1
			cin.clear(); //очищает флаг ошибки cin (так что будущие операции ввода-вывода будут работать правильно)

			/*КОД НИЖЕ: переходит к следующей новой строке(чтобы игнорировать что - либо еще в той же строке,
			чтобы оно не вызывало другого сбоя анализа). Он будет пропускать только до 10000 символов,
			поэтому код предполагает, что пользователь не будет вводить очень длинную недопустимую строку. */
			cin.ignore(10000, '\n');
		}

		//ниже приведены все примеры использования перегурженных операторов инкремента, декремента и отрицания с объектом
		switch (menu)
		{
		case 1:	objB = ++objA; break; //а и b будут совпадать
		case 2: objB = objA++; break; //a изменится, b будет равно старому a
		case 3: objB = --objA; break; //а и b будут совпадать
		case 4: objB = objA--; break; //a изменится, b будет равно старому a
		case 5: objB = !objA; break;  //b будет равно отрицанию a
		case 0: flag = false; break; //выход
		default: cout << "Некорректный ввод" << endl; system("pause");
		}

		//если мы не вышли из программы, значит нужно показать рузльтат выполнения операций, чтобы сравнить с изначальными данными
		//и удостовериться, что операторы корректно работают
		if (menu > 0 && menu < 6)
		{
			cout << endl << "Объекты после операций" << endl << endl;
			cout << "ObjA: ";
			objA.show();
			cout << endl << endl << "ObjB: ";
			objB.show();
			cout << endl << endl;
			system("pause");
		}
	}
}