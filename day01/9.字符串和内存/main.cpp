#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <iostream>
using namespace std;

//判断回文字符串  字符串正着读和倒着读都一样
void test01()
{
	char *str = "heloeh";
	char *start = str;
	char *end = str + strlen(str) - 1;
	while (end > start)
	{
		if ((*end) == (*start) )
		{
			end--;
			start++;
		}
		else
		{
			cout << "字符串不是回文字符串" << endl;
			break;
		}
	}
	if (end <= start)
	{
		cout << "字符串是回文字符串" << endl;
	}
}
//字符串格式化输入 输出
void test02()
{
	char buf[100] = { 0 };
	sprintf(buf, "%d%c%d=%d", 10, '+', 34, 10 + 34);
	puts(buf);
	int a;
	char buf2[100] = { 0 };
	sscanf("2", "%d", &a);
	cout << "a = " << a << endl;
}

//在字符串str中 找一个字符出现的位置 返回字符在字符串中的地址
	//char *strchr(const char *s,int c)
void test03()
{
	char *str = "liwenwei";
	char *ch = strchr(str, 'w');

	cout << " *ch = " << *ch << endl;
}
// 在字符串str中 自右往左找一个字符出现的位置 返回字符在字符串中的地址
//char *strrchr(const char *s,int c)
void test04()
{
	char *str = "liwenwei";
	char *ch = strrchr(str, 'w');

	cout << " ch = " << ch << endl;
}

//正则表达式 scanf("%[^\n]",str);//接收除换行符外的所有字符


//字符串分割函数 strtok  按照既定的分隔符拆分字符串
  //返回字符串拆分后的首地址 "拆分":将分隔符用 '\0' 
   //第一次拆分 参数1 传 待拆分的原串 
   //第 1+次拆分时 参1传 NULL值 
void test05()
{
	char str[] = "www.brp59.com";
	char *p = strtok(str, ".");
	if (p == NULL)
	{
		cout << "分割失败" << endl;
	}
	cout << "p = " << p << endl;

	p = strtok(NULL, ".");
	cout << "p = " << p << endl;
}

//atoi 字符串 转整数
//auof 字符串转浮点数
//auol 字符串转长整数

void test06()
{
	char *str = "1.25";
	int x = atoi(str);
	float y = atof(str);
	long int z = atol(str);
	cout << "x = " << x << " y = " << y << " z = " << z << endl;

	cout << "sizeof(float) = " << sizeof(float) << endl;
	cout << "sizeof(double) = " << sizeof(double) << endl;
}
void main()
{
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	test06();
	system("pause");
}