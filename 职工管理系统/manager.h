#pragma once
#include<iostream>
#include"Worker.h"
using namespace std;

class Manager :public Woker
{
public:
	//���캯��
	Manager (int id, string name, int did);
	//��ʾ���˵���Ϣ
	void showInfo();
	//��ø�λ����
	string getDeptName();
};