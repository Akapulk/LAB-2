#include "Queue.h"
#include <iostream>

using namespace std;

//����������� � ����������
Queue::Queue(int count) //�������� ������ ����������� �������
{
	for (int i = 0; i < count; ++i) //��������� count ��������� � �������
	{
		int value = rand() % 21 - 10; //����� ��������� �������� �� -10 �� 10
		push(value); //�������� ����� ���������� �������� � ������� � �������� ��� ���������� ��������
	}
}

//����������� �����������
Queue::Queue(const Queue & ob)
{
	Node *tmp = ob.tail; //���������-�������� �� �������, ������� ����� ����������, ��� ��� ������ ������ tail
	this->size = 0; //� �������, � ������� ����� ���������� ������������� ������ ������� ������ 0
	int *ptr = new int[ob.size]; //������ ��� ������ ���� �������� �� �������, ������� ����� ����������

	//�������� �������� � ������, ��� ��� ��������� �� ������� ����� ������ � �������� �������
	for (int i = 0; i < ob.size; ++i)
	{
		ptr[i] = tmp->data; //���������� ��������
		tmp = tmp->prev; //����������� ��������� �� ���������� �������
	}

	//�������� �������� � ����� ������ � ������ �������
	for (int i = ob.size - 1; i >= 0; --i)
		this->push(ptr[i]); //��������� �������

	delete[] ptr; //�������� ������ �����������, ������ ���� � ���������
}

//����������
Queue::~Queue()
{
	Node *tmp; //���������-��������
	for (int i = 0; i < size; ++i) //������� ��� size ��������� �� �������
	{
		tmp = tail; //���������� ��������� �� ��������� �������
		tail = tail->prev; //����������� tail �� ������������� �������
		delete tmp; //������� ��������� �������
	}
	size = 0; //������� �����
}

//������ ������� �������
int Queue::getSize()
{
	return size; //������ ���������� ������ �������
}

//����� ����������
void Queue::push(int data)
{
	Node* tmp = new Node; //������� ����� ������, � �� ���� ����� ��������� ��������� tmp
	tmp->data = data; //���������� � ���� data ��������, ������� �� ��������
	tmp->prev = tail; // ����� ������� ��������� �� ��������� � ������� �������, �.�. ����� ���
	tail = tmp; // ����� ��������� �� ����� �������
	++size; //����������� ���������� ��������� � �������;
}

//����� �������
void Queue::show()
{
	Node *tmp = tail; //���������-��������
	int *ptr = new int[size]; //������ ��� ������ ���� �������� �� �������

	//�������� �������� � ������, ��� ��� ��������� �� ������� ����� ������ � �������� �������
	for (int i = 0; i < size; ++i)
	{
		ptr[i] = tmp->data; //���������� ��������
		tmp = tmp->prev; //����������� ��������� �� ���������� �������
	}

	//������� �������� � ������ �������
	for (int i = size - 1; i >= 0; --i)
		cout << ptr[i] << " "; //������� �������

	delete[] ptr; //�������� ������ �����������, ������ ���� � ���������
}

//���������� ��������� ������������, ������ ����� ������� (this), ������ ������ ������� � �������� ���������
Queue & Queue::operator=(const Queue & ob)
{
	Node *tmp1 = tail; //��������� �� ������� ����� �� =
	Node *tmp2 = ob.tail; //��������� �� ������� ������ �� =

	for (int i = 0; i < size; ++i) //����������� �� ���� �������
	{
		tmp1->data = tmp2->data; //����������� �������� ������� ����� �������� �������� ������� ������
		tmp1 = tmp1->prev; //����������� ��������� �� ���������� ������� ������� �����
		tmp2 = tmp2->prev; //����������� ��������� �� ���������� ������� ������� ������
	}

	return *this; //���������� ������ ����� �� =, �� ���� ��� ������� ������
}

//���������� ��������� ���������
//��� ��� �� ���������� ��������� ������, �� ���������� �� ��������
Queue Queue::operator!()
{
	/*��� ��� ��� �� ���� ������ ��� ������, ��� �������� �������� ���� �������� (this), �� �� ������� ��������� ������, � 
	������� � ����� ���������� ��������� this �������*/
	Queue res(*this); //������� ����� ������� � ������� ������������ �����������
	Node *tmp = res.tail; //��������� �� ����� ������� ���������� ������� 
	for (int i = 0; i < size; ++i) //����������� �� ���� �������
	{
		tmp->data *= -1; //������ ������� �������� �� -1
		tmp = tmp->prev; //����������� ���������
	}
	return res;
}


/*
1 - ���������� ��������� � ��������� �������� ���, ��� �� ������� �����������/���������, � ����� ��������� ��������� ��������
�������� ��������, ������� ��� ����������� ���������� �� ������ ��������� �������� ��������� �������, ����� ������ � �������� ���
�����, � � ����� ����� ������� �������� ��������� �������
2 - ������ ���������� ������ �� ��������� �������
3 - ����� ���������� ����� ��� �������, � ��� �������� � �������� ��������� ����������� ������ int ��������, ���� ��� ��������
���� - �� ��� ��������, ���� ��� ��� - �������
4 - ���� �������� ������������� ��� �����, �� ��� ������ �� ���������� � �������� ���������, �� ������������ ��� this,
���� ��� ������������� �������, �� ���������� �������� ������ � �������� ��������� */

//���������� �����, ������ ���������� ������ �� ������
//�����, ������ ������, ��� �������� ������ �������� ������������ ��� this
Queue & Queue::operator++()
{
	int val; //�������, �� ������ ����� �����������
	cout << "������� �������� ��� ���������� �������: ";
	cin >> val;

	Node *tmp = tail; //���������-��������
	//����������� �� �������, � � ������� �������� ���������� ��, ��� �����
	for (int i = 0; i < size; ++i)
	{
		tmp->data += val; //���������� ��������� �������� � �������� �� �������
		tmp = tmp->prev; //����������� ���������
	}
	return *this; //���������� ������
}

//���������� ����������� ����������, ������ �� �������� ��������� ��������
Queue & Queue::operator--()
{
	int val;
	cout << "������� �������� ��� ���������� �������: ";
	cin >> val;

	Node *tmp = tail;
	for (int i = 0; i < size; ++i)
	{
		tmp->data -= val;
		tmp = tmp->prev;
	}
	return *this;
}

//��������, ������ ���������� ������� ��������� ������
Queue Queue::operator++(int)
{
	Queue res(*this); //���������� �������� ��������� �������, � ����� ������ � ���, ��� �����

	Node *tmp = tail; //���������-��������
	for (int i = 0; i < size; ++i) //� ������� �������� ������� ���������� ������ �������
	{
		tmp->data += size;
		tmp = tmp->prev; //����������� ��������� �� ���������� �������
	}
	return res; //���������� ��������� ������, ������� ������ � ���� ����������� ��������� ������� this
}

//��������, ������ ���������� ������� ��������� ������
Queue Queue::operator--(int)
{
	Queue res(*this);//���������� �������� ��������� �������, � ����� ������ � ���, ��� �����

	Node *tmp = tail;//���������-��������
	for (int i = 0; i < size; ++i)//�� ������� �������� ������� �������� ��������� ������ �������
	{
		tmp->data -= 2 * size;
		tmp = tmp->prev; //����������� ��������� �� ���������� �������
	}

	return res; //���������� ��������� ������, ������� ������ � ���� ����������� ��������� ������� this
}

