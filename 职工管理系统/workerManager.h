#pragma once  //防止头文件重复包含
#include<iostream>  //包含输入和输出流头文件
using namespace std;  //使用标准命名空间
#include"Worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
#include<fstream>
#define FILENAME "empFile.txt" 

class WorkerManager
{
public :
	//构造函数
	WorkerManager();
	//显示菜单功能
	void Show_Menue();
	//退出系统
	void  ExitSystem();
	//记录职工的人数
	int m_EmpNum;
	//职工数组的指针
	Woker ** m_EmpArray;
	//添加职工
	void Add_Emp();
	//保存文件
	void save();
	//判断文件是否为空
	bool m_fileIsEmpty;
	//统计文件中的人数
	int  get_EmpNum();
	//职工初始化
	void Init_Emp();
	//显示职工信息
	void show_Emp();
	//删除职工
	void Del_Emp();
	//判断职工是否存在,如果存在放回职工所在的数组中的位置，如果不存在返回-1
	int  Is_Exist(int id);
	//修改职工
	void Mod_Emp();
	//查找职工
	void Find_Emp();
	//按照职工的编号进行排序
	void Sort_Emp();
	//清空函数
	void Clean_Emp();
	//析构函数
	~WorkerManager();

};