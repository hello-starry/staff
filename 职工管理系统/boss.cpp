#include "boss.h"

//���캯��
Boss::Boss(int id, string name, int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = did;
}
//��ʾ���˵���Ϣ
void Boss::showInfo()
{
	cout << "ְ���ı��: " << this->m_Id;
	cout << "\t" << "ְ���������� " << this->m_Name;
	cout << "\t" << "��λ: " << this->getDeptName();
	cout << "\t��λְ��ͳ��ȫ�֣�������������" << endl;
}
//��ø�λ����
string Boss::getDeptName()
{
	return string("�ϰ�");
}