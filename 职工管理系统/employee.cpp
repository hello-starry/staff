#include "employee.h"

//���캯��
Employee::Employee(int id ,string name ,int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = did;
}
//��ʾ���˵���Ϣ
void Employee::showInfo()
{
	cout << "ְ���ı��: " << this->m_Id;
	cout << "\t" << "ְ���������� " << this->m_Name;
	cout << "\t" << "��λ: " << this->getDeptName();
	cout << "\t��λְ����ɾ�����������" << endl;
}
//��ø�λ����
string Employee::getDeptName()
{
	return "Ա��";
}