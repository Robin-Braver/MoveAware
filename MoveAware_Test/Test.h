#pragma once
#include"MA_MyArray.h"
#include"MyArray.h"

using MA = MA_MyArray<int>;
using NoMA = MyArray<int>;

//测试移动语义性能函数
template<typename Container>
int* Test_Perfomance(Container Con0, size_t size,int Randseed)//Con:容器，size：移动规模,RandSeed:随机数种子
{
	typedef typename iterator_traits<typename Container::iterator>::value_type Val_type;//获取容器值类型
	srand(Randseed);//随机数种子
	size_t insert_num = 0;//需要插入的数字
	int time[3];//便于数据处理，记录时间
	/*插入到目的容器*/
	clock_t begin1 = clock();
	for (size_t i = 0; i < size; ++i)
	{
		insert_num = rand() % 100+1;//生成1-100的随机数
		Val_type array(insert_num, i);//插入之前产生的随机个数个数字
		auto iter = Con0.end();//获取尾部迭代器
		Con0.insert(iter, Val_type(array));//在尾部插入array,且是右值插入
	}
	clock_t end1 = clock();
	time[0] = end1 - begin1;

	cout << "插入规模：" << Con0.size() << endl;
	cout << "插入花费：" << end1 - begin1 << "ms" << endl;

	/*测试使用移动语义*/
	clock_t begin2 = clock();
	Container Con1_MA(move(Con0));//移动构造
	clock_t end2 = clock();
	time[1] = end2 - begin2;

	cout << "移动构造（带移动语义）花费：" << end2 - begin2 << "ms" << endl;

	/*测试不使用移动语义*/
	clock_t begin3 = clock();
	Container Con2_NoMA(Con1_MA);//拷贝构造
	clock_t end3 = clock();
	time[2] = end3 - begin3;
	cout << "拷贝构造（不带移动语义）花费：" << end3 - begin3 << "ms" << endl;
	return time;
}


template<typename Container>
int Test_Perfomance2(Container Con0, size_t size, int Randseed)//Con:容器，size：移动规模,RandSeed:随机数种子
{
	typedef typename iterator_traits<typename Container::iterator>::value_type Val_type;//获取容器值类型
	srand(Randseed);//随机数种子
	size_t insert_num = 0;//需要插入的数字

	/*插入到目的容器*/
	clock_t begin1 = clock();
	for (size_t i = 0; i < size; ++i)
	{
		insert_num = rand() % 100 + 1;//生成1-100的随机数
		Val_type array(insert_num, i);//插入之前产生的随机个数个数字
		auto iter = Con0.begin();//获取首部迭代器
		//iter++;
		Con0.insert(iter, Val_type(array));//在尾部插入array,且是右值插入
	}
	clock_t end1 = clock();


	cout << "插入规模：" << Con0.size() << endl;
	cout << "插入花费：" << end1 - begin1 << "ms" << endl;
	return (end1 - begin1);
}



