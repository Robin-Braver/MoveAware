#include"Test.h"


void main()
{
	using Vec_Move = vector<MA_MyArray<int>>;
	using Vec_NoMove = vector<MyArray<int>>;
	using Lst_Move = list<MA_MyArray<int>>;
	using Lst_NoMove = list<MyArray<int>>;
	using Deq_Move = deque<MA_MyArray<int>>;
	using Deq_NoMove = deque<MyArray<int>>;
	using Set_Move = set<MA_MyArray<int>>;
	using Set_NoMove = set<MyArray<int>>;
	size_t size = 1*10000;
	int RandomSeed = 20;
	int epoch = 10;

	//deque<int>test{ 1,3 };
	//auto iter = test.begin();
	//cout << &(*iter) << endl;
	//iter++;
	//test.insert(iter, 2);//�ڵڶ���λ�ò���
	//iter = test.begin();//���»�ȡ��ַ
	//cout << &(*iter) << endl;


	//���ݴ�����������
	int vector1[2][3] = { 0,0,0,0,0,0 };
	int list1[2][3] = { 0,0,0,0,0,0 }; 
	int deque1[2][3] = { 0,0,0,0,0,0 }; 
	int set1[2][3] = { 0, 0, 0, 0, 0, 0 };
	for (int i = 0; i < epoch; ++i)
	{
		int* temp;
		cout << "��" << i + 1 << "�ֲ��Կ�ʼ" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);
		cout << "---****��TEST1��:Vector****---" << endl;
		cout << "---ʹ���ƶ�����---" << endl;
		Vec_Move vec1;
		temp = Test_Perfomance(vec1, size, RandomSeed);
		for (int i = 0; i < 3; ++i)//�ۻ�ʱ��
			vector1[0][i] += *(temp + i);

		cout << "---��ʹ���ƶ�����---" << endl;
		Vec_NoMove vec2;
		temp = Test_Perfomance(vec2, size, RandomSeed);
		for (int i = 0; i < 3; ++i)//�ۻ�ʱ��
			vector1[1][i] += *(temp + i);

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
		cout << "---****��TEST2��:List****---" << endl;
		cout << "---ʹ���ƶ�����---" << endl;
		Lst_Move Lst1;
		temp = Test_Perfomance(Lst1, size, RandomSeed);
		for (int i = 0; i < 3; ++i)//�ۻ�ʱ��
			list1[0][i] += *(temp + i);

		cout << "---��ʹ���ƶ�����---" << endl;
		Lst_NoMove Lst2;
		temp = Test_Perfomance(Lst2, size, RandomSeed);
		for (int i = 0; i < 3; ++i)//�ۻ�ʱ��
			list1[1][i] += *(temp + i);

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
		cout << "---****��TEST3��:Deque****---" << endl;
		cout << "---ʹ���ƶ�����---" << endl;
		Deq_Move deq1;
		temp = Test_Perfomance(deq1, size, RandomSeed);
		for (int i = 0; i < 3; ++i)//�ۻ�ʱ��
			deque1[0][i] += *(temp + i);

		cout << "---��ʹ���ƶ�����---" << endl;
		Deq_NoMove deq2;
		temp = Test_Perfomance(deq2, size, RandomSeed); 
		for (int i = 0; i < 3; ++i)//�ۻ�ʱ��
			deque1[1][i] += *(temp + i);

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
		cout << "---****��TEST4��:Set****---" << endl;
		cout << "---ʹ���ƶ�����---" << endl;
		Set_Move S1;
		temp = Test_Perfomance(S1, size, RandomSeed);
		for (int i = 0; i < 3; ++i)//�ۻ�ʱ��
			set1[0][i] += *(temp + i);

		cout << "---��ʹ���ƶ�����---" << endl;
		Set_NoMove S2;
		temp = Test_Perfomance<Set_NoMove>(S2, size, RandomSeed);
		for (int i = 0; i < 3; ++i)//�ۻ�ʱ��
			set1[1][i] += *(temp + i);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	}
	cout << "���ݹ�ģ��" << size << endl;
	cout << "vector" << endl;
	cout << "���ƶ�����" << endl;
	cout << "ƽ������ʱ�䣺" << vector1[0][0]/10 << endl;
	cout << "�ƶ�����ʱ�䣺" << vector1[0][1]/10 << endl;
	cout << "��������ʱ�䣺" << vector1[0][2]/10 << endl;
	cout << "���ƶ�����" << endl;
	cout << "ƽ������ʱ�䣺" << vector1[1][0]/10 << endl;
	cout << "�ƶ�����ʱ�䣺" << vector1[1][1]/10 << endl;
	cout << "��������ʱ�䣺" << vector1[1][2]/10 << endl;
	cout << endl;

	cout << "list" << endl;
	cout << "���ƶ�����" << endl;
	cout << "ƽ������ʱ�䣺" << list1[0][0] / 10 << endl;
	cout << "�ƶ�����ʱ�䣺" << list1[0][1] / 10 << endl;
	cout << "��������ʱ�䣺" << list1[0][2] / 10 << endl;
	cout << "���ƶ�����" << endl;
	cout << "ƽ������ʱ�䣺" << list1[1][0] / 10 << endl;
	cout << "�ƶ�����ʱ�䣺" << list1[1][1] / 10 << endl;
	cout << "��������ʱ�䣺" << list1[1][2] / 10 << endl;
	cout << endl;

	cout << "deque" << endl;
	cout << "���ƶ�����" << endl;
	cout << "ƽ������ʱ�䣺" << deque1[0][0] / 10 << endl;
	cout << "�ƶ�����ʱ�䣺" << deque1[0][1] / 10 << endl;
	cout << "��������ʱ�䣺" << deque1[0][2] / 10 << endl;
	cout << "���ƶ�����" << endl;
	cout << "ƽ������ʱ�䣺" << deque1[1][0] / 10 << endl;
	cout << "�ƶ�����ʱ�䣺" << deque1[1][1] / 10 << endl;
	cout << "��������ʱ�䣺" << deque1[1][2] / 10 << endl;
	cout << endl;

	cout << "set" << endl;
	cout << "���ƶ�����" << endl;
	cout << "ƽ������ʱ�䣺" << set1[0][0] / 10 << endl;
	cout << "�ƶ�����ʱ�䣺" << set1[0][1] / 10 << endl;
	cout << "��������ʱ�䣺" << set1[0][2] / 10 << endl;
	cout << "���ƶ�����" << endl;
	cout << "ƽ������ʱ�䣺" << set1[1][0] / 10 << endl;
	cout << "�ƶ�����ʱ�䣺" << set1[1][1] / 10 << endl;
	cout << "��������ʱ�䣺" << set1[1][2] / 10 << endl;
	cout << endl;


	//������deque�ڵڶ���λ�ò���Ԫ��
	//int sum_time1 = 0;//�ֱ��¼ʱ��
	//int sum_time2 = 0;
	//for (int i = 0; i < epoch; i++)
	//{
	//	cout << "��" << i + 1 << "�ֲ��Կ�ʼ" << endl;
	//	cout << "---ʹ���ƶ�����---" << endl;
	//	MA_MyArray<int> ma1(2, 2);//��ʼ��
	//	MA_MyArray<int>ma2(3, 3);
	//	Deq_Move d1{ ma1,ma2 };
	//	sum_time1 += Test_Perfomance2(d1, size, RandomSeed);

	//	cout << "---��ʹ���ƶ�����---" << endl;
	//	MyArray<int> a1(2, 2);//��ʼ��
	//	MyArray<int>a2(3, 3);
	//	Deq_NoMove d2{ a1,a2 };
	//	sum_time2 += Test_Perfomance2(d2, size, RandomSeed);
	//}
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);
	//cout << "ʹ���ƶ����廨��ƽ��ʱ��Ϊ��" << double(sum_time1) / 10 << endl;
	//cout << "��ʹ���ƶ����廨��ƽ��ʱ��Ϊ��" << double(sum_time2) / 10 << endl;
}