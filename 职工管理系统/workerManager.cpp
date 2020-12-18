#include "workerManager.h"

WorkerManager::WorkerManager()
{
	//�ļ�������
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//���ļ�
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		//��ʼ������
		this->m_EmpNum = 0;
		//��ʼ��ָ��
		this->m_EmpArray = NULL;
		//��ʼ���ļ��Ƿ�Ϊ��
		this->m_fileIsEmpty = true;
		ifs.close();
		return;

	}
	//�ļ���������Ϊ�յ�
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//�ļ�Ϊ��
		cout << "�ʼ�Ϊ��" << endl;
		this->m_EmpNum = 0;
		//��ʼ��ָ��
		this->m_EmpArray = NULL;
		//��ʼ���ļ��Ƿ�Ϊ��
		this->m_fileIsEmpty = true;
		ifs.close();
		return;
	}
	//��������� �ļ������Ҳ�Ϊ��
	int num = this->get_EmpNum();
	cout << "ְ��������Ϊ" << num << endl;
	this->m_EmpNum = num;
	//���ٿռ� 
	this->m_EmpArray = new Woker *[this->m_EmpNum];
	//���ļ������ݴ浽������
	this->Init_Emp();
	/*for (int i = 0; i < this->m_EmpNum; i++)
	{
	cout << "ְ����ţ�" << this->m_EmpArray[i]->m_Id
	<< " ְ����������" << this->m_EmpArray[i]->m_Name
	<< " ְ���Ĳ���" << this->m_EmpArray[i]->m_DeptId << endl;
	}*/
}
WorkerManager::~WorkerManager()
{
	//���������ݽ����ͷ�
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
	cout << "*********  ��ӭʹ��ְ������ϵͳ�� **********" << endl;
	cout << "*************  0.�˳��������  *************" << endl;
	cout << "*************  1.����ְ����Ϣ  *************" << endl;
	cout << "*************  2.��ʾְ����Ϣ  *************" << endl;
	cout << "*************  3.ɾ����ְְ��  *************" << endl;
	cout << "*************  4.�޸�ְ����Ϣ  *************" << endl;
	cout << "*************  5.����ְ����Ϣ  *************" << endl;
	cout << "*************  6.���ձ������  *************" << endl;
	cout << "*************  7.��������ĵ�  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}
//�˳�ϵͳʵ��
void WorkerManager::ExitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}
void WorkerManager::Add_Emp()
{
	cout << "���������ְ��������" << endl;
	int addnum = 0; //�����û������ְ��������
	cin >> addnum;
	if (addnum > 0)
	{
		//���
		//������ӵ��¿ռ��С
		int newsize = this->m_EmpNum + addnum;//�¿ռ��С���� ԭ����¼������ + �����ӵ�����

		//�����еĿռ�
		Woker **newspace = new Woker *[newsize];
		//��ԭ���Ŀռ����ݣ��������µĿռ���
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newspace[i] = this->m_EmpArray[i];
			}
		}
		//��������µ�����
		for (int i = 0; i < addnum; i++)
		{
			int id;//ְ���ı��
			string name;//ְ��������
			int dselect;//���ŵ�ѡ��
			cout << "�������" << i + 1 << "����ְ���ı��" << endl;
			cin >> id;
			cout << "�������" << i + 1 << "����ְ��������" << endl;
			cin >> name;
			cout << "�������ְ���ĸ�λ" << endl;
			cout << "1. ��ְͨ��" << endl;
			cout << "2. ����" << endl;
			cout << "3. �ϰ�" << endl;
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
			//��������ְ��ָ�뱣�浽������
			newspace[this->m_EmpNum + i] = worker;

		}
		//�ͷ�ԭ�еĿռ�
		delete[] this->m_EmpArray;
		//�����¿ռ��ָ��
		this->m_EmpArray = newspace;
		//�����¿ռ�����
		this->m_EmpNum = newsize;
		cout << "�ɹ������" << addnum << "��" << endl;
		//�ɹ����֮�󣬱��浽�ļ���
		this->save();
		this->m_fileIsEmpty = false; //�ļ���Ϊ��

	}
	else
	{
		cout << "��������" << endl;
	}
	system("pause");
	system("cls");
}


//�����ļ��Ķ���
void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out); //д�ļ�
	//��ÿ���˵�����д�뵽�ļ���
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id <<" "<<  this->m_EmpArray[i]->m_Name  <<" "<< this->m_EmpArray[i]->m_DeptId << endl;
	}
	//�ر��ļ�
	ofs.close();

}
int  WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);  //���ļ�  ���ļ�
	int id;
	string name;
	int did;
	
	int num = 0;
	while (ifs>>id && ifs>>name &&ifs >>did)  //��ȡһ�� ��¼һ��
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
		cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			this->m_EmpArray[i]->showInfo();
		}
	}
	//�����������
	system("pause");
	system("cls");
}
void WorkerManager::Del_Emp()
{
	//�ļ��Ƿ����
	if (this->m_fileIsEmpty)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ��kong" << endl;
	}
	else
	{
		cout << "������Ҫɾ��ְ����id" << endl;
		int id = 0;
		cin >> id;
		int index = this->Is_Exist(id);
		if (index != -1)  //˵��ְ�����ڣ�����Ҫִ��ɾ������
		{
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];  //����ǰ��
			}
			this->m_EmpNum--; //���������м�¼����Ա����.
			//�����º������ ͬ�����ļ���
			this->save();
			cout << "ɾ���ɹ�" << endl;
		}
		else
		{
			cout << "û���ҵ���ְ��" << endl;
		}
	}
	//�����������
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
			//˵���ҵ������ְ��
			index = i;
			break;
		}
	}
	return index;
}
void WorkerManager::Mod_Emp()
{

	//�ļ��Ƿ����
	if (this->m_fileIsEmpty)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ����" << endl;
	}
	else
	{
		cout << "������Ҫ�޸�ְ����id" << endl;
		int id = 0;
		cin >> id;
		int index = this->Is_Exist(id);
		if (index != -1)  //˵��ְ�����ڣ�����Ҫִ��ɾ������
		{
			//ɾ��֮ǰ��ְ��
			delete this->m_EmpArray[index];
			int newid = 0;
			string newname = "";
			int newdid = 0;
			cout << "������" << id << "������ְ��������Ϣ" << endl;
			cout << "�������µ�id" << endl;
			cin >> newid;
			cout << "�������µ�����" << endl;
			cin >> newname;
			cout << "�������еĲ��ű��" << endl;
			cout << "1. ��ְͨ��" << endl;
			cout << "2. ����" << endl;
			cout << "3. �ϰ�" << endl;
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
			cout << "�޸ĳɹ�" << endl;
			//���浽�ļ��� ����ͬ��
			this->save();
		}
		else
		{
			cout << "û���ҵ���ְ��" << endl;
		}
	}
	system("pause");
	system("cls");
}
void WorkerManager::Find_Emp()
{
	if (this->m_fileIsEmpty)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
	}
	else
	{
		cout << "��������ҵķ�ʽ" << endl;
		cout << "1.����ְ���ı�Ž��в���" << endl;
		cout << "2.����ְ�����������в���" << endl;
		int select;
		cin >> select;
		if (select == 1)
		{
			//���ձ�Ž��в���
			int id;
			cout << "������ְ���ı��" << endl;
			cin >> id;
			int ret = this->Is_Exist(id);
			if (ret != -1)
			{
				//�д��ˣ�
				cout << "���ҳɹ�����ְ������Ϣ���£�" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "���޴���" << endl;
			}
		}
		else if (select == 2)
		{
			//�����������в���
			string name;
			cout << "����������˵�����" << endl;
			cin >> name;
			//��һ���ж��Ƿ�鵽�ı�־
			bool flag = false; //Ĭ��û���ҵ���ְ��

			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					cout << "���ҳɹ���ְ���ı��Ϊ:" << this->m_EmpArray[i]->m_Id << "��ְ����Ϣ����" << endl;
					flag = true;
					this->m_EmpArray[i]->showInfo();
				}
			}
			if (flag == false)
			{
				cout << "����ʧ�ܣ����޴���" << endl;
			}
		}
		else
		{
			cout << "�����ѡ������" << endl;
		}
		
	}
	//�����������
	system("pause");
	system("cls");
}
void WorkerManager::Sort_Emp()
{
	if (this->m_fileIsEmpty)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ѡ���������ǽ�������" << endl;
		cout << "1.��ְ����Ž�������" << endl;
		cout << "2. ��ְ���ı�Ž��н�������" << endl;
		int select = 0;
		cout << "���������ѡ��" << endl;
		cin >> select;
		for (int i = 0; i <m_EmpNum; i++)
		{
			int minORmax = i;
			for (int j = i + 1; j < m_EmpNum; j++)
			{
				if (select == 1)  //��������
				{
					if (this->m_EmpArray[minORmax]->m_Id >this->m_EmpArray[j]->m_Id )
					{
						minORmax = j;
					}
				}
				else //����
				{
					if (this->m_EmpArray[minORmax]->m_Id < this->m_EmpArray[j]->m_Id)
					{
						minORmax = j;
					}
				}
			}
			//�ж�һ��ʼ����Сֵ�����ֵ�Ƿ������ֵ��Сֵ
			if (i != minORmax)
			{
				Woker *temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minORmax];
				this->m_EmpArray[minORmax] = temp;
			}
			
		}
		cout << "����ɹ�" << endl;
		//�������
		this->save();
		this->show_Emp();
	}
	
	
	
}
void WorkerManager::Clean_Emp()
{
	cout << "ȷ���Ƿ����" << endl;
	cout << "1.ȷ��" << endl;
	cout << "2. ����գ�����" << endl;
	int select;
	cout << "���������ѡ��" << endl;
	if (select = 1)
	{
		//�û����������ļ�
		ofstream ofs(FILENAME, ios::trunc); //trunc ɾ���ļ��ڴ��´���
		ofs.close();
		if (this->m_EmpArray != NULL)
		{
			//ɾ��������ÿ������
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

	cout << "��ճɹ�" << endl;
	system("pause");
	system("cls");
}