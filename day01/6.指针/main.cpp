#include <iostream>
using namespace std;

//指针:地址
//指针变量:存地址的变量
//指针的大小与类型无关 至于当前使用平台架构有关。 
//32位 4字节     64位8字节
//野指针 没有有效的地址空间的指针

//野指针的测试
void test01()
{
	int i = 20;
	int *p = new int;//在堆区开辟一个内存空间 将地址存入到p中
	*p = 200;
	cout << *p << endl;
	cout << p << endl;
	cout << &p << endl;
	delete p;
	p = NULL;

	p = &i;
	cout << *p << endl;
	cout << p << endl;
	cout << &p << endl;
	cout << &i << endl;

	//int *q = 10;//0-255 确定留给操作系统  
}


//泛型指针/万能指针 void *p
void test02() // 可以接收任意一种变量地址 但是 在使用时必须借助强转
{
	int a = 345;
	void  *p;//万能指针 
	p = &a;
	cout << *((int *)p) << endl;
}

//指针和数组
  //数组名 -- 地址常量 不可以被修改
  //指针是变量 所以可以用数组名赋值
void test03()
{
	//a[0]  == *(a + 0) 
	//a[1]  == *(a + 1)
	int a[] = { 0,1,2,3,4 };
	int *p = a;
	cout << "a[2] = " << *(p + 2) << endl;
}

//const修饰指针
void test04()
{
	int i = 20;
	int j = 30;
	const int *p = &i; //可以修改指针的指向 但不能直接修改指针的值 *p
	cout << "*p = " << *p << endl;
	p = &j;
	cout << "*p = " << *p << endl;
	j = 50;
	cout << "*p = " << *p << endl;


	int *const q = &j;//可以直接修改指针的值*p	但不能修改指针的指向
	//q = &i;
	*q = 20;

	const int *const n = &i;//
}

//指针与数组的区别
void test05()
{
	int a[] = { 0,1,2,3,4 };
	int *p = a;
	cout << "p自增前" << endl;
	cout << p << endl;
	cout << &p << endl;
	
	p++;
	cout << "p自增后" << endl;
	cout << *p << endl;
	cout << p << endl;
	cout << &p << endl;
}

//指针的加减运算
void test06()
{
	//数据类型对指针的作用： 
	    //决定了从指针存储的地址开始

}

//面试题之一
//对数组而言 指针 - 指针 = 偏移过的元素个数
void test07()
{
	int a[3] = { 1,2,6 };
	int *q = &a[2];
	int *p = a;
	int x = q - p;//     q-p/sizeof(int)
	cout << x << endl;
	cout << a[q - p] << endl;

}
//指针数组  1
   //一个存储地址的数组 数组内部所有元素都是地址
  //指针数组的本质是一个二级指针
void test08()
{
	int a = 10;
	int b = 20;
	int c = 30;

	int *p1 = &a;
	int *p2 = &b;
	int *p3 = &c;

	int *arr[] = {p1,p2,p3 };

	cout <<"*(arr[0] = ) "<<*arr[0] << endl;  
	cout << "*(*(arr + 1)) = " << *(*(arr + 1)) << endl;  // = *arr[1] = b =20


	cout << &arr[0] << endl;
	cout << &arr[1] << endl;
}

//指针数组 2
void test09()
{
	int a[] = { 10,80 };
	int b[] = { 20 ,30};
	int c[] = { 30 };

	int *arr[] = { a,b,c };
	cout << *(arr + 1)[1] << endl;
	cout << "arr[1] = " << *(*arr + 1);
}

// 一级指针是变量的地址
  //二级指针 是一级指针的地址

void test10()
{
	int a[] = { 1,2,3,4,5,6 };
	cout << "a = " << a << endl;
	cout << "a + 1 = " << a + 1 << endl;
	cout << "&a = " << &a << endl;
	cout << "&a +1 = " << &a + 1 << endl;
	cout << "sizeof(a) = " << sizeof(a) << endl;
}
void main()
{
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();

	//test07();
	//test08();
	test09();
	//test10();
	system("pause");
}
