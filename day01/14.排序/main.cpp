#include <iostream> 
#include <time.h>
using namespace std;


void arrSort(int *arr)
{
	for (int i = 0;i < 10;i++ )
		for(int j = i +1 ; j <10;j++)
		{
			if (arr[i] > arr[j])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
}
void test01()
{
	srand(time(NULL));
	int *arr = (int *)malloc(sizeof(int) * 10);
	for (int i = 0;i < 10;i++)
	{
		*(arr + i) = rand() % 100;
	}
	cout << "ÅÅÐòÇ°" << endl;
	for (int i = 0; i<10; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	arrSort(arr);
	cout << "ÅÅÐòºó" << endl;
	for (int i= 0;i<10;i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
void main()
{
	test01();
	system("pause");
}