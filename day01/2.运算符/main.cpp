#include<iostream>
using namespace std;

void main()
{
	//逗号运算符
	int a = 10, b= 20, c = 30;
	int x = (a = 1, b = 2, c = 3);
	cout << "x = " << x << endl;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;

	//三目运算符
	//表达式1 ？表达式2 ：表达式3
	//表达式1 是一个判别表达式 如果为真。整个三目运算 取值表达式2
	//						   如果为假。整个三目运算 取值表达式3
	int m = a > b ? 69 : a < b ? 3 : 5;
	cout << "m = " << m << endl;


	system("pause");
}