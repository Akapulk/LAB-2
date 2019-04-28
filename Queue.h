#pragma once
#include "Node.h"

//����� �������
class Queue {
	int size; //������ �������
	Node *tail; //��������� �� ����� �������
public:
	Queue() {}; //����������� �� ��������� (������)
	//explicit ������������� ������� �������������� ����� ��� �������������, �� ���� ������ �������� "Queue a = 6"
	explicit Queue(int count); //����������� � ����������
	Queue(const Queue& ob); //����������� �����������
	~Queue(); //����������
	int getSize(); //����� ������ size - ������ �������
	void push(int data); //����� ���������� �������� � �����, ��������� ���������� � ����� �������� data
	void show(); //����� ������ ������� �� �����

	Queue& operator = (const Queue &ob); //���������� ��������� ������������
	Queue operator ! (); //���������� ��������� ���������

	Queue& operator ++(); //���������� ��������� ����������� ����������
	Queue& operator --(); //���������� ��������� ����������� ����������
	Queue operator ++(int); //���������� ��������� ������������ ����������
	Queue operator --(int); //���������� ��������� ������������ ����������
};