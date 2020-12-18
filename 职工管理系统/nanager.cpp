#include "manager.h"

//构造函数
Manager::Manager (int id, string name, int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = did;
}
//显示个人的信息
void Manager::showInfo()
{
	cout << "职工的编号: " << this->m_Id;
	cout << "\t" << "职工的姓名： " << this->m_Name;
	cout << "\t" << "岗位: " << this->getDeptName();
	cout << "\t岗位职责：给普通员工下发任务，完成老板布置的任务" << endl;
}
//获得岗位名称
string Manager::getDeptName()
{
	return string ("经理");
}