#include "employee.h"

//构造函数
Employee::Employee(int id ,string name ,int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = did;
}
//显示个人的信息
void Employee::showInfo()
{
	cout << "职工的编号: " << this->m_Id;
	cout << "\t" << "职工的姓名： " << this->m_Name;
	cout << "\t" << "岗位: " << this->getDeptName();
	cout << "\t岗位职责：完成经理交代的任务" << endl;
}
//获得岗位名称
string Employee::getDeptName()
{
	return "员工";
}