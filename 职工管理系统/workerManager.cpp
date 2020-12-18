#include "workerManager.h"

WorkerManager::WorkerManager()
{
	//文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//读文件
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		//初始化属性
		this->m_EmpNum = 0;
		//初始化指针
		this->m_EmpArray = NULL;
		//初始化文件是否为空
		this->m_fileIsEmpty = true;
		ifs.close();
		return;

	}
	//文件存在数据为空的
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//文件为空
		cout << "问价为空" << endl;
		this->m_EmpNum = 0;
		//初始化指针
		this->m_EmpArray = NULL;
		//初始化文件是否为空
		this->m_fileIsEmpty = true;
		ifs.close();
		return;
	}
	//第三种情况 文件存在且不为空
	int num = this->get_EmpNum();
	cout << "职工的人数为" << num << endl;
	this->m_EmpNum = num;
	//开辟空间 
	this->m_EmpArray = new Woker *[this->m_EmpNum];
	//将文件的数据存到数组中
	this->Init_Emp();
	/*for (int i = 0; i < this->m_EmpNum; i++)
	{
	cout << "职工编号：" << this->m_EmpArray[i]->m_Id
	<< " 职工的姓名：" << this->m_EmpArray[i]->m_Name
	<< " 职工的部门" << this->m_EmpArray[i]->m_DeptId << endl;
	}*/
}
WorkerManager::~WorkerManager()
{
	//堆区的数据进行释放
	if (this->m_EmpArray != NULL)
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (this->m_EmpArray[i] != NULL)
			{
				delete this->m_EmpArray[i];
			}
		}
		delete[] this->m_EmpArray;
		m_EmpArray = NULL;
	}
}
void  WorkerManager::Show_Menue()
{
	cout << "********************************************" << endl;
	cout << "*********  欢迎使用职工管理系统！ **********" << endl;
	cout << "*************  0.退出管理程序  *************" << endl;
	cout << "*************  1.增加职工信息  *************" << endl;
	cout << "*************  2.显示职工信息  *************" << endl;
	cout << "*************  3.删除离职职工  *************" << endl;
	cout << "*************  4.修改职工信息  *************" << endl;
	cout << "*************  5.查找职工信息  *************" << endl;
	cout << "*************  6.按照编号排序  *************" << endl;
	cout << "*************  7.清空所有文档  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}
//退出系统实现
void WorkerManager::ExitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}
void WorkerManager::Add_Emp()
{
	cout << "请输入添加职工的人数" << endl;
	int addnum = 0; //保存用户输入的职工的数量
	cin >> addnum;
	if (addnum > 0)
	{
		//添加
		//计算添加的新空间大小
		int newsize = this->m_EmpNum + addnum;//新空间大小等于 原来记录的人数 + 新增加的人数

		//开辟行的空间
		Woker **newspace = new Woker *[newsize];
		//将原来的空间数据，拷贝到新的空间下
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newspace[i] = this->m_EmpArray[i];
			}
		}
		//批量添加新的数据
		for (int i = 0; i < addnum; i++)
		{
			int id;//职工的编号
			string name;//职工的姓名
			int dselect;//部门的选项
			cout << "请输入第" << i + 1 << "个新职工的编号" << endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "个新职工的姓名" << endl;
			cin >> name;
			cout << "请输入该职工的岗位" << endl;
			cout << "1. 普通职工" << endl;
			cout << "2. 经理" << endl;
			cout << "3. 老板" << endl;
			cin >> dselect;
			Woker * worker = NULL;
			switch (dselect)
			{
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2 :
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			}
			//将创建的职工指针保存到数组中
			newspace[this->m_EmpNum + i] = worker;

		}
		//释放原有的空间
		delete[] this->m_EmpArray;
		//更改新空间的指向
		this->m_EmpArray = newspace;
		//更新新空间人数
		this->m_EmpNum = newsize;
		cout << "成功添加了" << addnum << "人" << endl;
		//成功添加之后，保存到文件中
		this->save();
		this->m_fileIsEmpty = false; //文件不为空

	}
	else
	{
		cout << "输入有误" << endl;
	}
	system("pause");
	system("cls");
}


//保存文件的定义
void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out); //写文件
	//将每个人的数据写入到文件中
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id <<" "<<  this->m_EmpArray[i]->m_Name  <<" "<< this->m_EmpArray[i]->m_DeptId << endl;
	}
	//关闭文件
	ofs.close();

}
int  WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);  //打开文件  读文件
	int id;
	string name;
	int did;
	
	int num = 0;
	while (ifs>>id && ifs>>name &&ifs >>did)  //读取一行 记录一次
	{
		num++;
	}
	ifs.close();
	return num;

 }
void WorkerManager::Init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int did;
	int index = 0;
	while (ifs >> id&& ifs >> name && ifs >> did)
	{
		Woker *worker = NULL;
		if (did == 1)
		{
			worker = new Employee(id, name, did);
		}
		else if (did == 2)
		{
			worker = new Manager(id, name, did);
		}
		else if (did == 3)
		{
			worker = new Boss(id, name, did);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}
	ifs.close();
}
void WorkerManager::show_Emp()
{
	if (this->m_fileIsEmpty)
	{
		cout << "文件不存在或者记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			this->m_EmpArray[i]->showInfo();
		}
	}
	//按任意键清屏
	system("pause");
	system("cls");
}
void WorkerManager::Del_Emp()
{
	//文件是否存在
	if (this->m_fileIsEmpty)
	{
		cout << "文件不存在或者记录为开kong" << endl;
	}
	else
	{
		cout << "请输入要删除职工的id" << endl;
		int id = 0;
		cin >> id;
		int index = this->Is_Exist(id);
		if (index != -1)  //说明职工存在，并且要执行删除操作
		{
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];  //数据前移
			}
			this->m_EmpNum--; //更新数组中记录的人员个数.
			//将更新后的数据 同步到文件中
			this->save();
			cout << "删除成功" << endl;
		}
		else
		{
			cout << "没有找到该职工" << endl;
		}
	}
	//按任意键清屏
	system("pause");
	system("cls");
}
int WorkerManager::Is_Exist(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_Id == id)
		{
			//说明找到了这个职工
			index = i;
			break;
		}
	}
	return index;
}
void WorkerManager::Mod_Emp()
{

	//文件是否存在
	if (this->m_fileIsEmpty)
	{
		cout << "文件不存在或者记录为开空" << endl;
	}
	else
	{
		cout << "请输入要修改职工的id" << endl;
		int id = 0;
		cin >> id;
		int index = this->Is_Exist(id);
		if (index != -1)  //说明职工存在，并且要执行删除操作
		{
			//删除之前的职工
			delete this->m_EmpArray[index];
			int newid = 0;
			string newname = "";
			int newdid = 0;
			cout << "查找了" << id << "请输入职工的新信息" << endl;
			cout << "请输入新的id" << endl;
			cin >> newid;
			cout << "亲输入新的姓名" << endl;
			cin >> newname;
			cout << "请输入行的部门编号" << endl;
			cout << "1. 普通职工" << endl;
			cout << "2. 经理" << endl;
			cout << "3. 老板" << endl;
			cin >> newdid;
			Woker *worker = NULL;
			switch (newdid)
			{
			case 1:
				worker = new Employee(newid, newname, newdid);
				break;
			case 2:
				worker = new Manager(newid, newname, newdid);
				break;
			case 3:
				worker = new Boss(newid, newname, newdid);
				break;
			}
			this->m_EmpArray[index] = worker;
			cout << "修改成功" << endl;
			//保存到文件中 进行同步
			this->save();
		}
		else
		{
			cout << "没有找到该职工" << endl;
		}
	}
	system("pause");
	system("cls");
}
void WorkerManager::Find_Emp()
{
	if (this->m_fileIsEmpty)
	{
		cout << "文件不存在或者记录为空" << endl;
	}
	else
	{
		cout << "请输入查找的方式" << endl;
		cout << "1.按照职工的编号进行查找" << endl;
		cout << "2.按照职工的姓名进行查找" << endl;
		int select;
		cin >> select;
		if (select == 1)
		{
			//按照编号进行查找
			int id;
			cout << "请输入职工的编号" << endl;
			cin >> id;
			int ret = this->Is_Exist(id);
			if (ret != -1)
			{
				//有此人，
				cout << "查找成功，改职工的信息如下：" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "查无此人" << endl;
			}
		}
		else if (select == 2)
		{
			//按照姓名进行查找
			string name;
			cout << "请输入查找人的姓名" << endl;
			cin >> name;
			//加一个判断是否查到的标志
			bool flag = false; //默认没有找到该职工

			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					cout << "查找成功，职工的编号为:" << this->m_EmpArray[i]->m_Id << "的职工信息如下" << endl;
					flag = true;
					this->m_EmpArray[i]->showInfo();
				}
			}
			if (flag == false)
			{
				cout << "查找失败，查无此人" << endl;
			}
		}
		else
		{
			cout << "输入的选项有误" << endl;
		}
		
	}
	//按任意键清屏
	system("pause");
	system("cls");
}
void WorkerManager::Sort_Emp()
{
	if (this->m_fileIsEmpty)
	{
		cout << "文件不存在或者记录为空" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请选择是升序还是降序排列" << endl;
		cout << "1.按职工编号进行升序" << endl;
		cout << "2. 按职工的编号进行降序排列" << endl;
		int select = 0;
		cout << "请输入你的选择" << endl;
		cin >> select;
		for (int i = 0; i <m_EmpNum; i++)
		{
			int minORmax = i;
			for (int j = i + 1; j < m_EmpNum; j++)
			{
				if (select == 1)  //升序排列
				{
					if (this->m_EmpArray[minORmax]->m_Id >this->m_EmpArray[j]->m_Id )
					{
						minORmax = j;
					}
				}
				else //降序
				{
					if (this->m_EmpArray[minORmax]->m_Id < this->m_EmpArray[j]->m_Id)
					{
						minORmax = j;
					}
				}
			}
			//判断一开始的最小值和最大值是否还是最大值最小值
			if (i != minORmax)
			{
				Woker *temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minORmax];
				this->m_EmpArray[minORmax] = temp;
			}
			
		}
		cout << "排序成功" << endl;
		//保存磁盘
		this->save();
		this->show_Emp();
	}
	
	
	
}
void WorkerManager::Clean_Emp()
{
	cout << "确认是否清空" << endl;
	cout << "1.确认" << endl;
	cout << "2. 不清空，返回" << endl;
	int select;
	cout << "请输入你的选项" << endl;
	if (select = 1)
	{
		//用户真的想清空文件
		ofstream ofs(FILENAME, ios::trunc); //trunc 删除文件在从新创建
		ofs.close();
		if (this->m_EmpArray != NULL)
		{
			//删除堆区的每个数据
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				delete this->m_EmpArray[i];
			}

			delete[] this->m_EmpArray;
			m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_fileIsEmpty = true;
		}
	}

	cout << "清空成功" << endl;
	system("pause");
	system("cls");
}