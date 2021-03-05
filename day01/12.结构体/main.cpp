#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//传参 数据的封装
  // 关键字 struct 代表这是一个结构体类型
  // stu 是结构体的名字
  //整个结构体的类型是 struct stu


//共用体和联合体
typedef  union test
{
	char ch;
	short sh;
	int var;
	double m;
}test;//联合体 内部所有成员变量地址一致 等同于整个联合体的地址
  //联合体的大小 是内部成员变量中 最大的那个成员变量的大小
  //修改其中任意一个成员变量的值 其他成员变量会随之修改 

void test01()
{
	test obj;
	cout << "sizeof(obj) = " << sizeof(obj) << endl;
	printf("&obj.ch = %p\n", &obj.ch);
	cout << "&obj = " << &obj << endl;
	cout << "&obj.var = " << &obj.var << endl;
}

//枚举
// enum color{枚举常量}; 枚举常量 不能是浮点数 可以是负值 
//默认初值从0开始 后续常量较前一个常量加1
//enum color{red,green,blue,black};

enum color { red, green, blue, black };
void test02()
{
	int flag = 2;
	if (flag == blue)
	{
		cout << "nb" << endl;
	}
}

//结构体 复合型
//结构struct stu它只是一个类型 一个模板 没有空间 不可以给结构体成员赋值 
typedef  struct student 
{
	int id;
	int age;
	char name[128];	
}stu_t;

void test03() //结构体
{
	int x = sizeof(stu_t);
	cout << "x = " << x << endl;
}
//结构体数组
  
void test04()
{
	stu_t *stu = (stu_t *)malloc(sizeof(stu_t) * 4);
	if (stu == NULL)
	{
		cout << "空间申请失败" << endl;
		return;
	}
	if (stu != NULL)
	{
		free(stu);
		stu = NULL;
	}
}

//结构体套结构体
typedef struct tcu_stu
{
	stu_t s1;
	char subject[128];
}t_stu;
void test05()
{
	t_stu s2 ={{12,22,"liwenwei"},"shuxue"};
	//strcpy(s2.s1.name , "hello");
	cout << "s2.s1.name = " << s2.s1.name << endl;
}


typedef  struct 
{
	int id;
	int age;
	char name[128];
	char *School;
}tc_stu;
//结构体套指针
void test06()
{
	tc_stu *stu =(tc_stu *)malloc(sizeof(tc_stu) * 4);
	if (stu == NULL)
	{
		cout << "空间申请失败" << endl;
		return;
	}

	for (int i = 0;i < 4;i++)
	{
		stu[i].School = (char *)malloc(sizeof(char) * 20);
		if (stu[i].School == NULL)
		{
			cout << "stu[" << i << "]的" << "School空间申请失败" << endl;
			return;
		}
		strcpy(stu[i].School, "hello");
		//stu[i].School = "hello";//不能改变堆空间指针的指向
	}

	for (int i = 0; i < 4; i++)
	{
		cout << "stu[" << i << "].School = " << stu[i].School << endl;
	}

	for (int i = 0;i < 4;i++)
	{
		if (stu[i].School != NULL)
		{
			free(stu[i].School);
			stu[i].School = NULL;
		}
	}
}

typedef struct a_tea
{
	int a;
}a_t;

typedef struct tea
{
	int id;
	char *p;
	a_t *b;
}t;

void Relese(t *tmp)
{
	if (tmp->b != NULL)
	{
		free(tmp->b);
		tmp->b = NULL;
	}
	if (tmp->p != NULL)
	{
		free(tmp->p);
		tmp->p = NULL;
	}
	if (tmp != NULL)
	{
		free(tmp);
		tmp = NULL;
	}
}
void test07()
{
	t *tmp = (t *)malloc(sizeof(t));
	if (tmp == NULL)
	{
		return;
	}
	tmp->id = 100;
	tmp->p = (char *)malloc(128);
	strcpy(tmp->p, "hello");
	tmp->b = (a_t *)malloc(sizeof(a_t));
	tmp->b->a = 120;

	cout << "tmp->id = " << tmp->id << endl;
	cout << "tmp->p = " << tmp->p << endl;
	cout << "tmp->d->a = " << tmp->b->a << endl;
	Relese(tmp);
	tmp = NULL;
}


void main()
{
	//test01();
	//cout << "sizeof(student) = " << sizeof(student) << endl;
	//stu_t s1 = { 12,22,"liwenwei" }, s2 = { 13,21,"lxh" };
	
	//s1.name = "liwenwei";//因为数组名是常量 所以不能直接赋值
	//strcpy(s1.name, "liwenwei");

	//cout << "s1.name = " << s1.name << endl;
	//test02();
	//test03();
	//test04();
	//test05();
	//test06();
	test07();
	system("pause");
}