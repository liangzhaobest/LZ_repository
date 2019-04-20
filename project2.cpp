#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	const int N = 10;
	int a[N][N];
	a[0][0] = 1;a[1][0] = 1;a[1][1] = 1;
	for (int i = 2;i < N;i++)
	{
		for (int j = 1;j <= i - 1;j++)
		{
			a[i][0] = 1;
			a[i][i] = 1;
			a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
			
		}
	}
	for (int i (0);i < N;i++)
	{
		for (int j = 0;j <= i;j++)
			cout << setw(5) << a[i][j];
		cout << endl;
		
	}
	system("pause");
	return 0;

}