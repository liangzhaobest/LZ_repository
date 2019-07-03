#include<iostream>

#include<iomanip>

#include<string>

#include<conio.h>

#include<fstream>

#include<Windows.h>
using namespace std;
int y;int temp;
struct Trans

{

	int Number, carnum;

	int type;

	string  cname, Type;

	int year, month, day;

	int km, V, ymoney, jmoney, total_money;

	int C = 0;int T = 0;int B = 0;

};
class Management

{

private:
	string filename="infor";
	int N ;
	string sfilename = "store";
	//Trans*t=new Trans[N];
	Trans t[9];
    
	int present;

public:

	Management()

	{
		present = 0;
	}
	//~Management() { delete[] t; }
	int n1 = 0; int n2 = 0;int n3 = 0;

	int Km1 = 0, Km2 = 0, Km3 = 0;

	int price=10 ;
	void Getoption();

	void GetN();

	void Getinfor();

	void Searinfor();

	void Delinfor();

	void Ediinfor();

	void Showinfor();

	void Calinfor();

	void Sort();

	void Menu();

	void write();

	void read();

	void Store();

	void Gettype();

};
void Management::Gettype()//获取类型及相应类型的数据，统计各类型总数，计算费用，给不必要的值赋值

{

	cout << "类型的序号(1.客车 2.小轿车 3.卡车）：";cin >> t[present].type;

	switch (t[present].type)

	{

	case 1:

	{

		cout << "载客量：";cin >> t[present].B;

		t[present].Type = "客车";

		t[present].C = NULL;t[present].T = NULL;

		t[present].jmoney = 2000;

		t[present].total_money = price * t[present].V + t[present].jmoney;n1++;break;

	}

	case 2:

	{

		cout << "厢数：";cin >> t[present].C;

		t[present].Type = "轿车";t[present].B = NULL;t[present].T = NULL;

		t[present].jmoney = 1000;t[present].total_money = price * t[present].V + t[present].jmoney;n2++;break;

	}

	case 3:

	{

		cout << "载重：";cin >> t[present].T;

		t[present].Type = "卡车";t[present].C = NULL;t[present].B = NULL;

		t[present].jmoney = 1500;t[present].total_money = price * t[present].V + t[present].jmoney;n3++;break;

	}

	default:cout << "输入有误！";Gettype();break;

	}

}
void Management::Getoption()
{
	int opt;
	cout << "您是想新建一个文件，还是读取当前文件？（1.新建2.读取）";
	cin >> opt;
	switch (opt)
	{
	case 1:
	{
		cout << "请输入你想写入的文件名：";cin >> filename;
		cout << "请输入你想保存的文件名：";cin >> sfilename;
		break;
	}
	case 2:
	{
		read();
		break;
	}
	default:cout << "将新创建文件！" << endl;
		break;
	}
}
void Management::GetN()

{

	cout << "请输入你希望创建的车辆数目的最大值：";cin >> N;

	cout << "请输入当前油价：";cin >> price;

	cout << "(注：客车的基本维护费用为2000元/月,小轿车为1000元，卡车1500元）"

		<< "每台车当月费用=油价*耗油量/公里+基本维护费用" << endl;

}
void Management::Getinfor()//获取信息包括不同类型的特有数据

{

	int  a(1);

	while (true)

	{

		if (present<9)//判断是否超出容量

		{

			int i;

			cout << "请开始输入车辆的信息：\n"

				<< "编号：";

			cin >> i;

			for (int m = 0;m < present;m++)//判断编号是否已经存在，m控制对象数组

			{

				if (t[m].Number == i)

				{

					cout << "该编号已存在！" << endl;

					a++;

					break;

				}

			}

			if (a == 1)//输入基本信息

			{

				t[present].Number = i;cout << "行驶里程：";cin >> t[present].km;cout << "耗油量：";cin >> t[present].V;cout << "养路费：";cin >> t[present].ymoney;

				Gettype();

				cout << "车牌号：";cin >> t[present].carnum;

				cout << "制造公司：";

				cin >> t[present].cname;

				cout << "购买日期：年：";cin >> t[present].year;cout << "月：";cin >> t[present].month;cout << "日：";cin >> t[present].day;

				

				cout << "已添加该车辆的信息！" << endl;

				present++;



				int x;

				cout << "继续请输入1，结束请输入2：";cin >> x;

				if (x == 2)

				{

					cout << "退出！" << endl;break;

				}

			}

			else a = 1;continue;

		}

		else

		{

			cout << "车辆信息已满无法添加！";break;

		}

	}

	Sleep(800);

	Menu();

}
void Management::Searinfor()//查找信息（按照编号，类型还有公司）

{

	int i;//选择查询方式
	system("cls");
	cout << "*请选择你需要查找方式：\n"
		<< "*1.编号\n"
		<< "*2.制造公司\n"
		<< "*3.类型\n" 
		<<"*0.返回菜单"<< endl;cin >> i;

	switch (i)

	{

	case 1:

	{

		int n;	int p = 0;

		cout << "请输入要查找车辆的编号：";cin >> n;

		for (int i = 0;i < present;i++)

		{

			if (t[i].Number == n)

			{

				cout << "正在查找" << endl;

				cout << "*";Sleep(100);cout << "*";Sleep(100);cout << "*";Sleep(100);cout << "*";Sleep(100);cout << "*";Sleep(100);cout << "*";Sleep(100);cout << "*";Sleep(100);cout << "*";Sleep(100);cout << "*";Sleep(100);cout << "*";Sleep(100);cout << "*";Sleep(100);cout << "*";Sleep(100);cout << "*";Sleep(100);cout << "*";Sleep(100); cout << endl;

				cout << "编号为" << t[i].Number << "的车辆信息为：" << "类型：" << t[i].Type << " 车牌号：" << t[i].carnum << " 购买日期：" << t[i].year << "-" << t[i].month << "-" << t[i].day << " 制造公司：" << t[i].cname << " 行驶里程：" << t[i].km << "km" << " 耗油量：" << t[i].V << "L/KM" << " 养路费：" << t[i].ymoney << "元" << "总费用：" << t[i].total_money << "元";

				if (t[i].Type == "客车")

				{

					cout << "载客量：" << t[i].B << endl;

				}

				else if (t[i].Type == "卡车")cout << "载重：" << t[i].T << endl;

				else cout << "厢数：" << t[i].C << endl;
				int u;
				cout << "【********0.返回上一级*********】";cin >> u;if (u == 0) { Searinfor(); };
				p++;

			}

		}

		if (p == 0)

		{

			cout << "对不起，当前库中没有这个编号！" << endl;
			int u;
			cout << "【********0.返回上一级*********】";cin >> u;if (u == 0) { Searinfor(); };
		}

	}break;

	case 2:

	{

		string name;int p = 0;

		cout << "请输入你想要查找车辆的制造公司：";cin >> name;

		for (int i = 0;i < present;i++)

		{

			if (t[i].cname == name)

			{

				p++;

				cout << "正在查找" << endl;

				cout << "*";Sleep(100);cout << "*";Sleep(100);cout << "*";Sleep(100);cout << "*";Sleep(100);cout << "*";Sleep(100);cout << "*";Sleep(100);cout << "*";Sleep(100);cout << "*";Sleep(100);cout << "*";Sleep(100);cout << "*";Sleep(100);cout << "*";Sleep(100);cout << "*";Sleep(100);cout << "*";Sleep(100);cout << "*";Sleep(100); cout << endl;

				cout << "由" << name << "制造的相关车辆信息为：\n" << "类型：" << t[i].Type << " 车牌号：" << t[i].carnum << " 购买日期：" << t[i].year << "-" << t[i].month << "-" << t[i].day << "制造公司：" << t[i].cname << " 行驶里程：" << t[i].km << "km" << " 耗油量：" << t[i].V << " 养路费：" << t[i].ymoney << "总费用：" << t[i].total_money;

				if (t[i].Type == "客车")

				{

					cout << "载客量：" << t[i].B << endl;

				}

				else if (t[i].Type == "卡车")cout << "载重：" << t[i].T << endl;

				else cout << "厢数：" << t[i].C << endl;

				cout << "当前库中共有该公司制造的" << p << "辆车" << endl;
				int u;
				cout << "【********0.返回上一级*********】";cin >> u;if (u == 0) { Searinfor(); };

			}





		}

		if (p == 0) { cout << "没有该车辆信息！" << endl;int u;
		cout << "【********0.返回上一级*********】";cin >> u;if (u == 0) { Searinfor(); };
		}

	}break;

	case 3:

	{

		string tt;int p = 0;

		cout << "请输入你想要查找车辆的类型：";cin >> tt;

		for (int i = 0;i < present;i++)

		{

			if (t[i].Type == tt)

			{

				p++;

				cout << "正在查找" << endl;

				cout << "*";Sleep(100);cout << "*";Sleep(100);cout << "*";Sleep(100);cout << "*";Sleep(100);cout << "*";Sleep(100);cout << "*";Sleep(100);cout << "*";Sleep(100);cout << "*";Sleep(100);cout << "*";Sleep(100);cout << "*";Sleep(100);cout << "*";Sleep(100);cout << "*";Sleep(100);cout << "*";Sleep(100);cout << "*";Sleep(100); cout << endl;

				cout << tt << "的相关车辆信息为：\n" << "制造公司：" << t[i].cname << " 车牌号：" << t[i].carnum << " 购买日期：" << t[i].year << "-" << t[i].month << "-" << t[i].day << "制造公司：" << t[i].cname << " 行驶里程：" << t[i].km << "km" << " 耗油量：" << t[i].V << " 养路费：" << t[i].ymoney << "总费用：" << t[i].total_money;

				if (t[i].Type == "客车")

				{

					cout << "载客量：" << t[i].B << endl;

				}

				else if (t[i].Type == "卡车")cout << "载重：" << t[i].T << endl;

				else cout << "厢数：" << t[i].C << endl;

				cout << "当前库中共有该公司制造的" << p << "辆车" << endl;
				int u;
				cout << "【********0.返回上一级*********】";cin >> u;if (u == 0) { Searinfor(); };
			}
		}

		if (p == 0) { cout << "没有该车辆信息！" << endl;int u;
		cout << "【********0.返回上一级*********】";cin >> u;if (u == 0) { Searinfor(); };
		}

	}break;
	default:Menu();break;
	}

	cout << "请按任意键继续！";char z = _getch(); Menu();

}
void Management::Delinfor()//删除信息

{

	int i;int k = 0;

	while (true)

	{

		if (present == 0)

		{

			cout << "未录入任何信息！车辆信息库为空！" << endl;

		}

		else

		{

			cout << "请输入要删除车辆的编号：";cin >> i;//查找要删除车辆的编号

			for (int j = 0;j < present;j++)

			{

				if (t[j].Number == i)

				{

					string J;

					cout << "该车辆已找到！是否确认删除？YES/NO";cin >> J;

					if (J == "YES" || J == "Yes" || J == "yes")

					{

						t[j] = t[present - 1];

						present--;

						k++;



					}

					else if (J == "NO" || J == "No" || J == "no") cout << "已取消删除" << endl;Sleep(200);Menu();

				}

			}

			if (k == 0)

			{

				cout << "要删除的编号不存在！" << endl;break;

			}

			else

			{

				cout << "已删除编号为：" << i << "的车辆信息！" << endl;break;

			}

		}

	}

	cout << "任意键继续" << endl;

	Sleep(1000);

	Menu();

}
void Management::Ediinfor()//编辑

{

	int n;	int p = 0;

	cout << "请输入要查找车辆的编号：";cin >> n;//先查找要编辑的车辆

	for (int i = 0;i < present;i++)

	{

		if (t[i].Number == n)//利用if判断是否修改，定义temp 临时对象以实现是否保存修改

		{

			int a;int b;int c;Trans temp;temp = t[i];

			cout << "已查询到你要找的车辆，请开始编辑：（注：不希望修改的地方请两次回车输入1,需要修改请输入2继续,0返回菜单.编号无法修改！）";

			cout << "编号为：" << n << endl;

			cout << "类型：" << t[i].Type;
			cin >> a;

			if (a == 1) {
				cout<<"" ;

			}

			else if (a == 2) { cout << "修改为：";cin >> t[i].Type; }
			else Menu();
			cout << " 车牌号：" << t[i].carnum;

			cin >> b;

			if (b == 1) {
				cout << " ";

			}

			else if (b == 2) { cout << "修改为：";cin >> t[i].carnum; }
			else Menu();
			cout << " 购买日期：" << t[i].year << "-" << t[i].month << "-" << t[i].day;

			cin >> c;

			if (c == 1) {
				cout << " ";

			}

			else if (c == 2) { cout << "修改为：";cin >> t[i].year; }
			else Menu();
			cout << "制造公司：" << t[i].cname;

			cin >> a;

			if (a == 1) {
				cout << " ";

			}

			else if (a == 2) { cout << "修改为：";cin >> t[i].cname; }
			else Menu();
			cout << " 行驶里程：" << t[i].km << "km";

			cin >> b;

			if (b == 1) {
				cout << " ";

			}

			else if (b == 2) { cout << "修改为：";cin >> t[i].km; }

			cout << " 耗油量：" << t[i].V << "L/KM";

			cin >> c;

			if (c == 1) {
				cout << " ";

			}

			else if (c == 2) { cout << "修改为：";cin >> t[i].V; }
			else Menu();
			cout << " 养路费：" << t[i].ymoney << "元";

			cin >> a;

			if (a == 1) {
				cout << " ";

			}

			else if (a == 2) { cout << "修改为：";cin >> t[i].ymoney; }
			else Menu();
			cout << "总费用：" << t[i].total_money << "元";

			cin >> b;

			if (b == 1) {
				cout << " ";

			}

			else if (b == 2){cout << "修改为：";cin >> t[i].total_money;}
			else Menu();
			switch (t[i].type)

			{

			case 1:

			{

				cout << "载客量：" << t[i].B;

				cin >> a;

				if (a == 1) { cout << ""; }

				else  if (a == 2) { cout << "修改为：";cin >> t[i].B; }
				else Menu();
			}

			case 2:

			{



				cout << "厢数：" << t[i].C;

				cin >> a;

				if (a == 1)

				{

					cout << "";

				}

				else  if (a == 2) { cout << "修改为：";cin >> t[i].T; }
				else Menu();
			}

			default:

			{

				cout << "载重：" << t[i].T;

				cin >> a;

				if (a == 1)

				{

					cout << "";

				}

				else if (a == 2) { cout << "修改为：";cin >> t[i].T; }
				else Menu();
			}

			break;

			}

			int k;

			cout << "是否确认修改？（1.是 2.否）：";//判断是否修改

			cin >> k;

			if (k == 1)

			{

				cout << "已成功修改！" << endl;

			}

			else t[i] = temp;



			p++;

		}

	}

	if (p == 0)

	{

		cout << "对不起，当前库中没有这个编号！" << endl;

	}

	cout << "任意键继续" << endl;char z = _getch();

	Sleep(1000);

	Menu();

}
void Management::Calinfor()//统计信息

{

	cout << "**信息统计的结果如下：\n"

		<< "@车辆总数：" << present << "辆" << endl;

	cout << "**大客车数目：" << n1 << " 小轿车数目：" << n2 << "卡车数目：" << n3 << endl;

	cout << "总里程为：";int a = 0;

	for (int i = 0;i < present;i++)

	{

		a = a + t[i].km;

	}cout << a << endl;

	cout << "@客车总公里数：" << Km1 << " 小轿车总公里数：" << Km2 << "  卡车总公里数：" << Km3 << endl;

	float H(0);

	for (int i = 0;i < present;i++)//平均费用

	{

		H = H + t[i].V;

	}

	cout << "所有车俩平均费用：" << H / present << "元" << endl;

	cout << "任意键继续" << endl;char z = _getch();

	Menu();

}
void Management::Sort()//排序，分两种方式

{

	int p;

	cout << "请输入你想要的排序方式：1.从小到大2.从大到小：";cin >> p;

	switch (p)

	{

	case 1:

	{

		for (int i = 0;i < present - 1;i++)

		{

			for (int j = i + 1;j < present;j++)

			{

				if (t[i].V > t[j].V)

				{

					Trans temp;

					temp = t[i];

					t[i] = t[j];

					t[j] = temp;

				}

			}

		}

	} break;

	default:

	{

		for (int i = 0;i < present - 1;i++)

		{

			for (int j = i + 1;j < present;j++)

			{

				if (t[i].V <= t[j].V)

				{

					Trans temp;

					temp = t[i];

					t[i] = t[j];

					t[j] = temp;

				}

			}

		}

	}

	break;

	}

	cout << "\n\n排序完成！已按照要求的三种类型车辆耗油量大小进行排序，结果如下：\n";//输出排序结果

	for (int i = 0;i < present;i++)

	{

		if (t[i].type == 1)

		{

			cout << "**客车**\n";

			cout << "编号" << setw(8) << "车牌" << setw(8) << "公司" << setw(12) << "日期" << setw(8) << "里程" << setw(8) << "耗油" << setw(8) << "载客量" << setw(8) << "养路费" << setw(8) << "总费用" << endl;

			cout << t[i].Number << setw(8) << t[i].carnum << setw(8) << t[i].cname << setw(10) << t[i].year << "-" << t[i].month << "-" << t[i].day << setw(8) << t[i].km << setw(8) << t[i].V << setw(5) << t[i].B << setw(8) << t[i].ymoney << setw(8) << t[i].total_money << endl;

			cout << "***************************************************************************" << endl;

			Km1 = Km1 + t[i].km;

		}

		else continue;

	}

	for (int i = 0;i < present;i++)

	{

		if (t[i].type == 2)

		{

			cout << "轿车\n";

			cout << "编号" << setw(8) << "车牌" << setw(8) << "公司" << setw(8) << "日期" << setw(8) << "里程" << setw(8) << "耗油" << setw(8) << "厢数" << setw(8) << "养路费" << setw(8) << "费用" << endl;

			cout << t[i].Number << setw(8) << t[i].carnum << setw(8) << t[i].cname << setw(10) << t[i].year << "-" << t[i].month << "-" << t[i].day << setw(8) << t[i].km << setw(8) << t[i].V << setw(5) << t[i].C << setw(8) << t[i].ymoney << setw(8) << t[i].total_money << endl;

			cout << "***************************************************************************" << endl;

			Km2 = Km2 + t[i].km;

		}

		else continue;

	}

	for (int i = 0;i < present;i++)

	{

		if (t[i].type == 3)

		{

			cout << "卡车\n";

			cout << "编号" << setw(8) << "车牌" << setw(8) << "公司" << setw(12) << "日期" << setw(8) << "里程" << setw(8) << "耗油" << setw(5) << "载重" << setw(8) << "养路费" << setw(8) << "费用" << endl;

			cout << t[i].Number << setw(8) << t[i].carnum << setw(8) << t[i].cname << setw(10) << t[i].year << "-" << t[i].month << "-" << t[i].day << setw(8) << t[i].km << setw(8) << t[i].V << setw(5) << t[i].T << setw(8) << t[i].total_money << setw(8) << t[i].total_money << endl;

			cout << "***************************************************************************" << endl;

			Km3 = Km3 + t[i].km;

		}

		else continue;

	}

	cout << "排序已结束，即将返回菜单！按任意键继续" << endl;char z = _getch();Menu();

}
void Management::Showinfor()//显示信息

{



	if (present != 0)

	{

		cout << "****所有车辆的信息为：\n"

			<< "类型" << setw(5) << "编号" << setw(8) << "车牌" << setw(8) << "公司" << setw(9) << "里程" << setw(10) << "耗油量" << setw(8) << "载客量" << setw(8) << "载重量" << setw(8) << "厢数" << setw(8) << "日期" << setw(10) << "养路费" << setw(12) << "总费用" << endl;

		for (int i = 0;i < present;i++)

		{

			cout << t[i].Type << setw(5) << t[i].Number << setw(8) << t[i].carnum << setw(8) << t[i].cname << setw(8) << t[i].km << setw(8) << t[i].V << setw(8) << t[i].B << setw(9) << t[i].T << setw(7) << t[i].C << setw(8) << t[i].year << "-" << t[i].month << "-" << t[i].day << setw(8) << t[i].ymoney << setw(10) << t[i].total_money << endl;

		}

	}

	else cout << "还没有录入任何车辆的信息！返回菜单" << endl;

	cout << "任意键继续" << endl;

	char z = _getch();

	Menu();

}
void Management::Menu()//菜单

{



	system("cls");



	cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n"

		<< "=================**1.输入车辆的信息**=================\n"

		<< "=================**2.信息查询**=======================\n"

		<< "=================**3.输出当前车辆信息**===============\n"

		<< "=================**4.编辑信息**=======================\n"

		<< "=================**5.删除车辆**=======================\n"

		<< "=================**6 排序功能**=======================\n"

		<< "=================**7.统计功能**=======================\n"

		<< "=================**8.写入文件**=======================\n"

		<< "=================**9.读取文件**=======================\n"

		<< "=================**10.保存信息**=======================\n"

		<< "=================**11.退出系统**=======================\n" << endl;

	int x;cout << "请输入需要服务的序号：";

	cin >> x;

	switch (x)

	{

	case 1:cout << "***************【输入车辆信息】****************" << endl;Getinfor();break;

	case 2:cout << "***************【查询车辆信息】****************" << endl;Searinfor();break;

	case 3:cout << "  *************【输出车辆信息】****************" << endl;Showinfor();break;

	case 4:cout << "***************【编辑车辆信息】****************" << endl;Ediinfor();break;

	case 5:cout << "***************【删除车辆信息】****************" << endl;Delinfor();break;

	case 6:cout << "***************【排序车辆信息】****************" << endl; Sort();;break;

	case 7:cout << "***************【统计车辆信息】****************" << endl; Calinfor();break;

	case 8:cout << "***************【写入文件】********************" << endl; write();break;

	case 9:cout << "******************【读取文件】*****************" << endl;read();break;

	case 10:cout << "******************【保存信息】*****************" << endl;Store();break;

	case 11:cout << "******************【退出系统】*****************" << endl;int m;cout << "是否确认退出？（是1 否2）";cin >> m;if (m == 1) { cout << "开始退出" << endl; }
			else Menu();cout << setw(10) << "*感";Sleep(200);cout << "谢";Sleep(200);cout << "您";Sleep(200);cout << "的";Sleep(200);cout << "使";Sleep(200);cout << "用！*";Sleep(200);exit(0);break;

	default:cout << "您的输入有误，请检查后重新输入" << endl;Sleep(200);Menu();

		break;

	}

}
/*void Management::read()//读操作

{

	while (1)

	{

		ifstream read("d:\\project\\梁炤课程设计\\infor.txt", ios::in);

		if (read)

		{

			while (!read.eof())

			{



				read>>  t[present].Number>>t[present].type>> t[present].carnum >> t[present].cname >> t[present].year >> t[present].month >> t[present].day >> t[present].km >>t[present].V >> t[present].ymoney;

				if (t[present].type == 1)

					read >> t[present].B;

				else if (t[present].type == 2)

					read >> t[present].C;

				else

					read>>t[present].T;

					present++;

			}

			read.close();

			break;

		}

		else

		{

			ofstream out("d:\\project\\梁炤课程设计\\information.txt");

			out.close();

		}

		Menu();

	}



	present = n1 + n2 + n3;

}

void Management::write()//写操作

{

	ofstream write;

	write.open("d:\\project\\梁炤课程设计\\information.txt", ios::out);

	if (write)

	{

		for (int i = 0; i < present; i++)

		{

			cout << "*";Sleep(100);cout << "*";Sleep(100);cout << "*";Sleep(100);cout << "*";Sleep(100);cout << "*";Sleep(100);cout << "*";Sleep(100);cout << "*";Sleep(100);cout << "*";Sleep(100);cout << "*";Sleep(100); cout << endl;
			cout << "第" << i + 1 << "条写入完成！" << endl;
			write <<t[i].Type<<setw(8)<< t[i].Number << setw(8) << t[i].carnum << setw(8) << t[i].cname << setw(8) << t[i].km << setw(8) << t[i].V << setw(8) << t[i].B << setw(8) << t[i].T << setw(5) << t[i].C << setw(8) << t[i].year << setw(5) << t[i].month << setw(5) << t[i].day << t[i].ymoney << setw(8) << t[i].total_money << endl;
		}
		write.close();

	}

	else cout << "写入失败！" << endl;

	cout << "任意键继续！";char z = _getch();Menu();

}
*/
void Management::Store()//保存

{
	int  M;
	if (sfilename == "store")
	{
		cout << "保存到前文件！";
	}
	else cout << "保存到" << sfilename << "文件" << endl;
	cout << "是否确认保存？是1 否2";cin >> M;//判断是否保存信息
	if (M == 1)
	{
		cout << "开始保存" << endl;
	}
	else Menu();
	ofstream fileout("d:\\project\\梁炤课程设计\\store.txt", ios::trunc);

	fileout.close();

	ofstream write("d:\\project\\梁炤课程设计\\store.txt");

	cout << "*";Sleep(180);cout << "*";Sleep(180);cout << "*";cout << "*";Sleep(180);cout << "*";Sleep(180);cout << "*";Sleep(180);cout << "*";Sleep(180);cout << "*";Sleep(180);cout << "*";Sleep(180);cout << "*";Sleep(180); cout << endl;

	cout << "保存完成！" << endl;

	for (int i = 0;i < present;i++)

	{

		write << "****车辆的信息为：\n"

			<< "类型" << setw(5) << "编号" << setw(8) << "车牌" << setw(8) << "公司" << setw(8) << "里程" << setw(8) << "耗油" << setw(8) << "载客量" << setw(8) << "载重" << setw(8) << "厢数" << setw(8) << "日期" << endl;

		write << t[i].Type << setw(5) << t[i].Number << setw(8) << t[i].carnum << setw(8) << t[i].cname << setw(8) << t[i].km << setw(8) << t[i].V << setw(8) << t[i].B << setw(8) << t[i].T << setw(5) << t[i].C << setw(8) << t[i].year << "-" << t[i].month << "-" << t[i].day << endl;

	}

	write.close();

	cout << "已保存信息！" << endl;

	Sleep(600);

	Menu();

}
int main()

{

	Management mc;

	cout << "--*---*---*--*---*---*----*----*---*---*---*---*---*-----*\n"

		<< "|**********************************************************|\n"

		<< "|**********************************************************|\n"

		<< "|*************   !欢迎来到车辆管理系统！  *****************|\n"

		<< "|**********************************************************|\n"

		<< "|**********************************************************|\n"

		<< "--*---*---*--*---*---*----*----*---*---*---*---*---*-----*\n" << endl;

	mc.Getoption();
	cout << "按任意键继续！" << endl;
	char z = _getch();
	//mc.GetN();
	mc.Menu();
	return 0;

}
/*void Management::read()

{

	fstream f;

	f.open("d:\\project\\梁炤课程设计\\information.txt", ios::in);

	if (!f)

	{

		cerr << "打开文件错误！" << endl;

		Sleep(200);Menu();

	}


		cout << "*";Sleep(180);cout << "*";Sleep(180);cout << "*";cout << "*";Sleep(180);cout << "*";Sleep(180);cout << "*";Sleep(180);cout << "*";Sleep(180);cout << "*";Sleep(180);cout << "*";Sleep(180);cout << "*";Sleep(180); cout << endl;
		cout << "读取完成！";
	while (!f.eof())

	{
		f >>t[present].Type>> t[present].Number >> t[present].type >> t[present].carnum >> t[present].cname >> t[present].year >> t[present].month >> t[present].day >> t[present].km >> t[present].V >> t[present].ymoney >> t[present].total_money;
		present++;
	}




	f.close();
	Sleep(200);Menu();


}*/
void Management::write()
{
	int m;cout << "是否确认写入？（是1 否2）";cin >> m;if (m == 1) { cout << "开始写入" << endl; }
	else Menu();
	if (filename == "infor")
	{
		cout << "写入当前文件！";
	}
	else cout << "写入" << filename << "文件" << endl;
	ofstream f(filename, ios::binary);
	if (!f)
	{
		cout << "创建文件失败!" << endl;
		return;
	}
	f.write((char*)t, 9* sizeof(Trans));present = n1 + n2 + n3;f << present;
	cout << "*";Sleep(180);cout << "*";Sleep(180);cout << "*";cout << "*";Sleep(180);cout << "*";Sleep(180);cout << "*";Sleep(180);cout << "*";Sleep(180);cout << "*";Sleep(180);cout << "*";Sleep(180);cout << "*";Sleep(180); cout << endl;
	cout << "写入成功" << endl;
	
	f.close();
	Sleep(200);Menu();
}
void Management::read()
{
	if (filename == "infor")
	{
		cout << "读取当前文件！";
	}
	else cout << "读取" << filename << "文件" << endl;
	ifstream f(filename, ios::binary);
	if (!f)
	{
		cout << "读取文件失败,将创建新的文件" << endl;

	}
	else
	{
		f.read((char*)t, 9 * sizeof(Trans));f>>present;
		f.close();
		cout << "*";Sleep(180);cout << "*";Sleep(180);cout << "*";cout << "*";Sleep(180);cout << "*";Sleep(180);cout << "*";Sleep(180);cout << "*";Sleep(180);cout << "*";Sleep(180);cout << "*";Sleep(180);cout << "*";Sleep(180); cout << endl;

	
		cout << "读取完成" << endl;
	
		Sleep(200);Menu();
	}
}






