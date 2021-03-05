#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//printf -- 
//sprintf -- 
//fprintf --

//系统文件
	//标准输入 stdin -- 0
	//标准输出 stdout -- 1
	//标准错误 stderr -- 2
void test01()
{
	FILE *fp = fopen("G:/fopen/test01.txt","w+");
	char *buf = "liwenweizuishuai";
	if (fp == NULL)
	{
		perror("fopen error");// -- 屏幕 --标准错误
		return;
	}
	int ret = fputs(buf, fp);
	//文件的结束标记 EOF
	//cout << "ret = " << ret << endl;
	fclose(fp);
}

void test02()
{
	FILE *fp = fopen("G:/fopen/test01.txt", "r");
	char *ch = (char *)malloc(sizeof(char) * 1024);
	memset(ch, 0, 1024);
	if (fp == NULL)
	{
		perror("fopen error");// -- 屏幕 --标准错误
		return;
	}
	fgets(ch, 1024, fp); 
    cout << "ch = " << ch << endl;
	if (ch == NULL)
	{
		free(ch);
		ch = NULL;
	}
	fclose(fp);
}
//foef //判断是否到达文件结尾

//将用户输入的数据 写入文件中
void test03()
{
	FILE *fp = fopen("G:/fopen/test02.txt", "w");
	if (fp == NULL)
	{
		perror("fopen error");// -- 屏幕 --标准错误
		return;
	}
	char buf[4096];
	while (1)
	{
		fgets(buf, 4096, stdin);
		if (strncmp(buf,":wq",3) == 0)
		{
			break;
		}
		fputs(buf, fp);
	}

	fclose(fp);
}

void main()
{
	//test01();
	//test02();
	test03();
	system("pause");
}

