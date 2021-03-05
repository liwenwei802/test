#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#define li 23 //define 出的宏常量 没有数据类型 不重视作用域
//变量声明不会开辟内存空间
const int wen = 25;
void main()
{
	/*
	 int a, b, c;
	 putchar('a');
	 putchar('\n');
	
	 scanf("%d %d %d", &a, &b, &c);
	 cout << "a = " << a << " b = " << b << " c = " << c << endl;
	 char e[20];
	 scanf("%s", e);
	 cout << "e = " << e << endl;

	 rewind(stdin);
	 char ch;
	 ch = getchar();
	 putchar(ch);
	 putchar('\n');
	 char ch2;
	 ch2 = getchar();
	 cout << "ch2 = " << " ";
	 putchar(ch2);
	 putchar('\n');
	 rewind(stdin);
	 char ch3;
	 ch3 = getchar();
	 cout << "ch3 = " << " ";
	 putchar(ch3);
	 putchar('\n');
	 */
	char ch;
	ch = getchar();
	printf("%c\n", ch);
	system("pause");
	while ((ch = getchar()) != '\n')
	{
		printf("%c", ch);
	}
	printf("\n");
	 system("pause");



}