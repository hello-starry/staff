#include "manager.h"

//���캯��
Manager::Manager (int id, string name, int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = did;
}
//��ʾ���˵���Ϣ
void Manager::showInfo()
{
	cout << "ְ���ı��: " << this->m_Id;
	cout << "\t" << "ְ���������� " << this->m_Name;
	cout << "\t" << "��λ: " << this->getDeptName();
	cout << "\t��λְ�𣺸���ͨԱ���·���������ϰ岼�õ�����" << endl;
}
//��ø�λ����
string Manager::getDeptName()
{
	return string ("����");
}