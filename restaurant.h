const int MAXSIZE=100;
typedef struct Dishes
{
	int price;
    char name[20];
    long nums;
}dishes;
//生成账单
typedef struct Check
{
    int total;
}check;
//消费者信息
class Customer
{
	int tabnums;//桌号
    long quenums;//排队号
    dishes cdish[MAXSIZE];	
public:
	Check ch;//账单
	Customer(long x=0,long y=0);
	static int dishamounts;//当前菜品的数量
	static long present_quenums;//记录当前排队号
	void order_dishes(char na[],dishes di[]);//按菜品编号点菜
	void print();//打印账单
	int Pay();//计算支付金额
	friend class Manger;
};
//系统菜单,管理员身份进入
//类的职责要分明不能将他们强行塞入一个类中
class Menu
{
   static int dishesnums;//当前的菜品数量
   friend class Manger;
   friend  class Customer;
public:
    dishes di[MAXSIZE];//用顺序表存储菜品
};
class Manger
{
	 Customer c[150];
public:
	static int present_custnums;
   	void add_dishes(int i,dishes x);//添加菜品
	void delete_dishes(int i);//删除指定位置i处的元素
	void serch_dishes(long nums);//按编号查找
    void add_customer();//添加顾客
    void PrintMenu();
    void UserInterface();
	void Manageinterface();
	void Print_customer();//打印消费者信息
	//friend class Customer;
    friend void Customerinterface(dishes di[],Customer c[]);
};