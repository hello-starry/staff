#pragma once  //��ֹͷ�ļ��ظ�����
#include<iostream>  //��������������ͷ�ļ�
using namespace std;  //ʹ�ñ�׼�����ռ�
#include"Worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
#include<fstream>
#define FILENAME "empFile.txt" 

class WorkerManager
{
public :
	//���캯��
	WorkerManager();
	//��ʾ�˵�����
	void Show_Menue();
	//�˳�ϵͳ
	void  ExitSystem();
	//��¼ְ��������
	int m_EmpNum;
	//ְ�������ָ��
	Woker ** m_EmpArray;
	//���ְ��
	void Add_Emp();
	//�����ļ�
	void save();
	//�ж��ļ��Ƿ�Ϊ��
	bool m_fileIsEmpty;
	//ͳ���ļ��е�����
	int  get_EmpNum();
	//ְ����ʼ��
	void Init_Emp();
	//��ʾְ����Ϣ
	void show_Emp();
	//ɾ��ְ��
	void Del_Emp();
	//�ж�ְ���Ƿ����,������ڷŻ�ְ�����ڵ������е�λ�ã���������ڷ���-1
	int  Is_Exist(int id);
	//�޸�ְ��
	void Mod_Emp();
	//����ְ��
	void Find_Emp();
	//����ְ���ı�Ž�������
	void Sort_Emp();
	//��պ���
	void Clean_Emp();
	//��������
	~WorkerManager();

};