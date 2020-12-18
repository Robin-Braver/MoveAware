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
	//test.insert(iter, 2);//在第二个位置插入
	//iter = test.begin();//重新获取地址
	//cout << &(*iter) << endl;


	//数据处理的相关数组
	int vector1[2][3] = { 0,0,0,0,0,0 };
	int list1[2][3] = { 0,0,0,0,0,0 }; 
	int deque1[2][3] = { 0,0,0,0,0,0 }; 
	int set1[2][3] = { 0, 0, 0, 0, 0, 0 };
	for (int i = 0; i < epoch; ++i)
	{
		int* temp;
		cout << "第" << i + 1 << "轮测试开始" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);
		cout << "---****【TEST1】:Vector****---" << endl;
		cout << "---使用移动语义---" << endl;
		Vec_Move vec1;
		temp = Test_Perfomance(vec1, size, RandomSeed);
		for (int i = 0; i < 3; ++i)//累积时间
			vector1[0][i] += *(temp + i);

		cout << "---不使用移动语义---" << endl;
		Vec_NoMove vec2;
		temp = Test_Perfomance(vec2, size, RandomSeed);
		for (int i = 0; i < 3; ++i)//累积时间
			vector1[1][i] += *(temp + i);

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
		cout << "---****【TEST2】:List****---" << endl;
		cout << "---使用移动语义---" << endl;
		Lst_Move Lst1;
		temp = Test_Perfomance(Lst1, size, RandomSeed);
		for (int i = 0; i < 3; ++i)//累积时间
			list1[0][i] += *(temp + i);

		cout << "---不使用移动语义---" << endl;
		Lst_NoMove Lst2;
		temp = Test_Perfomance(Lst2, size, RandomSeed);
		for (int i = 0; i < 3; ++i)//累积时间
			list1[1][i] += *(temp + i);

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
		cout << "---****【TEST3】:Deque****---" << endl;
		cout << "---使用移动语义---" << endl;
		Deq_Move deq1;
		temp = Test_Perfomance(deq1, size, RandomSeed);
		for (int i = 0; i < 3; ++i)//累积时间
			deque1[0][i] += *(temp + i);

		cout << "---不使用移动语义---" << endl;
		Deq_NoMove deq2;
		temp = Test_Perfomance(deq2, size, RandomSeed); 
		for (int i = 0; i < 3; ++i)//累积时间
			deque1[1][i] += *(temp + i);

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
		cout << "---****【TEST4】:Set****---" << endl;
		cout << "---使用移动语义---" << endl;
		Set_Move S1;
		temp = Test_Perfomance(S1, size, RandomSeed);
		for (int i = 0; i < 3; ++i)//累积时间
			set1[0][i] += *(temp + i);

		cout << "---不使用移动语义---" << endl;
		Set_NoMove S2;
		temp = Test_Perfomance<Set_NoMove>(S2, size, RandomSeed);
		for (int i = 0; i < 3; ++i)//累积时间
			set1[1][i] += *(temp + i);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	}
	cout << "数据规模：" << size << endl;
	cout << "vector" << endl;
	cout << "有移动语义" << endl;
	cout << "平均插入时间：" << vector1[0][0]/10 << endl;
	cout << "移动构造时间：" << vector1[0][1]/10 << endl;
	cout << "拷贝构造时间：" << vector1[0][2]/10 << endl;
	cout << "无移动语义" << endl;
	cout << "平均插入时间：" << vector1[1][0]/10 << endl;
	cout << "移动构造时间：" << vector1[1][1]/10 << endl;
	cout << "拷贝构造时间：" << vector1[1][2]/10 << endl;
	cout << endl;

	cout << "list" << endl;
	cout << "有移动语义" << endl;
	cout << "平均插入时间：" << list1[0][0] / 10 << endl;
	cout << "移动构造时间：" << list1[0][1] / 10 << endl;
	cout << "拷贝构造时间：" << list1[0][2] / 10 << endl;
	cout << "无移动语义" << endl;
	cout << "平均插入时间：" << list1[1][0] / 10 << endl;
	cout << "移动构造时间：" << list1[1][1] / 10 << endl;
	cout << "拷贝构造时间：" << list1[1][2] / 10 << endl;
	cout << endl;

	cout << "deque" << endl;
	cout << "有移动语义" << endl;
	cout << "平均插入时间：" << deque1[0][0] / 10 << endl;
	cout << "移动构造时间：" << deque1[0][1] / 10 << endl;
	cout << "拷贝构造时间：" << deque1[0][2] / 10 << endl;
	cout << "无移动语义" << endl;
	cout << "平均插入时间：" << deque1[1][0] / 10 << endl;
	cout << "移动构造时间：" << deque1[1][1] / 10 << endl;
	cout << "拷贝构造时间：" << deque1[1][2] / 10 << endl;
	cout << endl;

	cout << "set" << endl;
	cout << "有移动语义" << endl;
	cout << "平均插入时间：" << set1[0][0] / 10 << endl;
	cout << "移动构造时间：" << set1[0][1] / 10 << endl;
	cout << "拷贝构造时间：" << set1[0][2] / 10 << endl;
	cout << "无移动语义" << endl;
	cout << "平均插入时间：" << set1[1][0] / 10 << endl;
	cout << "移动构造时间：" << set1[1][1] / 10 << endl;
	cout << "拷贝构造时间：" << set1[1][2] / 10 << endl;
	cout << endl;


	//测试用deque在第二个位置插入元素
	//int sum_time1 = 0;//分别记录时间
	//int sum_time2 = 0;
	//for (int i = 0; i < epoch; i++)
	//{
	//	cout << "第" << i + 1 << "轮测试开始" << endl;
	//	cout << "---使用移动语义---" << endl;
	//	MA_MyArray<int> ma1(2, 2);//初始化
	//	MA_MyArray<int>ma2(3, 3);
	//	Deq_Move d1{ ma1,ma2 };
	//	sum_time1 += Test_Perfomance2(d1, size, RandomSeed);

	//	cout << "---不使用移动语义---" << endl;
	//	MyArray<int> a1(2, 2);//初始化
	//	MyArray<int>a2(3, 3);
	//	Deq_NoMove d2{ a1,a2 };
	//	sum_time2 += Test_Perfomance2(d2, size, RandomSeed);
	//}
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);
	//cout << "使用移动语义花费平均时间为：" << double(sum_time1) / 10 << endl;
	//cout << "不使用移动语义花费平均时间为：" << double(sum_time2) / 10 << endl;
}