#pragma once
#include<iostream>
using namespace std;
#include <string>

class Woker
{
public:

	//��ʾ���˵���Ϣ
	virtual  void showInfo() = 0;
	//��ø�λ����
	virtual string getDeptName() = 0;

	//ְ���ı��
	int m_Id;
	//ְ��������
	string m_Name;
	//���ű��
	int m_DeptId;
};