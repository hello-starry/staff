#pragma once
#include<iostream>
#include"Worker.h"
using namespace std;

class Boss :public Woker
{
public:
	//构造函数
	Boss(int id, string name, int did);
	//显示个人的信息
	void showInfo();
	//获得岗位名称
	string getDeptName();
}; 
