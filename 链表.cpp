#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <fstream>

using namespace std;
#define black 1 //1������� 
#define small 2 //2����С���� 
#define big 3 //3����󻨰��� 

#define ok 1
#define error 0
int total;//��������� 
int money,amoney;
int heinum,xiaonum,danum;

int a[100]; 




typedef struct LNode {
	int places;
	int num;
	int species;
	double weigh;
	int days=1;
	bool overweight=false;
	bool overdays=false;
	bool death=false;
	bool ill=false;
	int indivisual_price;
	struct LNode *next;
	~LNode(){
		if(species==1) {
			money+=15*weigh;
			amoney+=15*weigh;
		}
		if(species==2) {
			money+=7*weigh;
			amoney+=7*weigh;
		}
		if(species==3) {
			money+=6*weigh;
			amoney+=6*weigh;
		}
		a[places]--;
		fstream outfile("buy_and_sell_data.txt",ios::app);
		string temp;
		temp="������";
		outfile<<temp;
		outfile<<endl;
		temp="���Ʒ��Ϊ��";
		outfile<<temp;
		outfile<<species;
		outfile<<endl;
		temp="�������Ϊ��";
		outfile<<temp;
		outfile<<weigh;
		outfile<<endl;
		temp="��ĳɳ�����Ϊ��";
		outfile<<temp;
		outfile<<days;
		outfile<<endl;
		temp="�����Ȧ��Ϊ��";
		outfile<<temp;
		outfile<<places;
		outfile<<endl;
		temp="��ı��Ϊ��";
		outfile<<temp;
		outfile<<num;
		outfile<<endl; 
		temp="����ļ۸�Ϊ��";
		outfile<<temp;
		outfile<<amoney;
		outfile<<endl; 
		amoney=0;
	} 
}LNode, *LinkList;

int creat(LinkList &L) {
	L = new LNode;
	L->next = NULL;
	int  i,b,x,d;
	cout << "�������ʼ������ĸ�����" ;
	cin >>b;
	cout << "�������ʼ��С����ĸ�����";
	cin>>x;
	cout << "�������ʼ���󻨰���ĸ�����";
	cin >>d;
	total=b+x+d; 
	for (i = 1; i <=b; i++) {
		LNode *p;
		p = new LNode;
		p->species=1;
		p->next = L->next;
		L->next = p;
	}
	for (i = 1; i <=x; i++) {
		LNode *p;
		p = new LNode;
		p->species=2;
		p->next = L->next;
		L->next = p;
	}
	for (i = 1; i <=d; i++) {
		LNode *p;
		p = new LNode;
		p->species=3;
		p->next = L->next;
		L->next = p;
	}
	return ok;
}


bool overflow(LNode *p,int n){
	bool t1=false;
	int count=1;
	while(p!=NULL){
		if(p->places==n) count++;
		if(count==10){
			t1=true;
			break;
		}
		p=p->next;
	}
	return t1;
}
void buy(LinkList &L,int b,int all) {//�����µ��� 
	LNode *e;
	LNode *p = L;
	int pl,b1,x,d;
	int per=b/all+1;
	cout << "�����빺��ĺ���ĸ�����" ;
	cin >>b1;
	cout << "�����빺���С����ĸ�����";
	cin>>x;
	cout << "�����빺��Ĵ󻨰���ĸ�����";
	cin >>d;
	for(int i=0;i<b1;i++){
		e = new LNode;
		e->next = p->next;
		p->next = e;
		p=L;
		e->species=1;
		e->weigh=(rand()%301+200)/10.0;
		while(1){
			pl=rand()%(per+1);
			if(a[pl]>9) continue;
			else {
				e->places=pl;
				e->num=a[pl];
				a[pl]++;
				break;
				}
			}
		fstream outfile1("buy_and_sell_data.txt",ios::app);
		string temp;
		temp="������";
		outfile1<<temp;
		outfile1<<endl;
		temp="���Ʒ��Ϊ��";
		outfile1<<temp;
		outfile1<<e->species;
		outfile1<<endl;
		temp="�������Ϊ��";
		outfile1<<temp;
		outfile1<<e->weigh;
		outfile1<<endl;
		temp="��ĳɳ�����Ϊ��";
		outfile1<<temp;
		outfile1<<e->days;
		outfile1<<endl;
		temp="�����Ȧ��Ϊ��";
		outfile1<<temp;
		outfile1<<e->places;
		outfile1<<endl;
		temp="��ı��Ϊ��";
		outfile1<<temp;
		outfile1<<e->num;
		outfile1<<endl; 
		temp="����ļ۸�Ϊ��";
		outfile1<<temp;
		outfile1<<amoney;
		outfile1<<endl; 
		amoney=0;
	    p=p->next;
	}
	for(int i=0;i<x;i++){
		e = new LNode;
		e->next = p->next;
		p->next = e;
		p=L;
		e->species=2;
		e->weigh=(rand()%301+200)/10.0;
		while(1){
			pl=rand()%(99-per)+per+1;
			if(a[pl]>9) continue;
			else {
				e->places=pl;
				e->num=a[pl];
				a[pl]++;
				break;
				}
			}
		fstream outfile2("buy_and_sell_data.txt",ios::app);
		string temp;
		temp="������";
		outfile2<<temp;
		outfile2<<endl;
		temp="���Ʒ��Ϊ��";
		outfile2<<temp;
		outfile2<<e->species;
		outfile2<<endl;
		temp="�������Ϊ��";
		outfile2<<temp;
		outfile2<<e->weigh;
		outfile2<<endl;
		temp="��ĳɳ�����Ϊ��";
		outfile2<<temp;
		outfile2<<e->days;
		outfile2<<endl;
		temp="�����Ȧ��Ϊ��";
		outfile2<<temp;
		outfile2<<e->places;
		outfile2<<endl;
		temp="��ı��Ϊ��";
		outfile2<<temp;
		outfile2<<e->num;
		outfile2<<endl; 
		temp="����ļ۸�Ϊ��";
		outfile2<<temp;
		outfile2<<amoney;
		outfile2<<endl; 
		amoney=0;
		p=p->next;
	}
	for(int i=0;i<d;i++){
		e = new LNode;
		e->next = p->next;
		p->next = e;
		p=L;
		e->species=3;
		e->weigh=(rand()%301+200)/10.0;
		while(1){
			pl=rand()%(99-per)+per+1;
			if(a[pl]>9) continue;
			else {
				e->places=pl;
				e->num=a[pl];
				a[pl]++;
				break;
				}
			}
		p=p->next;
	}
	
	}


int print(LinkList &L) 
{
	LNode *p;
	p = L->next;
	while (p!=NULL) {
		cout<<"���Ʒ�֣�"<<p->species<<endl;
		cout<<"������أ�"<<p->weigh<<setprecision(3)<<endl; 
		cout<<"��ĳɳ�������"<<p->days<<endl;
		cout<<"�����Ȧ�ţ�"<<p->places<<endl;
		cout<<"��ı�ţ�"<<p->num<<endl;
		cout<<endl;
		p = p->next;	
	}
	return ok;
}

int black_count(LinkList &L){//ͳ�ƺ�������� 
	int num_black=0;
	LNode *p;
	p=L->next;
	while(p!=NULL){
		if(p->species==1) num_black++;
		p=p->next;
	}
	return num_black;
}


void search_place(LinkList &L,int n){
	LNode *p;
	p=L->next;
	bool flag=0;
	int count=0,num1=0,num2=0,num3=0;
	while(p!=NULL){
		if(p->places==n){
			flag=1;
			count++;
			if(p->species==1) num1++;
			if(p->species==2) num2++;
			if(p->species==3) num3++;
		}
		p=p->next;
	}
	if(flag==0) cout<<"��Ǹ������ȦΪ��"<<endl;
	else{
			cout<<"���������Ϊ��"<<count<<endl;
			cout<<"���������Ϊ��"<<num1<<endl;
			cout<<"С���������Ϊ��"<<num2<<endl;
			cout<<"�󻨰��������Ϊ��"<<num3<<endl;
		}
		
	}

void search_pigs(LinkList &L,int place,int number){
	LNode *p;
	p=L->next;
	bool flag=0;
	while(p!=NULL){
		if(p->places==place&&p->num==number){
			flag=1;
			cout<<"�����������Ϊ��"<<p->weigh<<endl;
			cout<<"������ĳɳ�����Ϊ��"<<p->days<<endl;
			break; 
		}
		p=p->next;
	}
	if(flag==0) cout<<"��Ǹ����������"<<endl;
}

void initial_assign(LinkList &L,int b,int all){//��ʼ�������Ȧ�ͱ�ź����� 
	int n=0;
	LNode *p;
	p=L->next;
	int per=100*b/all+1,pl;
	while(p!=NULL){
		p->weigh=(rand()%301+200)/10.0;
		if(p->species==1){
			while(1){
				pl=rand()%(per+1);
				if(a[pl]>9) continue;
				else {
					p->places=pl;
					p->num=a[pl];
					a[pl]++;
					break;
				}
			}
		}
		else{
			while(1){
				pl=rand()%(99-per)+per+1;
				if(a[pl]>9) continue;
				else {
					p->places=pl;
					p->num=a[pl];
					a[pl]++;
					break;
				}
			}
		}
		p=p->next;
		}
	}

void grow(LinkList &L,int n){//��ʾÿ����������,�����ж��Ƿ��� 
	LNode *p;
	for(int i=0;i<n;i++){
		p=L->next;
		while(p!=NULL){
			if(p->days>=365) p->overdays=true;
			if(p->weigh>50) p->overweight=true;
			if(p->overweight==false){
				p->weigh+=(rand()%13)/10.0;
			}
			if(p->overdays==false){
				p->days++;
			}
			p=p->next;
		}
	}
}

void sell(LinkList &L){//�ж����Ƿ�ﵽ���۵ı�׼�����ﵽ��ɾ���ڵ㣬������ 
	LNode *p;
	LNode *h;
	p=L->next;
	h=L;
	while(p!=NULL){
		if(p->overdays==true||p->overweight==true){
			h->next=p->next;
			delete p;
			p=h->next;
		}
		else{
			h=p;
			p=p->next;
		}
	}
}

void search_species(LinkList &L,int n){
	LNode *p;
	p=L->next;
	int weigh[3];//��10Ϊ���䳤�ȣ���20-50��Ϊ��������
	int days[8];//��50Ϊ���䳤�Ƚ�1-365�ֳɰ˸����� 
	memset(weigh,0,sizeof(weigh));
	memset(days,0,sizeof(days));
	int count=0;
	while(p!=NULL){
		if(p->species==n){
			count++;
			if(20<=p->weigh&&30>p->weigh) weigh[0]++;
			if(30<=p->weigh&&40>p->weigh) weigh[1]++;
			if(40<=p->weigh&&50>p->weigh) weigh[2]++;
			if(1<=p->days&&50>p->days) days[0]++;
			if(50<=p->days&&100>p->days) days[1]++;
			if(100<=p->days&&150>p->days) days[2]++;
			if(150<=p->days&&200>p->days) days[3]++;
			if(200<=p->days&&250>p->days) days[4]++;
			if(250<=p->days&&300>p->days) days[5]++;
			if(300<=p->days&&350>p->days) days[6]++;
			if(350<=p->days&&365>p->days) days[7]++;
		}
		p=p->next;
	}
	if(count==0){
		cout<<"��Ǹ���޷����ҵ���Ʒ�ֵ���"<<endl;
		return;
	}
	cout<<"��Ʒ�ֵ��������Ϊ��"<<count<<endl;
	cout<<"������[20,30)֮������У�"<<weigh[0]<<endl; 
	cout<<"������[30,40)֮������У�"<<weigh[1]<<endl;
	cout<<"������[40,50]֮������У�"<<weigh[2]<<endl; 
	cout<<"�ɳ�������[1,50)�����У�"<<days[0]<<endl;
	cout<<"�ɳ�������[50,100)�����У�"<<days[1]<<endl;
	cout<<"�ɳ�������[100,150)�����У�"<<days[2]<<endl;
	cout<<"�ɳ�������[150,200)�����У�"<<days[3]<<endl;
	cout<<"�ɳ�������[200,250)�����У�"<<days[4]<<endl;
	cout<<"�ɳ�������[250,300)�����У�"<<days[5]<<endl;
	cout<<"�ɳ�������[300,350)�����У�"<<days[6]<<endl;
	cout<<"�ɳ�������[350,365]�����У�"<<days[7]<<endl;
}




void store_all(LinkList &L){
	ofstream outfile("lth.txt");
	string temp;
	LNode *p;
	p=L->next;
	while(p!=NULL){

		outfile<<p->species;
		outfile<<" ";
		outfile<<p->weigh;
		outfile<<" ";
		outfile<<p->days;
		outfile<<" ";
		outfile<<p->places;
		outfile<<" ";
		outfile<<p->num;
		if(p->next==NULL) break;
		outfile<<endl;
		p=p->next;
	}
}

void read_all(LinkList &L){
	L=new LNode;
	L->next=NULL; 
	char buff[300];
	double temp;
	ifstream infile("lth.txt",ios::in);
	while(!infile.eof()){
		LNode *p;
		p = new LNode;
		p->next = L->next;
		L->next = p;
		for(int i=0;i<5;i++){



		infile>>temp;
		switch(i){
			case 0:
				p->species=temp;
				break;
			case 1:
				p->weigh=temp;
				break;
			case 2:
				p->days=temp;
				break;
			case 3:
				p->places=temp;
				break;
			case 4:
				p->num=temp;
				break;
		}
		}

	}
}

int getnum(LinkList &L){
	LNode *p;
	p=L->next;
	int count=0;
	while(p!=NULL){
		count++;
		p=p->next;
	}
	return count;
}






int main()
{
	srand((int)time(NULL));
	LinkList p;
	read_all(p);
	int out = 1, choice,bnum,elsenum,groday,newnum,spn,exp,exn,findsp;
	while (out) {
		cout << endl << "##########��ӭ������е�������##########"; 
		cout << endl << "-----������룺1";
		cout << endl << "-----С������룺2";
		cout << endl << "-----�󻨰�����룺3"; 
		cout << endl << "1----------------��ʼ������";
		cout << endl << "2----------------��ѯĳһ��Ȧ�����";
		cout << endl << "3----------------��ѯĳһͷ��";
		cout << endl << "4----------------��������";
		cout << endl << "5----------------��ѯĳһƷ�ֵ�����";
		cout << endl << "6----------------��ʾ��������";
		cout << endl << "7----------------����ɳ���";
		cout << endl << "0----------------�����뿪����";
		cout << endl << "��ѡ��:";
		cin >> choice;
		switch (choice) {
		case 1: 
			memset(a,0,sizeof(a));
			creat(p); 
			bnum=black_count(p);
			elsenum=total-bnum;
			initial_assign(p,bnum,total);
			break;
		
		case 2:
			cout<<"��Ҫ��ѯ����Ȧ�ı�ţ�";
			cin>>spn;
			search_place(p,spn);
			break;
		
		case 3:
			cout<<"��Ҫ��ѯ�������Ȧ�ţ�";
			cin>>exp;
			cout<<"��Ҫ��ѯ����ı�ţ�";
			cin>>exn;
			search_pigs(p,exp,exn);
			break;
		
		
		
		case 4:
			buy(p,bnum,total);
			break;
			
		case 5:
			cout<<"��ѯ��������ࣺ";
			cin>>findsp;
			search_species(p,findsp);
			break;
		
		case 6: 
			print(p);
			cout<<"���������Ϊ��"<<black_count(p); 
			break;
		
		case 7:
			cout<<"����������ɳ�������Ϊ��";
			cin>> groday;
			grow(p,groday);
			sell(p);
			cout<<"������ڵ�����Ϊ��"<<money;
			money=0;
		
		case 8:
			int t1=getnum(p);
			int t2=rand()%(t1+1);
			virus_days(p,t1,t2);
			
			
			
		case 0:
			store_all(p);
			break;
	}
}
}
