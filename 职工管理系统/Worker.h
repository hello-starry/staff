#pragma once
#include<iostream>
using namespace std;
#include <string>

class Woker
{
public:

	//显示个人的信息
	virtual  void showInfo() = 0;
	//获得岗位名称
	virtual string getDeptName() = 0;

	//职工的编号
	int m_Id;
	//职工的姓名
	string m_Name;
	//部门编号
	int m_DeptId;
};