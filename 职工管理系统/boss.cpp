#include "boss.h"

//构造函数
Boss::Boss(int id, string name, int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = did;
}
//显示个人的信息
void Boss::showInfo()
{
	cout << "职工的编号: " << this->m_Id;
	cout << "\t" << "职工的姓名： " << this->m_Name;
	cout << "\t" << "岗位: " << this->getDeptName();
	cout << "\t岗位职责：统筹全局，给经理布置任务" << endl;
}
//获得岗位名称
string Boss::getDeptName()
{
	return string("老板");
}