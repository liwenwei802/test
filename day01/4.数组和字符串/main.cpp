#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string.h>
#include <time.h>
using namespace std;
void main()
{
	//相同数据类型的有序集合
	int arr[] = { 1,2,3 };
	printf("&arr[0] = %p\n", &arr[0]);//取数组首元素的地址

	printf("arr = %p\n", arr);//取数组地址   

	cout << "sizeof(arr) = " << sizeof(arr) << endl;
	cout << "sizeof(arr[0] = )" << sizeof(arr[0]) << endl;
	cout << "数组的元素个数 = " << sizeof(arr) / sizeof(arr[0]) << endl;

	//数组名为地址 arr = &arr[0]

	//数组初始化

	//二维数组的大小
	int arr2[][3] = { {1,2,3},{ 4,5 } };
	cout << "二维数组的大小为 :" << sizeof(arr2) << endl;
	//一行元素大小
	cout << "一行元素大小为 ：" << sizeof(arr2[0]) / sizeof(arr2[0][0]) << endl;

	char ch[6] = { 'h','e','l','l','0'};
	char ch2[] = "hello world";
	int x = sizeof(ch);
	int y = sizeof(ch2);
	cout << "x = " << x << " y = " << y << endl;
	cout << ch2 << endl;

	cout << "我要开始获取字符串了" << endl;
	char *s =NULL;
	s = new char[10];
	if (s == NULL)
	{
		cout << "申请空间失败" << endl;
		return;
	}
	strcpy(s, ch);
	cout << "s = " << s << endl;
	int m = sizeof(s);

	cout << "m =  " << m << endl;
	//s = (char *)malloc(sizeof(char) * 10);
    //gets(s);//从键盘获取一个字符串， 返回字符串的首地址

	char *str = new char[20];
	fgets(str, 20, stdin);
	cout << "str = " << str << endl;
	cout << "put函数的输出 " << endl;
	puts(str);
	rewind(stdin);
	char li = getchar();
	cout << "li = " << li << endl;

	fputs(str, stdout);
	delete[] str;
	delete[] s;

	//字符串的拼接
	char *str1 = "li";
	char *str2 = "wenwei";
	char *str3 = new char[strlen(str1) + strlen(str2) + 1];
	memset(str3, 0, strlen(str1) + strlen(str2) + 1);
	int q = strlen(str3);
	if(str3 == NULL)
	{
		cout << "内存空间申请失败" << endl;
		return;
	}
	int h = strlen(str1) + strlen(str2);
	strcat(str3, str1);
	strcat(str3, str2);
	//strcat(str3, '\0');
	cout << "拼接后的str3为" << endl;
	cout << "str3 = " << str3 << endl;
	time_t  Time;
	time(&Time);
	cout << Time << endl;

	system("pause");
}