#pragma once
#include<iostream>
#include"Worker.h"
using namespace std;

class Employee :public Woker
{
public:
	//���캯��
	Employee(int id, string name, int did);
	//��ʾ���˵���Ϣ
	void showInfo();
	//��ø�λ����
	string getDeptName();
};