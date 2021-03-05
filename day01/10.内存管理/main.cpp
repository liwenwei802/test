#include <iostream>
using namespace std;

//生命周期
  //1 局部变量: 从变量定义开始 函数调用完成 -- 函数内部
  //2 全局变量:程序启动（在main函数之前） ，程序终止结束。 -- 程序执行期间
  //3 static局部变量:程序启动（在main函数之前） ，程序终止结束。 -- 程序执行期间
  //4 static 全局变量 : 程序启动（在main函数之前） ，程序终止结束。 -- 程序执行期间
  
//“变量定义:用于为变量分配存储空间,还可为变量指定初始值。
//程序中,变量有且仅有一个定义。 
//变量声明:用于向程序表明变量的类型和名字

//局部变量 
//作用域 :从包裹该变量的第一个有大括号结束 
void test01()
{
	{
		int a = 10;//仅在括号内起作用
	}
}

//static 局部变量
void test02()
{
	static int a = 20;

}

//二级指针所指向的堆空间
//p[i][j] = *(p + i)[j] == *(*(p + i) + j)
void test03()
{
	char **p = (char **)malloc(sizeof(char *) * 5);
	if (p == NULL)
	{
		cout << "二级指针空间申请失败" << endl;
		return;
	}
	for (int i = 0;i < 5;i++)
	{
		p[i] = (char*)malloc(sizeof(char) * 100);
		if (p[i] == NULL)
		{
			cout << "空间申请失败" << endl;
			return;
		}
		memset(p[i], 0, sizeof(char) * 100);
	}
	//释放空间 
	for(int i = 0 ;i < 5;i++)
	{
		if (p[i])
		{
			free(p[i]);
			p[i] = NULL;
		}
	}
	if (p != NULL)
	{
		free(p);
		p = NULL;
	}
}

void main()
{
	
	test03();
	system("pause");
}