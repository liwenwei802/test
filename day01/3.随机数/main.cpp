#include <iostream>
#include <time.h>
using namespace std;

void main()
{
	int x;
	srand(time(NULL));
    for (int i = 0; i < 3;i++)
    {
		x = rand() % 52;
		cout << " x = " << x << " ";
    }
	cout << '\n';
	system("pause");
}