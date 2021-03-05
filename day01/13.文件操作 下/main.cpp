#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;


//fseek() 函数
  //文件读写指针  在一个文件内只有一个
  //int fseek()
     //参数1 文件
     //参数2 偏移量(矢量:+ 向后 -向前 )
	 //参数3 SEEK_SET :文件开头位置
	 //参数4 SEEK_CUR :文件当前位置
     //参数4 SEEK_END :文件结尾位置
   //返回值 失败 -1 成功 0

//ftell() 
	//获取文件位置
    //返回:从文件当前读写位置到起始位置的偏移量

    //借助ftell + fseek(SEEK_END);来获取文件大小

//rewind() :回卷文件读写指针  将读写指针移到起始

typedef struct student {
	int age;
	char name[10];
	int num;
}stu_t;
void test01()
{
	stu_t stu[4] = {
		18,"afei",10,
		20,"andy",20,
		30,"lily",30,
		16,"james",40
	};
	stu_t s1;
	FILE *fp = fopen("G:/fopen/tes08.txt", "wb+");
	if (fp == NULL)
	{
		perror("fopen error");
		return;
	}
	fwrite(stu, 1, sizeof(stu), fp);

	fseek(fp, -20*2, SEEK_END);
	

	//cout << "sizeof(stu_t) = " << sizeof(stu_t) << endl;
	fread(&s1, 1, sizeof(s1), fp);
	cout << "age = " << s1.age << " s1.name = " << s1.name << " s1.num = " << s1.num << endl;
	//fseek(fp,0,SEEK_END)
	fclose(fp);
}

//利用fseek() 和 ftell() 来求文件大小
void test02()
{
	FILE *fp = fopen("G:/fopen/tes08.txt", "r");
	if (fp == NULL)
	{
		perror("fopen error");
		return;
	}
	fseek(fp, 0, SEEK_END);//将文件指针移到文件结尾
	int ret = ftell(fp);//计算指针的偏移量
	cout << "ret = " << ret << endl;
	fclose(fp);
}

//打开文件 对于系统而言 系统资源消耗较大
   //int stat (const char *path,struct stat *buf)
    
		//参1:文件访问路径
		//参2:文件属性结构体
		//返回值： 成功： 0， 失败： -1；
void test03()
{
	struct stat buf;
	int ret = stat("G:/fopen/tes08.txt", &buf);
	//传出参数:在函数调用结束时 可以充当返回值
	cout << "文件的大小为: " << buf.st_size << endl;
}

//文件缓冲区
   //缓冲区:内存中的一块区域
      //再一次访问物理磁盘过程中 尽可能获取磁盘数据 保存在内存中
// 屏幕 -- stdout -- stdout缓冲区
// 键盘 -- stdin  -- stdin 缓冲区

//手动刷新缓冲区
//int fflush(FILE *stream);
  //成功 0  失败 -1
int fflush(FILE *stream)
{
	FILE *fp = fopen("G:/fopen/tes08.txt", "r");
	if (fp == NULL)
	{
		perror("fopen error");
		return;
	}
	while(1)
	{
		
	}


	fclose(fp);
}

void test04()
{
	

}
void main()
{
	//test01();
	//test02();
	test03();
	system("pause");
}