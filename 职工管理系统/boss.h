#pragma once
#include<iostream>
#include"Worker.h"
using namespace std;

class Boss :public Woker
{
public:
	//���캯��
	Boss(int id, string name, int did);
	//��ʾ���˵���Ϣ
	void showInfo();
	//��ø�λ����
	string getDeptName();
}; 
