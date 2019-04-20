class Cstudent
{
private:
	char name[200];

	char nname[200];
	long No;
	float score[3];
public:
	void Getscore();
	void Getname();
	void GetNo();
	void PrintData();
	void GetAverage();
};

#include<iostream>
#include<iomanip>
using namespace std;
void Cstudent::Getscore()
{
	cout << "please input the student's scores:";
	for (int i = 0;i < 3;i++)
		cin >> score[i];
	cout << endl;
}
void Cstudent::Getname()
{
	cout << "please input the student's name:";
	cin >> name;
	cout << endl;
}
void  Cstudent::GetNo()
{
	cout << "please input the student's number:";
	cin >> No;
	cout << endl;
}
void Cstudent::PrintData()
{
	cout << name << "'s scores are:";
	for (int i = 0;i < 3;i++)
		cout << setw(5) << score[i];
	cout << endl;
}
void Cstudent::GetAverage()
{
	float a=0;
	for (int i = 0;i < 3;i++)
		a += score[i];
	cout << "the average of his(her) scores is:" << a << endl;


}
int main()
{
	cout << "*************************************************************************************************************\n"
		<< "**************** This is a program produced to cope with students'information!******************************** \n"
		<< "**************************************************************************************************************" << endl;
	int n;
	cout << "Please input the number of the students:";
	cin >> n;
	Cstudent ourstudent[60];
	for (int i = 0;i < n;i++)
	{
		ourstudent[i].Getname();
		ourstudent[i].GetNo();
		ourstudent[i].Getscore();
	}
	for (int i = 0;i < n;i++)
	{
		ourstudent[i].PrintData();
		ourstudent[i].GetAverage();
		cout << endl;
	}
	system("pause");
	return 0;
}