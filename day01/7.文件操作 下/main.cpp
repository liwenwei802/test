#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <time.h>
using namespace std;


//printf() -- sprintf() -- fprintf()
//scanf()  -- sscanf()  -- fscanf()

//fprintf
void test01()
{
	FILE *fp = fopen("G:/fopen/tes03.txt", "w+");
	if (fp == NULL)
	{
		perror("fopen error");
		return;
	}
	printf("%d%c%d=%d\n", 10, '*', 7, 10 * 7);
	fprintf(fp, "%d%c%d=%d\n", 10, '*', 7, 10 * 7);
	fclose(fp);
}

void test02()
{
	FILE *fp = fopen("G:/fopen/tes04.txt", "w");
	if (fp == NULL)
	{
		perror("fopen error");
		return;
	}
	fputs("6\n",fp);
	fputs("7\n",fp);
	fputs("8\n",fp);
	fputs("\n",fp);
	fputs("\n",fp);
	fputs("\n",fp);

	fclose(fp);
}

void test03()
{
	FILE *fp = fopen("G:/fopen/tes04.txt", "r");
	int a;
	if (fp == NULL)
	{
		perror("fopen error");
		return;
	}
	while (true)
	{
		fscanf(fp, "%d\n", &a);
		printf("%d\n", a);
		if (feof(fp))
		{
			break;
		}
		
	}
	fclose(fp);
}

void test04()
{
	FILE *fp = fopen("G:/fopen/tes04.txt", "r");
	int a;
	if (fp == NULL)
	{
		perror("fopen error");
		return;
	}
	while (true)
	{
		char buf[1024];
		fgets(buf, 3, fp);
		
		if (feof(fp))
		{
			break;
		}
		cout << buf;
	}
	fclose(fp);
}

//文件排序
void test05()
{
	FILE *fp = fopen("G:/fopen/tes05.txt", "w+");
	if (fp == NULL)
	{
		perror("fopen error");
		return;
	}
	//随机数种子
	srand(time(NULL));

	//循环生成随机数 放入文件中
	for (int i = 0 ;i < 10;i++)
	{
		fprintf(fp, "%d\n", rand() % 100);
	}
	fclose(fp);
}

void arrSort(int *arr)
{
	for (int i = 0; i < 10; i++)
		for (int j = i + 1; j <10; j++)
		{
			if (arr[i] > arr[j])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
}

void test06()
{
	FILE *fp = fopen("G:/fopen/tes05.txt", "r");
	int arr[10];
	int i = 0;
	if (fp == NULL)
	{
		perror("fopen error");
		return;
	}
	while (true)
	{
		fscanf(fp, "%d\n", &arr[i]);
		i++;
		if (feof(fp))
		{
			break;
		}
	}
	arrSort(arr);
	fclose(fp);
	fp = fopen("G:/fopen/tes05.txt", "w+");
	for (i = 0;i < 10;i++)
	{
		fprintf(fp, "%d\n", arr[i]);
	}
	fclose(fp);
}

//fgets -- fputs 
//fgetc -- fputc
//fprintf -- fscanf   默认处理文本文件

//fwrite() 
//fread() 函数 用来处理二进制文件

//size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream);
//写数据到文件中
    //参1：待写出的数据的地址
	//参2：待写出数据的大小
	//参3：写出的次数		-- 参2 x 参3 = 写出数据的总大小。
	//参4：文件
	//返回值： 成功：永远是 参3 的值。
	//-- - 通常将参2 传 1. 将参3传实际写出字节数。
	//失败：0

//fread()函数： 从文件fp中读出数据。
//size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
	//参1：读取到的数据存储的位置
	//参2：一次读取的字节数
	//参3：读取的次数				-- 参2 x 参3 = 读出数据的总大小
	//参4：文件
	//返回值： 成功：参数3.	-- - 通常将参2 传 1. 将参3传欲读出的字节数。
	//0：读失败 -- 到达文件结尾 -- feof(fp)为真。

typedef struct student{
	int age;
	char name[10];
	int num;
}stu_t;
void test07()//fwrite()函数
{
	stu_t stu[4] = {
		18,"afei",10,
		20,"andy",20,
		30,"lily",30,
		16,"james",40
	};
	FILE *fp = fopen("G:/fopen/tes06.txt", "w+");
	if (fp == NULL)
	{
		perror("fopen error");
		return;
	}

	int ret = fwrite(stu, 1, sizeof(stu_t) * 4, fp);
	if (ret == 0)
	{
		perror("fwrite error");
		return;
	}
	fclose(fp);
}

void test08()//fread()函数
{
	FILE *fp = fopen("G:/fopen/tes06.txt", "r");
	if (fp == NULL)
	{
		perror("fopen error");
		return;
	}
	stu_t buf[4];
	int ret = fread(buf, sizeof(stu_t), 4, fp);
	cout << "ret = " << ret << endl;
	for (int i =0 ;i < 4;i++)
	{
		cout << "buf["<<i<<"].age = "<<buf[i].age << " ";
		cout << "buf[" << i << "].name = " << buf[i].name << " ";
		cout << "buf[" << i << "].num = " << buf[i].num << endl;
	}
	fclose(fp);
}

//大文件拷贝  
//已知一个任意类型的文件 对该文件赋值 产生一个相同的新文件
  //1 打开两个文件 一个"r" 另一个"w"
  //2 从r中 fread  fwrite到w文件中
  //3 判断到达文件结尾 终止
  //4 关闭

void test09()
{
	FILE *fp = fopen("G:/fopen/tes07.txt", "r");
	char buf[1024];
	if (fp == NULL)
	{
		perror("fopen error");
		return;
	}
	FILE *fp2 = fopen("G:/fopen/tescp.txt", "w");
	if (fp2 == NULL)
	{
		perror("fopen error");
		return;
	}
	while (true)
	{
		fgets(buf, 1024, fp);
		if (feof(fp))
		{
			break;
		}
		fputs(buf, fp2);
	}
	fclose(fp);
	fclose(fp2);
}
void test10()
{
	FILE *fp = fopen("G:/fopen/guohuo.mp3", "rb");
	char buf[1024];
	if (fp == NULL)
	{
		perror("fopen error");
		return;
	}
	FILE *fp2 = fopen("G:/fopen/guohuocp.mp3", "wb");
	if (fp2 == NULL)
	{
		perror("fopen error");
		return;
	}
	while (true)
	{
		int ret = fread(buf, 1, sizeof(buf), fp);
		if (ret == 0)
		{
			break;
		}
		fwrite(buf, 1, ret, fp2);
	}
	fclose(fp);
	fclose(fp2);
}

void test11()
{
	int buf[1024] = { 0 };
	cout << "sizeof(buf) = " << sizeof(buf) << endl;

}
void main()
{
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	//getchar();//为了看清文件前后的数据
	//test06();

	//test07();
	//test08();
	//test09();
	//test10();
	test11();
	system("pause");
}