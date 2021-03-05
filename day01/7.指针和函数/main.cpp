#include <iostream>

using namespace std;

//栈帧:  当函数调用时 系统会在stack 空间上申请一块内存区域 用来功函数调用
  //主要存放形参和局部变量  。当函数调用结束 这块区域自动被被释放

//传值和传址:

//实参地址传值
void swap(int *a,int *b)
{
	int temp = 0;
	temp = *a;
	*a = *b;
	*b = temp;
}
void test01()
{
	int a = 10;
	int b = 20;
	swap(&a, &b);
	cout << "a = " << a << "  b = " << b << endl;
}


//二维指针做输出修改 一维指针的值
void  retu(char ** a)
{
	*a = "liw";
}
void test02()
{
	char *ch = "lww";
	retu(&ch);
	cout << "ch = " << ch << endl;
}


//数组做函数参数
  //传递的不再是整个数组 而是数组的首地址(一个指针的大小)
void arrmain(char a[])
{
	cout << "a = " << a << endl;
}
void test03()
{
	char *ch = "liwenwei";
	arrmain(ch);
}

//字符串的拼接  strcat
void test04()
{	
	char *str1 = "li";
	char *str2 = "wenwei";
	char *str3 = new char[strlen(str1) + strlen(str2) + 1];
	memset(str3, 0, strlen(str1) + strlen(str2) + 1);
	int q = strlen(str3);
	if (str3 == NULL)
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
}

//字符串比较大小 strcmp
  //strcmp(ch1,ch2) 
  //返回值是1 ch1 > ch2
  //返回值是0 ch1 = ch2
  //返回值是-1 ch1 < ch2
  //strncmp(ch1,ch2,count) 比较ch1 ch2 前n个字符
void test05()
{
	char *str = "hallo";
	char *ch = "hello";
	int x = strcmp(str, ch);
	cout << "x = " << x << endl;
}

//字符串拷贝 strcpy 
 //二级指针做函数输出
void supplychar(char *a,char **b)
{
	char *temp = new char[strlen(a) + 1];
	*b = temp;
	//strcpy(temp, a);//不安全
	strncpy(temp, a, strlen(a) + 1);
}
void test07()
{
	char *a = "liwenwei";
	char *b = NULL;
	supplychar(a, &b);
	cout << "b = " << b << endl;
	delete[] b;
	b = NULL;
}

//去除字符串空格
void test08()
{
	char *str = "liwenwei zuishuai";


}

//strstr 函数 :在str中 找substr出现的位置
 //char *strstr(char *str,char *substr)  返回值第一次出现substr的位置 
void test09()
{
	char *str = "li";
	char *substr = "wen";
	int count = 0;
	while(char *pos = strstr(str, substr))
	{
		count++;
		if (strlen(pos) >= strlen(substr))
		{
			str = pos + strlen(substr);
		}
		else
		{
			break;
		}
	}
	cout << "count = " << count << endl;
	//cout << "pos = " << pos << endl;
}
//指针和字符串的区别
void test06()
{
	/*char str1[] = "hello";
	char *str2 = "hello";
	*(str2+1)= 'R';*/

	char str1[] = { 'h','i' };  //不会在后面自动添加 '\0 '
	char str2[] = "hi";   //会在后面自动添加 '\0 '
	char *str3 = "hello";  //hello是一个字符串常量 不可以随意修改

	cout << "sizeof(str1) = " << sizeof(str1) << endl; //2
	cout << "sizeof(str2)" << sizeof(str2) << endl; //3
	//cout << "sizeof(str3)" << sizeof(str3) << endl; //指针的大小 四个字节
}


void main()
{
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	//test06();
	test07();
	//test09();
	system("pause");
}