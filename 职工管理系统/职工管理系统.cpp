#include<iostream>
#include"workerManager.h"
#include"Worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
using namespace std;



int main()
{
	////���Դ���
	//Woker * employee = new Employee(1, "����", 1);
	//employee->showInfo();
	//delete employee;
	//Woker * manager = new Manager(2, "����", 2);
	//manager->showInfo();
	//delete manager;
	//Woker *boss = new Boss(3, "����", 3);
	//boss->showInfo();
	//delete boss;
	//ʵ����һ�������ߵĶ���
	WorkerManager wm;
	
	int choice = 0;
	while (true)
	{
		//����չʾ�˵��ĳ�Ա����
		wm.Show_Menue();
		cout << "���������ѡ��:  " << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:   //�˳�ϵͳ
			wm.ExitSystem();
			break;
		case 1:    //����ְ��
			wm.Add_Emp();
			break;
		case 2:   //��ʾְ��
			wm.show_Emp();
			break;
		case 3: //ɾ��ְ��
			wm.Del_Emp();
		break; 
		case 4:  //�޸�ְ��
			wm.Mod_Emp();
			break;
		case 5:  //����ְ��
			wm.Find_Emp();
			break;
		case 6:  //����ְ��
			wm.Sort_Emp();
			break;
		case 7:  //����ĵ�
			wm.Clean_Emp();
			break;
		default :
			system("cls");  //����
			break;

		}
	}
	system("pause");
	return 0;
}