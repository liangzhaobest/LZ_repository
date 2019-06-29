#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
class Transportation
{
private:
	char cname[10];
	int  carnum;
	int year, month, day;
	float km;
	int  ymoney, total_money;
public:
	int y,Number;
	int i = 0;
	float V;
	int N, C, X, T;
	void Getinfor(), Getbus(), Getcar(), Gettruck(), Getbasic();
	void Showsort(Transportation a[], int n);
	void  Showinfor(), showbasic(), Showbus(), Showcar(), Showtruck();
	void Judge();
	friend void Getoption();
};
Transportation m[3];
int b(0), c(0), t(0);
void Transportation::Getinfor()
{
	cout << "请输入车辆类型的序号（bus(0),car(1) or truck(2)):";
	cin >> y;
	switch (y)
	{
	case 0:Getbus();b = b + 1;Judge(); break;
	case 1:Getcar();c = c + 1; Judge();break;
	case 2:Gettruck();t = t + 1;Judge(); break;
	default:cout << "输入错误！没有这种类型的车辆";Getinfor();
		break;
	}

}
void  Transportation::Getbasic()
{
	cout << "**编号：";cin >> m[i].Number;cout << Number;
	cout << "**车牌号：";cin >> m[i].carnum;
	cout << "**购买时间：年份-";cin >> m[i].year;cout << "月份-";cin >> m[i].month;cout << "日-";cin >> m[i].day;
	cout << "**制造公司：";cin >> m[i].cname;
	cout << "**总公里数：";cin >> m[i].km;
	cout << "**耗油量：";cin >> m[i].V;
	cout << "**养路费：";cin >> m[i].ymoney;
	

}
void Transportation::Getbus()
{
	Getbasic();
	cout << "**载客量：";cin >> m[i].C;

}
void Transportation::Getcar()
{
	Getbasic();
	cout << "**厢数：";cin >> m[i].X;
}
void Transportation::Gettruck()
{
	Getbasic();
	cout << "**载重量（整数吨）：";cin >> m[i].T;
}
void Transportation::Showinfor()
{
	int i = 0;
	switch (y)
	{
	case 0:m[i].Showbus(); break;
	case 1:m[i].Showcar();break;
	case 2:m[i].Showtruck(); break;
	default:cout << "错误！没有这种类型的车辆";
		break;
	}
}
void Transportation::Showbus()
{
	showbasic();
	cout << "载客数：" << m[i].C << "人" << endl;
}
void Transportation::Showcar()
{
	showbasic();
	cout << "厢数：" << m[i].X << "厢" << endl;
}
void Transportation::Showtruck()
{
	showbasic();
	cout << "载重量：" << m[i].T << "吨" << endl;
}
void Transportation::showbasic()
{
	cout << "**编号:" << m[i].Number << " 车牌号：" << m[i].carnum << " 购买时间：" << m[i].year << "-" << m[i].month << "-" << m[i].day << "\n制造公司：" << m[i].cname << " 行驶公里数" << m[i].km << "  耗油量：" << m[i].V << " 养路费:" << m[i].ymoney;
}
class Management :public Transportation
{
private:
public:

	void TJ();
	friend void Transportation::Getinfor();
};
void Management::TJ()
{
	cout << "大客车共有：" << b << "辆，" << "小轿车共有：" << c << "辆，" << "大卡车共有：" << t << "辆。\n" << "共计：" << b + c + t << "辆车。" << endl;
}
void create()
{
	cout << "车辆对象数组已创建！" << endl;
}
void Sort(Transportation a[], int n)
{
	Transportation temp;
	for (int i = 0;i < n;i++)
	{
		for (int j = 1;j < n - 1;j++)
		{
			if (a[j].V > a[j - 1].V)
			{
				temp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = temp;
			}
		}
	}
}
void Transportation::Showsort(Transportation a[], int n)
{
	for (int i = 0;i < n;i++)
	{
		cout << "编号：" << a[i].Number << "耗油量：" << a[i].V << endl;;
	}
}
void Showmenu()
{
	cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n"
		<< "=================**1.输入车辆的信息**=================\n"
		<< "=================**2.信息查询**=======================\n"
		<< "=================**3.输出当前车辆信息**===============\n"
		<< "=================**4.编辑信息**=======================\n"
		<< "=================**5.删除车辆**=======================\n"
		<< "=================**6.统计信息**=======================\n"
		<< "=================**7.排序功能**=======================\n"
		<< "=================**8.返回菜单**=======================\n"
		<< "=================**9.退出系统**=======================\n" << endl;
}
void   Delay(int  time)
{
	clock_t   now = clock();
	while (clock() - now < time);
}
void Getoption()
{
	cout << "**请按照序选择相应的功能**\n"
		<< "!!选择退出后程序将于3秒后关闭!!" << endl;
	Showmenu();
	int x;
	int i = 0;
	cin >> x;
	Management ma;
	switch (x)
	{
	case 1:cout << "***************【输入车辆信息】****************" << endl;m[i].Getinfor();break;
	case 2:cout << "***************【查询车辆信息】****************" << endl;break;
	case 3:cout << "***************【输出车辆信息】****************" << endl;m[i].Showinfor();m[i].Judge();  break;
	case 4:cout << "***************【编辑车辆信息】****************" << endl;break;
	case 5:cout << "***************【删除车辆信息】****************" << endl;break;
	case 6:cout << "***************【统计车辆信息】****************" << endl;;ma.TJ(); break;
	case 7:cout << "***************【排序车辆信息】****************" << endl;Sort(m, 4);m->Showsort(m, 4); break;
	case 8:cout << "***************【返回菜单】********************" << endl;Getoption(); break;
	case 9:cout << "******************【退出系统】*****************" << endl;cout << "感谢您的使用！！！";Delay(3 * 1000); break;
	default:cout << "您的输入有误，请检查后重新输入" << endl;
		break;
	}

}
void Transportation::Judge()
{
	cout << "*****************************\n";
	cout << "***1.继续输入信息***\n"
		<< "***2.返回菜单****\n" << endl;
	int x;cin >> x;
	if (x == 1)
		Getinfor();
	else Getoption();
}
int main()
{
	cout << "*********************************************************\n"
		<< "**********************************************************\n"
		<< "***************欢迎来到车辆管理系统！*********************\n"
		<< "**********************************************************\n"
		<< "**********************************************************\n" << endl;
	cout << "按任意键继续！" << endl;
	getchar();
	Getoption();
	return 0;
}