const int MAXSIZE=100;
typedef struct Dishes
{
	int price;
    char name[20];
    long nums;
}dishes;
//�����˵�
typedef struct Check
{
    int total;
}check;
//��������Ϣ
class Customer
{
	int tabnums;//����
    long quenums;//�ŶӺ�
    dishes cdish[MAXSIZE];	
public:
	Check ch;//�˵�
	Customer(long x=0,long y=0);
	static int dishamounts;//��ǰ��Ʒ������
	static long present_quenums;//��¼��ǰ�ŶӺ�
	void order_dishes(char na[],dishes di[]);//����Ʒ��ŵ��
	void print();//��ӡ�˵�
	int Pay();//����֧�����
	friend class Manger;
};
//ϵͳ�˵�,����Ա��ݽ���
//���ְ��Ҫ�������ܽ�����ǿ������һ������
class Menu
{
   static int dishesnums;//��ǰ�Ĳ�Ʒ����
   friend class Manger;
   friend  class Customer;
public:
    dishes di[MAXSIZE];//��˳���洢��Ʒ
};
class Manger
{
	 Customer c[150];
public:
	static int present_custnums;
   	void add_dishes(int i,dishes x);//��Ӳ�Ʒ
	void delete_dishes(int i);//ɾ��ָ��λ��i����Ԫ��
	void serch_dishes(long nums);//����Ų���
    void add_customer();//��ӹ˿�
    void PrintMenu();
    void UserInterface();
	void Manageinterface();
	void Print_customer();//��ӡ��������Ϣ
	//friend class Customer;
    friend void Customerinterface(dishes di[],Customer c[]);
};