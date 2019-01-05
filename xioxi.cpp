/*新增一个菜品：包括单价，菜名，菜的简介。
可添加的功能：1.推荐特色菜，特价菜，以及优惠大酬宾。
2.几号桌目前是空，可以坐几个人。
账单；*/
//菜品信息
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
Menu m1;//全局对象
int GetRandomNumber()
{
	int RandomNumber;
	srand((unsigned)time(NULL));//time()用系统时间初始化种。为rand()生成不同的随机种子。
	RandomNumber = rand() % 100 + 1;//生成1~100随机数
	return RandomNumber;
}
void Manger::add_customer()
{
	int x=GetRandomNumber();
	Customer *ptr;
	ptr=new Customer(x,++Customer::present_quenums);
	c[present_custnums++]=*ptr;
	cout<<"桌号:"<<x<<setw(10)<<"排队号:"<<Customer::present_quenums<<endl;
    delete ptr;
}
void Manger::Print_customer()
{
	int i;
	cout<<"所有消费者的消费清单如下："<<endl;
	cout<<"排队号"<<setw(10)<<"桌号"<<setw(15)<<"消费金额"<<endl;
	for(i=0;i<present_custnums;i++)
	cout<<c[i].quenums<<setw(15)<<c[i].tabnums<<setw(15)<<c[i].ch.total<<endl;	
}
void Manger::add_dishes(int i,dishes x)//插入的位置,以及菜品的相关信息
{
	int j;
	if(Menu::dishesnums==MAXSIZE-1)
		cout<<"菜单容量已达上限"<<endl;
	if(i<=0||i>Menu::dishesnums+2)//留出i=0那个空间
		cout<<"插入的位置不合理"<<endl;
	else
		for(j=Menu::dishesnums;j>=i+1;j--)
			m1.di[j+1]=m1.di[j];//腾出插入的空间
      m1.di[i]=x;
	  Menu::dishesnums++;
}
void Manger::delete_dishes(int i)
{
	int j;
	if(i<1||i>Menu::dishesnums)
		cout<<"不存在该菜品"<<endl;
	else
	cout<<"要删除的菜品信息如下:"<<endl;
	cout<<m1.di[i].nums<<setw(15)<<m1.di[i].name<<setw(15)<<m1.di[i].price<<endl;
	for(j=i+1;j<=Menu::dishesnums;j++)
		m1.di[j-1]=m1.di[j];
	Menu::dishesnums--;
}
void Manger::PrintMenu()
{
	int i;
	cout<<setw(15)<<"*****菜       单*****"<<endl;
	cout<<"菜品编号"<<setw(15)<<"菜名"<<setw(15)<<"价格"<<endl;
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
		cout<<"不存在该菜品"<<endl;
	else
		cout<<m1.di[i].nums<<setw(15)<<m1.di[i].name<<setw(15)<<m1.di[i].price<<endl;
}
void firstmenu()
{
    cout<<"**********欢迎进入餐厅管理系统**********"<<endl;
    cout<<setw(25)<<"请选择您的身份:"<<endl;
    cout<<setw(20)<<"1.消费者"<<endl;
    cout<<setw(20)<<"2.管理员"<<endl;
    cout<<setw(20)<<"0.退出"<<endl;
}
void CustomerMenu()
{
	cout<<"*****欢 迎 进 入 点 菜 系 统*****"<<endl;
	cout<<"您可以选择如下操作"<<endl;
    cout<<"****1.点菜****"<<endl;
    cout<<"****2.打印所点菜的信息****"<<endl;
    cout<<"****3.结账****"<<endl;//打印出消费账单。
	cout<<"****0.退出系统****"<<endl;
}
void ManageMenu()
{
    cout<<"****欢迎进入管理员界面****"<<endl;
		cout<<"****1.添加菜品****"<<endl;
        cout<<"****2.添加顾客****"<<endl;
        cout<<"****3.删除菜品****"<<endl;
        cout<<"****4.查找菜品****"<<endl;
        cout<<"****5.显示菜品信息****"<<endl;
		cout<<"****6.打印消费者信息****"<<endl;
        cout<<"****0.退出系统****"<<endl;
        cout<<"****请选择您的操作****"<<endl;
}
void Manger::Manageinterface()//管理员界面
{
    int times=3,m=1,n;
	char password[5];//以管理员身份进入时，要登录。
	cout<<"****欢 迎 进 入 管 理 员 界 面，请 输 入 密 码****"<<endl;
        cin>>password;
      do
      {    
		  times--;
		  if(strcmp(password,"11111")!=0&&times>0)
		  {
			   cout<<"您输入的密码有误，"<<"您还有"<<times<<"次机会可重新输入"<<endl;
		      cin>>password;
		  }
      }while(strcmp(password,"11111")!=0&&times>0);
	if(times==0)
		cout<<"您的管理员身份有误,请核实后登陆"<<endl;
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
				cout<<"请输入待插入的菜品信息(依次为菜名、价格、编号)"<<endl;
				cin>>x.name>>x.price>>x.nums;
				cout<<"请输入要插入的位置"<<endl;
				cin>>n;
				add_dishes(n,x);
			     break;
			    }
        case 2:
               {
				cout<<"您好!系统为您生成的排队号，桌号为:"<<endl;
                add_customer();
                break;
               }
		case 3:{
			     int n;
				 cout<<"请输入要删除的菜品的位置"<<endl;
			     cin>>n;
				 delete_dishes(n);
				 break;
			   }
		case 4:{
			    long nums;
			cout<<"请输入要查找的菜品的编号"<<endl;
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
void Manger::UserInterface()//用户界面
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
		cout<<"不存在该菜品,请重新输入菜品对应编号"<<endl;
	}
	else if(strcmp(na,m1.di[i].name)==0)
	{
		cdish[i]=m1.di[i];
		dishamounts++;
		cout<<"点菜成功,所点菜的信息如下"<<endl;
		print();
	}
}
void Customer::print()
{
	int i;
	cout<<setw(10)<<"您的桌号为"<<tabnums<<setw(10)<<"您的排队号为"<<quenums<<endl;
	cout<<setw(10)<<"您所点的菜品为:"<<endl;
		cout<<"编号"<<setw(15)<<"菜名"<<setw(15)<<"价格"<<endl;
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
	cout<<"请按照系统生成的号码依次输入您的桌号，排队号"<<endl;
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
				cout<<"请输入您要点的菜名"<<endl;
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
			  cout<<"以下为您的消费情况:"<<endl;
			  c1.print();
			  c1.ch.total=c1.Pay();
			  c[Manger::present_custnums-1]=c1;
			  cout<<"合计："<<"您本次一共消费"<<c1.Pay()<<"元"<<endl;
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


