/*����һ����Ʒ���������ۣ��������˵ļ�顣
����ӵĹ��ܣ�1.�Ƽ���ɫ�ˣ��ؼ۲ˣ��Լ��Żݴ�����
2.������Ŀǰ�ǿգ������������ˡ�
�˵���*/
//��Ʒ��Ϣ
#include<iostream.h>
#include<string.h>
#include<iomanip.h>
#include<time.h>
#include<stdlib.h>
#include"restaurant.h"
int Menu::dishesnums=0;
int Customer::dishamounts=0;
long Customer::present_quenums=001;
int Manger::present_custnums=0;
Menu m1;//ȫ�ֶ���
int GetRandomNumber()
{
	int RandomNumber;
	srand((unsigned)time(NULL));//time()��ϵͳʱ���ʼ���֡�Ϊrand()���ɲ�ͬ��������ӡ�
	RandomNumber = rand() % 100 + 1;//����1~100�����
	return RandomNumber;
}
void Manger::add_customer()
{
	int x=GetRandomNumber();
	Customer *ptr;
	ptr=new Customer(x,++Customer::present_quenums);
	c[present_custnums++]=*ptr;
	cout<<"����:"<<x<<setw(10)<<"�ŶӺ�:"<<Customer::present_quenums<<endl;
    delete ptr;
}
void Manger::Print_customer()
{
	int i;
	cout<<"���������ߵ������嵥���£�"<<endl;
	cout<<"�ŶӺ�"<<setw(10)<<"����"<<setw(15)<<"���ѽ��"<<endl;
	for(i=0;i<present_custnums;i++)
	cout<<c[i].quenums<<setw(15)<<c[i].tabnums<<setw(15)<<c[i].ch.total<<endl;	
}
void Manger::add_dishes(int i,dishes x)//�����λ��,�Լ���Ʒ�������Ϣ
{
	int j;
	if(Menu::dishesnums==MAXSIZE-1)
		cout<<"�˵������Ѵ�����"<<endl;
	if(i<=0||i>Menu::dishesnums+2)//����i=0�Ǹ��ռ�
		cout<<"�����λ�ò�����"<<endl;
	else
		for(j=Menu::dishesnums;j>=i+1;j--)
			m1.di[j+1]=m1.di[j];//�ڳ�����Ŀռ�
      m1.di[i]=x;
	  Menu::dishesnums++;
}
void Manger::delete_dishes(int i)
{
	int j;
	if(i<1||i>Menu::dishesnums)
		cout<<"�����ڸò�Ʒ"<<endl;
	else
	cout<<"Ҫɾ���Ĳ�Ʒ��Ϣ����:"<<endl;
	cout<<m1.di[i].nums<<setw(15)<<m1.di[i].name<<setw(15)<<m1.di[i].price<<endl;
	for(j=i+1;j<=Menu::dishesnums;j++)
		m1.di[j-1]=m1.di[j];
	Menu::dishesnums--;
}
void Manger::PrintMenu()
{
	int i;
	cout<<setw(15)<<"*****��       ��*****"<<endl;
	cout<<"��Ʒ���"<<setw(15)<<"����"<<setw(15)<<"�۸�"<<endl;
	for(i=1;i<=Menu::dishesnums;i++)
	{
		cout<<m1.di[i].nums<<setw(25)<<m1.di[i].name<<setw(15)<<m1.di[i].price<<endl;
	}
}
void Manger::serch_dishes(long nums)
{
	int i=1;
	while(m1.di[i].nums!=nums&&i<=Menu::dishesnums)
		i++;
	if(i>Menu::dishesnums)
		cout<<"�����ڸò�Ʒ"<<endl;
	else
		cout<<m1.di[i].nums<<setw(15)<<m1.di[i].name<<setw(15)<<m1.di[i].price<<endl;
}
void firstmenu()
{
    cout<<"**********��ӭ�����������ϵͳ**********"<<endl;
    cout<<setw(25)<<"��ѡ���������:"<<endl;
    cout<<setw(20)<<"1.������"<<endl;
    cout<<setw(20)<<"2.����Ա"<<endl;
    cout<<setw(20)<<"0.�˳�"<<endl;
}
void CustomerMenu()
{
	cout<<"*****�� ӭ �� �� �� �� ϵ ͳ*****"<<endl;
	cout<<"������ѡ�����²���"<<endl;
    cout<<"****1.���****"<<endl;
    cout<<"****2.��ӡ����˵���Ϣ****"<<endl;
    cout<<"****3.����****"<<endl;//��ӡ�������˵���
	cout<<"****0.�˳�ϵͳ****"<<endl;
}
void ManageMenu()
{
    cout<<"****��ӭ�������Ա����****"<<endl;
		cout<<"****1.��Ӳ�Ʒ****"<<endl;
        cout<<"****2.��ӹ˿�****"<<endl;
        cout<<"****3.ɾ����Ʒ****"<<endl;
        cout<<"****4.���Ҳ�Ʒ****"<<endl;
        cout<<"****5.��ʾ��Ʒ��Ϣ****"<<endl;
		cout<<"****6.��ӡ��������Ϣ****"<<endl;
        cout<<"****0.�˳�ϵͳ****"<<endl;
        cout<<"****��ѡ�����Ĳ���****"<<endl;
}
void Manger::Manageinterface()//����Ա����
{
    int times=3,m=1,n;
	char password[5];//�Թ���Ա��ݽ���ʱ��Ҫ��¼��
	cout<<"****�� ӭ �� �� �� �� Ա �� �棬�� �� �� �� ��****"<<endl;
        cin>>password;
      do
      {    
		  times--;
		  if(strcmp(password,"11111")!=0&&times>0)
		  {
			   cout<<"���������������"<<"������"<<times<<"�λ������������"<<endl;
		      cin>>password;
		  }
      }while(strcmp(password,"11111")!=0&&times>0);
	if(times==0)
		cout<<"���Ĺ���Ա�������,���ʵ���½"<<endl;
	else
	{
	    while(m)
        {
            ManageMenu();
            cin>>n;
            switch(n)
            {
          case 1:
			    {
				dishes x;
				int n;
				cout<<"�����������Ĳ�Ʒ��Ϣ(����Ϊ�������۸񡢱��)"<<endl;
				cin>>x.name>>x.price>>x.nums;
				cout<<"������Ҫ�����λ��"<<endl;
				cin>>n;
				add_dishes(n,x);
			     break;
			    }
        case 2:
               {
				cout<<"����!ϵͳΪ�����ɵ��ŶӺţ�����Ϊ:"<<endl;
                add_customer();
                break;
               }
		case 3:{
			     int n;
				 cout<<"������Ҫɾ���Ĳ�Ʒ��λ��"<<endl;
			     cin>>n;
				 delete_dishes(n);
				 break;
			   }
		case 4:{
			    long nums;
			cout<<"������Ҫ���ҵĲ�Ʒ�ı��"<<endl;
			     cin>>nums;
			serch_dishes(nums);
			break;
			   }
		case 5:{
			PrintMenu();
			break;
			   }
		case 6:
			{
				Print_customer();
				break;
			}
		case 0:m=0;
            }
        }
	}
}
void Manger::UserInterface()//�û�����
{
    int sel,m=1;
    while(m)
    {
        firstmenu();
        cin>>sel;
        switch(sel)
        {
       case 1: Customerinterface(m1.di,c);
                  break;
       case 2: Manageinterface();
               break;
       case 0:m=0;
        }
    }
}
Customer::Customer(long x,long y)
{
	tabnums=x;
	quenums=y;
}
void Customer::order_dishes(char na[],dishes di[])
{
	int i=1;
	while(strcmp(na,di[i].name)!=0&&i<=Menu::dishesnums)
		i++;
	if(i>Menu::dishesnums)
	{
		cout<<"�����ڸò�Ʒ,�����������Ʒ��Ӧ���"<<endl;
	}
	else if(strcmp(na,m1.di[i].name)==0)
	{
		cdish[i]=m1.di[i];
		dishamounts++;
		cout<<"��˳ɹ�,����˵���Ϣ����"<<endl;
		print();
	}
}
void Customer::print()
{
	int i;
	cout<<setw(10)<<"��������Ϊ"<<tabnums<<setw(10)<<"�����ŶӺ�Ϊ"<<quenums<<endl;
	cout<<setw(10)<<"������Ĳ�ƷΪ:"<<endl;
		cout<<"���"<<setw(15)<<"����"<<setw(15)<<"�۸�"<<endl;
	for(i=1;i<=dishamounts;i++)
	cout<<cdish[i].nums<<setw(15)<<cdish[i].name<<setw(15)<<cdish[i].price<<endl;
}
int Customer::Pay()
{
	ch.total=0;
	int i;
	for(i=1;i<=dishamounts;i++)
	ch.total+=cdish[i].price;
	return ch.total;
}
void Customerinterface(dishes di[],Customer c[])
{
    int m=1,i,x;
	long y;
	cout<<"�밴��ϵͳ���ɵĺ������������������ţ��ŶӺ�"<<endl;
	cin>>x>>y;
	Customer::present_quenums=y;
	Customer c1=c[Manger::present_custnums-1];
	while(m)
	{
		CustomerMenu();
		cin>>i;
		switch(i)
		{
		case 1:
			{
				char name[20];
				cout<<"��������Ҫ��Ĳ���"<<endl;
				cin>>name;
				c1.order_dishes(name,m1.di);
			     break;
			}
        case 2:
            {
               c1.print();
                break;
            }
		case 3:
			{
			  cout<<"����Ϊ�����������:"<<endl;
			  c1.print();
			  c1.ch.total=c1.Pay();
			  c[Manger::present_custnums-1]=c1;
			  cout<<"�ϼƣ�"<<"������һ������"<<c1.Pay()<<"Ԫ"<<endl;
				 break;
			}
		case 0:m=0;
		}
	}
}
int main()
{
	Manger m1;
   m1.UserInterface();
	return 0;
}


