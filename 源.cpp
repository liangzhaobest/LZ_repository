#include<iostream>

#include<iomanip>

#include<string>

#include<conio.h>

#include<fstream>

#include<Windows.h>

using namespace std;

int y;int temp;

void   Delay(int  time)

{

	clock_t   now = clock();

	while (clock() - now < time);

}

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

	int N = 0;

	Trans t[3];

	int present;

public:

	Management()

	{
		present = 0;
	}

	int n1 = 0; int n2 = 0;int n3 = 0;

	int Km1 = 0, Km2 = 0, Km3 = 0;

	int price = 0;

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

void Management::Gettype()//��ȡ���ͼ���Ӧ���͵����ݣ�ͳ�Ƹ�����������������ã�������Ҫ��ֵ��ֵ

{

	cout << "���͵����(1.�ͳ� 2.С�γ� 3.��������";cin >> t[present].type;

	switch (t[present].type)

	{

	case 1:

	{

		cout << "�ؿ�����";cin >> t[present].B;

		t[present].Type = "�ͳ�";

		t[present].C = NULL;t[present].T = NULL;

		t[present].jmoney = 2000;

		t[present].total_money = price * t[present].V + t[present].jmoney;n1++;break;

	}

	case 2:

	{

		cout << "������";cin >> t[present].C;

		t[present].Type = "�γ�";t[present].B = NULL;t[present].T = NULL;

		t[present].jmoney = 1000;t[present].total_money = price * t[present].V + t[present].jmoney;n2++;break;

	}

	case 3:

	{

		cout << "���أ�";cin >> t[present].T;

		t[present].Type = "����";t[present].C = NULL;t[present].B = NULL;

		t[present].jmoney = 1500;t[present].total_money = price * t[present].V + t[present].jmoney;n3++;break;

	}

	default:cout << "��������";Gettype();break;

	}

}

void Management::GetN()

{

	cout << "��������ϣ�������ĳ�����Ŀ�����ֵ��";cin >> N;

	cout << "�����뵱ǰ�ͼۣ�";cin >> price;

	cout << "(ע���ͳ��Ļ���ά������Ϊ2000Ԫ/��,С�γ�Ϊ1000Ԫ������1500Ԫ��"

		<< "ÿ̨�����·���=�ͼ�*������/����+����ά������" << endl;

}

void Management::Getinfor()//��ȡ��Ϣ������ͬ���͵���������

{

	int  a(1);

	while (true)

	{

		if (present < 3)//�ж��Ƿ񳬳�����

		{

			int i;

			cout << "�뿪ʼ���복������Ϣ��\n"

				<< "��ţ�";

			cin >> i;

			for (int m = 0;m < present;m++)//�жϱ���Ƿ��Ѿ����ڣ�m���ƶ�������

			{

				if (t[m].Number == i)

				{

					cout << "�ñ���Ѵ��ڣ�" << endl;

					a++;

					break;

				}

			}

			if (a == 1)//���������Ϣ

			{

				t[present].Number = i;

				Gettype();

				cout << "���ƺţ�";cin >> t[present].carnum;

				cout << "���칫˾��";

				cin >> t[present].cname;

				cout << "�������ڣ��꣺";cin >> t[present].year;cout << "�£�";cin >> t[present].month;cout << "�գ�";cin >> t[present].day;

				cout << "��ʻ��̣�";cin >> t[present].km;cout << "��������";cin >> t[present].V;cout << "��·�ѣ�";cin >> t[present].ymoney;

				cout << "����Ӹó�������Ϣ��" << endl;

				present++;



				int x;

				cout << "����������1������������2��";cin >> x;

				if (x == 2)

				{

					cout << "�˳���" << endl;break;

				}

			}

			else a = 1;continue;

		}

		else

		{

			cout << "������Ϣ�����޷���ӣ�";break;

		}

	}

	Sleep(800);

	Menu();

}

void Management::Searinfor()//������Ϣ�����ձ�ţ����ͻ��й�˾��

{

	int i;//ѡ���ѯ��ʽ

	cout << "*��ѡ������Ҫ���ҷ�ʽ��\n"

		<< "*1.���\n"

		<< "*2.���칫˾\n"

		<< "*3.����" << endl;cin >> i;

	switch (i)

	{

	case 1:

	{

		int n;	int p = 0;

		cout << "������Ҫ���ҳ����ı�ţ�";cin >> n;

		for (int i = 0;i < present;i++)

		{

			if (t[i].Number == n)

			{

				cout << "���ڲ���" << endl;

				cout << "*";Sleep(100);cout << "*";Sleep(100);cout << "*";Sleep(100);cout << "*";Sleep(100);cout << "*";Sleep(100);cout << "*";Sleep(100);cout << "*";Sleep(100);cout << "*";Sleep(100);cout << "*";Sleep(100);cout << "*";Sleep(100);cout << "*";Sleep(100);cout << "*";Sleep(100);cout << "*";Sleep(100);cout << "*";Sleep(100); cout << endl;

				cout << "���Ϊ" << t[i].Number << "�ĳ�����ϢΪ��" << "���ͣ�" << t[i].Type << " ���ƺţ�" << t[i].carnum << " �������ڣ�" << t[i].year << "-" << t[i].month << "-" << t[i].day << " ���칫˾��" << t[i].cname << " ��ʻ��̣�" << t[i].km << "km" << " ��������" << t[i].V << "L/KM" << " ��·�ѣ�" << t[i].ymoney << "Ԫ" << "�ܷ��ã�" << t[i].total_money << "Ԫ";

				if (t[i].Type == "�ͳ�")

				{

					cout << "�ؿ�����" << t[i].B << endl;

				}

				else if (t[i].Type == "����")cout << "���أ�" << t[i].T << endl;

				else cout << "������" << t[i].C << endl;

				p++;

			}

		}

		if (p == 0)

		{

			cout << "�Բ��𣬵�ǰ����û�������ţ�" << endl;

		}

	}break;

	case 2:

	{

		string name;int p = 0;

		cout << "����������Ҫ���ҳ��������칫˾��";cin >> name;

		for (int i = 0;i < present;i++)

		{

			if (t[i].cname == name)

			{

				p++;

				cout << "���ڲ���" << endl;

				cout << "*";Sleep(100);cout << "*";Sleep(100);cout << "*";Sleep(100);cout << "*";Sleep(100);cout << "*";Sleep(100);cout << "*";Sleep(100);cout << "*";Sleep(100);cout << "*";Sleep(100);cout << "*";Sleep(100);cout << "*";Sleep(100);cout << "*";Sleep(100);cout << "*";Sleep(100);cout << "*";Sleep(100);cout << "*";Sleep(100); cout << endl;

				cout << "��" << name << "�������س�����ϢΪ��\n" << "���ͣ�" << t[i].Type << " ���ƺţ�" << t[i].carnum << " �������ڣ�" << t[i].year << "-" << t[i].month << "-" << t[i].day << "���칫˾��" << t[i].cname << " ��ʻ��̣�" << t[i].km << "km" << " ��������" << t[i].V << " ��·�ѣ�" << t[i].ymoney << "�ܷ��ã�" << t[i].total_money;

				if (t[i].Type == "�ͳ�")

				{

					cout << "�ؿ�����" << t[i].B << endl;

				}

				else if (t[i].Type == "����")cout << "���أ�" << t[i].T << endl;

				else cout << "������" << t[i].C << endl;

				cout << "��ǰ���й��иù�˾�����" << p << "����" << endl;

			}





		}

		if (p == 0) { cout << "û�иó�����Ϣ��" << endl; }

	}break;

	default:

	{

		string tt;int p = 0;

		cout << "����������Ҫ���ҳ��������ͣ�";cin >> tt;

		for (int i = 0;i < present;i++)

		{

			if (t[i].Type == tt)

			{

				p++;

				cout << "���ڲ���" << endl;

				cout << "*";Sleep(100);cout << "*";Sleep(100);cout << "*";Sleep(100);cout << "*";Sleep(100);cout << "*";Sleep(100);cout << "*";Sleep(100);cout << "*";Sleep(100);cout << "*";Sleep(100);cout << "*";Sleep(100);cout << "*";Sleep(100);cout << "*";Sleep(100);cout << "*";Sleep(100);cout << "*";Sleep(100);cout << "*";Sleep(100); cout << endl;

				cout << tt << "����س�����ϢΪ��\n" << "���칫˾��" << t[i].cname << " ���ƺţ�" << t[i].carnum << " �������ڣ�" << t[i].year << "-" << t[i].month << "-" << t[i].day << "���칫˾��" << t[i].cname << " ��ʻ��̣�" << t[i].km << "km" << " ��������" << t[i].V << " ��·�ѣ�" << t[i].ymoney << "�ܷ��ã�" << t[i].total_money;

				if (t[i].Type == "�ͳ�")

				{

					cout << "�ؿ�����" << t[i].B << endl;

				}

				else if (t[i].Type == "����")cout << "���أ�" << t[i].T << endl;

				else cout << "������" << t[i].C << endl;

				cout << "��ǰ���й��иù�˾�����" << p << "����" << endl;

			}





		}

		if (p == 0) { cout << "û�иó�����Ϣ��" << endl; }

	}break;



	}

	cout << "�밴�����������";char z = _getch(); Menu();

}

void Management::Delinfor()//ɾ����Ϣ

{

	int i;int k = 0;

	while (true)

	{

		if (present == 0)

		{

			cout << "δ¼���κ���Ϣ��������Ϣ��Ϊ�գ�" << endl;

		}

		else

		{

			cout << "������Ҫɾ�������ı�ţ�";cin >> i;//����Ҫɾ�������ı��

			for (int j = 0;j < present;j++)

			{

				if (t[j].Number == i)

				{

					string J;

					cout << "�ó������ҵ����Ƿ�ȷ��ɾ����YES/NO";cin >> J;

					if (J == "YES" || J == "Yes" || J == "yes")

					{

						t[j] = t[present - 1];

						present--;

						k++;



					}

					else if (J == "NO" || J == "No" || J == "no") cout << "��ȡ��ɾ��" << endl;

				}

			}

			if (k == 0)

			{

				cout << "Ҫɾ���ı�Ų����ڣ�" << endl;

			}

			else

			{

				cout << "��ɾ�����Ϊ��" << i << "�ĳ�����Ϣ��" << endl;break;

			}

		}

	}

	cout << "���������" << endl;

	Sleep(1000);

	Menu();

}

void Management::Ediinfor()//�༭

{

	int n;	int p = 0;

	cout << "������Ҫ���ҳ����ı�ţ�";cin >> n;//�Ȳ���Ҫ�༭�ĳ���

	for (int i = 0;i < present;i++)

	{

		if (t[i].Number == n)//����if�ж��Ƿ��޸ģ�����temp ��ʱ������ʵ���Ƿ񱣴��޸�

		{

			int a;int b;int c;Trans temp;temp = t[i];

			cout << "�Ѳ�ѯ����Ҫ�ҵĳ������뿪ʼ�༭����ע����ϣ���޸ĵĵط���س���ո�����1,��Ҫ�޸��������������ּ���.����޷��޸ģ���";

			cout << "���Ϊ��" << n << endl;

			cout << "���ͣ�" << t[i].Type;

			cin >> a;

			if (a == 1) {
				cout << "";

			}

			else  cout << "�޸�Ϊ��";cin >> t[i].Type;

			cout << " ���ƺţ�" << t[i].carnum;

			cin >> b;

			if (b == 1) {
				cout << " ";

			}

			else  cout << "�޸�Ϊ��";cin >> t[i].carnum;

			cout << " �������ڣ�" << t[i].year << "-" << t[i].month << "-" << t[i].day;

			cin >> c;

			if (c == 1) {
				cout << " ";

			}

			else cout << "�޸�Ϊ��";cin >> t[i].year;

			cout << "���칫˾��" << t[i].cname;

			cin >> a;

			if (a == 1) {
				cout << " ";

			}

			else  cout << "�޸�Ϊ��";cin >> t[i].cname;

			cout << " ��ʻ��̣�" << t[i].km << "km";

			cin >> b;

			if (b == 1) {
				cout << " ";

			}

			else cout << "�޸�Ϊ��";cin >> t[i].km;

			cout << " ��������" << t[i].V << "L/KM";

			cin >> c;

			if (c == 1) {
				cout << " ";

			}

			else cout << "�޸�Ϊ��";cin >> t[i].V;

			cout << " ��·�ѣ�" << t[i].ymoney << "Ԫ";

			cin >> a;

			if (a == 1) {
				cout << " ";

			}

			else cout << "�޸�Ϊ��";cin >> t[i].ymoney;

			cout << "�ܷ��ã�" << t[i].total_money << "Ԫ";

			cin >> b;

			if (b == 1) {
				cout << " ";

			}

			else cout << "�޸�Ϊ��";cin >> t[i].total_money;

			switch (t[i].type)

			{

			case 1:

			{

				cout << "�ؿ�����" << t[i].B;

				cin >> a;

				if (a == NULL) { cout << ""; }

				else  cout << "�޸�Ϊ��";cin >> t[i].B;

			}

			case 2:

			{



				cout << "������" << t[i].C;

				cin >> a;

				if (a == NULL)

				{

					cout << "";

				}

				else  cout << "�޸�Ϊ��";cin >> t[i].T;

			}

			default:

			{

				cout << "���أ�" << t[i].T;

				cin >> a;

				if (a == NULL)

				{

					cout << "";

				}

				else cout << "�޸�Ϊ��";cin >> t[i].T;

			}

			break;

			}

			int k;

			cout << "�Ƿ�ȷ���޸ģ���1.�� 2.�񣩣�";//�ж��Ƿ��޸�

			cin >> k;

			if (k == 1)

			{

				cout << "�ѳɹ��޸ģ�" << endl;

			}

			else t[i] = temp;



			p++;

		}

	}

	if (p == 0)

	{

		cout << "�Բ��𣬵�ǰ����û�������ţ�" << endl;

	}

	cout << "���������" << endl;char z = _getch();

	Sleep(1000);

	Menu();

}

void Management::Calinfor()//ͳ����Ϣ

{

	cout << "**��Ϣͳ�ƵĽ�����£�\n"

		<< "@����������" << present << "��" << endl;

	cout << "**��ͳ���Ŀ��" << n1 << " С�γ���Ŀ��" << n2 << "������Ŀ��" << n3 << endl;

	cout << "�����Ϊ��";int a = 0;

	for (int i = 0;i < present;i++)

	{

		a = a + t[i].km;

	}cout << a << endl;

	cout << "@�ͳ��ܹ�������" << Km1 << " С�γ��ܹ�������" << Km2 << "  �����ܹ�������" << Km3 << endl;

	float H(0);

	for (int i = 0;i < present;i++)//ƽ������

	{

		H = H + t[i].V;

	}

	cout << "���г���ƽ�����ã�" << H / present << "Ԫ" << endl;

	cout << "���������" << endl;char z = _getch();

	Menu();

}

void Management::Sort()//���򣬷����ַ�ʽ

{

	int p;

	cout << "����������Ҫ������ʽ��1.��С����2.�Ӵ�С��";cin >> p;

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

	cout << "\n\n������ɣ��Ѱ���Ҫ����������ͳ�����������С�������򣬽�����£�\n";//���������

	for (int i = 0;i < present;i++)

	{

		if (t[i].type == 1)

		{

			cout << "**�ͳ�**\n";

			cout << "���" << setw(8) << "����" << setw(8) << "��˾" << setw(12) << "����" << setw(8) << "���" << setw(8) << "����" << setw(8) << "�ؿ���" <<setw(8)<<"��·��"<<setw(8)<<"�ܷ���"<< endl;

			cout << t[i].Number << setw(8) << t[i].carnum << setw(8) << t[i].cname << setw(10) << t[i].year << "-" << t[i].month << "-" << t[i].day << setw(8) << t[i].km << setw(8) << t[i].V << setw(5) << t[i].B <<setw(8)<<t[i].ymoney<<setw(8)<<t[i].total_money<< endl;

			cout << "***************************************************************************" << endl;

			Km1 = Km1 + t[i].km;

		}

		else continue;

	}

	for (int i = 0;i < present;i++)

	{

		if (t[i].type == 2)

		{

			cout << "�γ�\n";

			cout << "���" << setw(8) << "����" << setw(8) << "��˾" << setw(8) << "����" << setw(8) << "���" << setw(8) << "����" << setw(8) << "����"<<setw(8) <<"��·��"<<setw(8)<<"����"<< endl;

			cout << t[i].Number << setw(8) << t[i].carnum << setw(8) << t[i].cname << setw(10) << t[i].year << "-" << t[i].month << "-" << t[i].day << setw(8) << t[i].km << setw(8) << t[i].V << setw(5) << t[i].C<<setw(8)<<t[i].ymoney<<setw(8)<<t[i].total_money<< endl;

			cout << "***************************************************************************" << endl;

			Km2 = Km2 + t[i].km;

		}

		else continue;

	}

	for (int i = 0;i < present;i++)

	{

		if (t[i].type == 3)

		{

			cout << "����\n";

			cout << "���" << setw(8) << "����" << setw(8) << "��˾" << setw(12) << "����" << setw(8) << "���" << setw(8) << "����" << setw(5) << "����"<<setw(8)<<"��·��"<<setw(8)<<"����" << endl;

			cout << t[i].Number << setw(8) << t[i].carnum << setw(8) << t[i].cname << setw(10) << t[i].year << "-" << t[i].month << "-" << t[i].day << setw(8) << t[i].km << setw(8) << t[i].V << setw(5) << t[i].T <<setw(8)<<t[i].total_money<<setw(8)<<t[i].total_money<< endl;

			cout << "***************************************************************************" << endl;

			Km3 = Km3 + t[i].km;

		}

		else continue;

	}

	cout << "�����ѽ������������ز˵��������������" << endl;char z = _getch();Menu();

}

void Management::Showinfor()//��ʾ��Ϣ

{



	if (present != 0)

	{

		cout << "****���г�������ϢΪ��\n"

			<< "����" << setw(5) << "���" << setw(8) << "����" << setw(8) << "��˾" << setw(9) << "���" << setw(10) << "������" <<setw(8) << "�ؿ���" << setw(8) << "������" << setw(8) << "����" << setw(8) << "����" << setw(10)<<"��·��"<<setw(12) << "�ܷ���" << endl;

		for (int i = 0;i < present;i++)

		{

			cout << t[i].Type << setw(5) << t[i].Number << setw(8) << t[i].carnum << setw(8) << t[i].cname << setw(8) << t[i].km << setw(8) << t[i].V << setw(8) << t[i].B << setw(9) << t[i].T << setw(7) << t[i].C << setw(8) << t[i].year << "-" << t[i].month << "-" << t[i].day<<setw(8) <<t[i].ymoney<<setw(10)<< t[i].total_money << endl;

		}

	}

	else cout << "��û��¼���κγ�������Ϣ�����ز˵�" << endl;

	cout << "���������" << endl;

	char z = _getch();

	Menu();

}

void Management::Menu()//�˵�

{



	system("cls");



	cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n"

		<< "=================**1.���복������Ϣ**=================\n"

		<< "=================**2.��Ϣ��ѯ**=======================\n"

		<< "=================**3.�����ǰ������Ϣ**===============\n"

		<< "=================**4.�༭��Ϣ**=======================\n"

		<< "=================**5.ɾ������**=======================\n"

		<< "=================**6 ������**=======================\n"

		<< "=================**7.ͳ�ƹ���**=======================\n"

		<< "=================**8.д���ļ�**=======================\n"

		<< "=================**9.��ȡ�ļ�**=======================\n"

		<< "=================**10.������Ϣ**=======================\n"

		<< "=================**11.�˳�ϵͳ**=======================\n" << endl;

	int x;cout << "��������Ҫ�������ţ�";

	cin >> x;

	switch (x)

	{

	case 1:cout << "***************�����복����Ϣ��****************" << endl;Getinfor();break;

	case 2:cout << "***************����ѯ������Ϣ��****************" << endl;Searinfor();break;

	case 3:cout << "  *************�����������Ϣ��****************" << endl;Showinfor();break;

	case 4:cout << "***************���༭������Ϣ��****************" << endl;Ediinfor();break;

	case 5:cout << "***************��ɾ��������Ϣ��****************" << endl;Delinfor();break;

	case 6:cout << "***************����������Ϣ��****************" << endl; Sort();;break;

	case 7:cout << "***************��ͳ�Ƴ�����Ϣ��****************" << endl; Calinfor();break;

	case 8:cout << "***************��д���ļ���********************" << endl; write();break;

	case 9:cout << "******************����ȡ�ļ���*****************" << endl;read();break;

	case 10:cout << "******************��������Ϣ��*****************" << endl;Store();break;

	case 11:cout << "******************���˳�ϵͳ��*****************" << endl;cout << setw(10) << "*��";Sleep(200);cout << "л";Sleep(200);cout << "��";Sleep(200);cout << "��";Sleep(200);cout << "ʹ";Sleep(200);cout << "�ã�*";Sleep(200);exit(0);break;

	default:cout << "�������������������������" << endl;Sleep(200);Menu();

		break;

	}

}

/*void Management::read()//������

{

	while (1)

	{

		ifstream read("d:\\project\\���ݿγ����\\infor.txt", ios::in);

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

			ofstream out("d:\\project\\���ݿγ����\\information.txt");

			out.close();

		}

		Menu();

	}



	present = n1 + n2 + n3;

}

void Management::write()//д����

{

	ofstream write;

	write.open("d:\\project\\���ݿγ����\\information.txt", ios::out);

	if (write)

	{

		for (int i = 0; i < present; i++)

		{

			cout << "*";Sleep(100);cout << "*";Sleep(100);cout << "*";Sleep(100);cout << "*";Sleep(100);cout << "*";Sleep(100);cout << "*";Sleep(100);cout << "*";Sleep(100);cout << "*";Sleep(100);cout << "*";Sleep(100); cout << endl;
			cout << "��" << i + 1 << "��д����ɣ�" << endl;
			write <<t[i].Type<<setw(8)<< t[i].Number << setw(8) << t[i].carnum << setw(8) << t[i].cname << setw(8) << t[i].km << setw(8) << t[i].V << setw(8) << t[i].B << setw(8) << t[i].T << setw(5) << t[i].C << setw(8) << t[i].year << setw(5) << t[i].month << setw(5) << t[i].day << t[i].ymoney << setw(8) << t[i].total_money << endl;
		}
		write.close();

	}

	else cout << "д��ʧ�ܣ�" << endl;

	cout << "�����������";char z = _getch();Menu();

}
*/
void Management::Store()//����

{

	int  M;

	cout << "�Ƿ�ȷ�ϱ��棿";cin >> M;//�ж��Ƿ񱣴���Ϣ

	if (M == 1)

	{

		cout << "��ʼ����" << endl;

	}

	else Menu();

	ofstream fileout("d:\\project\\���ݿγ����\\store.txt", ios::trunc);

	fileout.close();

	ofstream write("d:\\project\\���ݿγ����\\store.txt");

	cout << "*";Sleep(180);cout << "*";Sleep(180);cout << "*";cout << "*";Sleep(180);cout << "*";Sleep(180);cout << "*";Sleep(180);cout << "*";Sleep(180);cout << "*";Sleep(180);cout << "*";Sleep(180);cout << "*";Sleep(180); cout << endl;

	cout << "������ɣ�" << endl;

	for (int i = 0;i < present;i++)

	{

		write << "****��������ϢΪ��\n"

			<< "����" << setw(5) << "���" << setw(8) << "����" << setw(8) << "��˾" << setw(8) << "���" << setw(8) << "����" << setw(8) << "�ؿ���" << setw(8) << "����" << setw(8) << "����" << setw(8) << "����" << endl;

		write << t[i].Type << setw(5) << t[i].Number << setw(8) << t[i].carnum << setw(8) << t[i].cname << setw(8) << t[i].km << setw(8) << t[i].V << setw(8) << t[i].B << setw(8) << t[i].T << setw(5) << t[i].C << setw(8) << t[i].year << "-" << t[i].month << "-" << t[i].day << endl;

	}

	write.close();

	cout << "�ѱ�����Ϣ��" << endl;

	Sleep(600);

	Menu();

}

int main()

{

	Management mc;

	cout << "--*---*---*--*---*---*----*----*---*---*---*---*---*-----*\n"

		<< "|**********************************************************|\n"

		<< "|**********************************************************|\n"

		<< "|*************   !��ӭ������������ϵͳ��  *****************|\n"

		<< "|**********************************************************|\n"

		<< "|**********************************************************|\n"

		<< "--*---*---*--*---*---*----*----*---*---*---*---*---*-----*\n" << endl;

	cout << "�������������" << endl;

	char z = _getch();

	mc.Menu();

	return 0;

}

/*void Management::read()

{

	fstream f;

	f.open("d:\\project\\���ݿγ����\\information.txt", ios::in);

	if (!f)

	{

		cerr << "���ļ�����" << endl;

		Sleep(200);Menu();

	}

	
        cout << "*";Sleep(180);cout << "*";Sleep(180);cout << "*";cout << "*";Sleep(180);cout << "*";Sleep(180);cout << "*";Sleep(180);cout << "*";Sleep(180);cout << "*";Sleep(180);cout << "*";Sleep(180);cout << "*";Sleep(180); cout << endl;
		cout << "��ȡ��ɣ�";
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
	ofstream f("d:\\project\\���ݿγ����\\binary.dat", ios::binary);
	if (!f)
	{
		cout << "�����ļ�ʧ��!"<<endl;
		return;
	}
	f.write((char*)t, 3 * sizeof(Trans));present = n1 + n2 + n3;f << present;
	cout << "д��ɹ�" << endl;
	system("pause");
	f.close();
	Sleep(200);Menu();
}
void Management::read()
{
	ifstream f("d:\\project\\���ݿγ����\\binary.dat", ios::binary);
	if (!f)
	{
		cout << "��ȡ�ļ�ʧ��" << endl;
		
	}
	f.read((char*)t, 3 * sizeof(Trans));f >> present;
	f.close();
	cout << "��ȡ���" << endl;
	system("pause");
	Sleep(200);Menu();
}