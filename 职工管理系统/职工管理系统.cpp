#include<iostream>
#include"workerManager.h"
#include"Worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
using namespace std;



int main()
{
	////测试代码
	//Woker * employee = new Employee(1, "张三", 1);
	//employee->showInfo();
	//delete employee;
	//Woker * manager = new Manager(2, "李四", 2);
	//manager->showInfo();
	//delete manager;
	//Woker *boss = new Boss(3, "王五", 3);
	//boss->showInfo();
	//delete boss;
	//实例化一个管理者的对象
	WorkerManager wm;
	
	int choice = 0;
	while (true)
	{
		//调用展示菜单的成员函数
		wm.Show_Menue();
		cout << "请输入你的选择:  " << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:   //退出系统
			wm.ExitSystem();
			break;
		case 1:    //增加职工
			wm.Add_Emp();
			break;
		case 2:   //显示职工
			wm.show_Emp();
			break;
		case 3: //删除职工
			wm.Del_Emp();
		break; 
		case 4:  //修改职工
			wm.Mod_Emp();
			break;
		case 5:  //查找职工
			wm.Find_Emp();
			break;
		case 6:  //排序职工
			wm.Sort_Emp();
			break;
		case 7:  //清空文档
			wm.Clean_Emp();
			break;
		default :
			system("cls");  //清屏
			break;

		}
	}
	system("pause");
	return 0;
}