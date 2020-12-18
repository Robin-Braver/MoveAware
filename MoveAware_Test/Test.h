#pragma once
#include"MA_MyArray.h"
#include"MyArray.h"

using MA = MA_MyArray<int>;
using NoMA = MyArray<int>;

//�����ƶ��������ܺ���
template<typename Container>
int* Test_Perfomance(Container Con0, size_t size,int Randseed)//Con:������size���ƶ���ģ,RandSeed:���������
{
	typedef typename iterator_traits<typename Container::iterator>::value_type Val_type;//��ȡ����ֵ����
	srand(Randseed);//���������
	size_t insert_num = 0;//��Ҫ���������
	int time[3];//�������ݴ�����¼ʱ��
	/*���뵽Ŀ������*/
	clock_t begin1 = clock();
	for (size_t i = 0; i < size; ++i)
	{
		insert_num = rand() % 100+1;//����1-100�������
		Val_type array(insert_num, i);//����֮ǰ�������������������
		auto iter = Con0.end();//��ȡβ��������
		Con0.insert(iter, Val_type(array));//��β������array,������ֵ����
	}
	clock_t end1 = clock();
	time[0] = end1 - begin1;

	cout << "�����ģ��" << Con0.size() << endl;
	cout << "���뻨�ѣ�" << end1 - begin1 << "ms" << endl;

	/*����ʹ���ƶ�����*/
	clock_t begin2 = clock();
	Container Con1_MA(move(Con0));//�ƶ�����
	clock_t end2 = clock();
	time[1] = end2 - begin2;

	cout << "�ƶ����죨���ƶ����壩���ѣ�" << end2 - begin2 << "ms" << endl;

	/*���Բ�ʹ���ƶ�����*/
	clock_t begin3 = clock();
	Container Con2_NoMA(Con1_MA);//��������
	clock_t end3 = clock();
	time[2] = end3 - begin3;
	cout << "�������죨�����ƶ����壩���ѣ�" << end3 - begin3 << "ms" << endl;
	return time;
}


template<typename Container>
int Test_Perfomance2(Container Con0, size_t size, int Randseed)//Con:������size���ƶ���ģ,RandSeed:���������
{
	typedef typename iterator_traits<typename Container::iterator>::value_type Val_type;//��ȡ����ֵ����
	srand(Randseed);//���������
	size_t insert_num = 0;//��Ҫ���������

	/*���뵽Ŀ������*/
	clock_t begin1 = clock();
	for (size_t i = 0; i < size; ++i)
	{
		insert_num = rand() % 100 + 1;//����1-100�������
		Val_type array(insert_num, i);//����֮ǰ�������������������
		auto iter = Con0.begin();//��ȡ�ײ�������
		//iter++;
		Con0.insert(iter, Val_type(array));//��β������array,������ֵ����
	}
	clock_t end1 = clock();


	cout << "�����ģ��" << Con0.size() << endl;
	cout << "���뻨�ѣ�" << end1 - begin1 << "ms" << endl;
	return (end1 - begin1);
}



