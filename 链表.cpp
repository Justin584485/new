#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <fstream>

using namespace std;
#define black 1 //1代表黑猪 
#define small 2 //2代表小花猪 
#define big 3 //3代表大花白猪 

#define ok 1
#define error 0
int total;//猪的总数量 
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
		temp="卖出：";
		outfile<<temp;
		outfile<<endl;
		temp="猪的品种为：";
		outfile<<temp;
		outfile<<species;
		outfile<<endl;
		temp="猪的体重为：";
		outfile<<temp;
		outfile<<weigh;
		outfile<<endl;
		temp="猪的成长天数为：";
		outfile<<temp;
		outfile<<days;
		outfile<<endl;
		temp="猪的猪圈号为：";
		outfile<<temp;
		outfile<<places;
		outfile<<endl;
		temp="猪的编号为：";
		outfile<<temp;
		outfile<<num;
		outfile<<endl; 
		temp="该猪的价格为：";
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
	cout << "请输入初始化黑猪的个数：" ;
	cin >>b;
	cout << "请输入初始化小花猪的个数：";
	cin>>x;
	cout << "请输入初始化大花白猪的个数：";
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
void buy(LinkList &L,int b,int all) {//买入新的猪 
	LNode *e;
	LNode *p = L;
	int pl,b1,x,d;
	int per=b/all+1;
	cout << "请输入购入的黑猪的个数：" ;
	cin >>b1;
	cout << "请输入购入的小花猪的个数：";
	cin>>x;
	cout << "请输入购入的大花白猪的个数：";
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
		temp="卖出：";
		outfile1<<temp;
		outfile1<<endl;
		temp="猪的品种为：";
		outfile1<<temp;
		outfile1<<e->species;
		outfile1<<endl;
		temp="猪的体重为：";
		outfile1<<temp;
		outfile1<<e->weigh;
		outfile1<<endl;
		temp="猪的成长天数为：";
		outfile1<<temp;
		outfile1<<e->days;
		outfile1<<endl;
		temp="猪的猪圈号为：";
		outfile1<<temp;
		outfile1<<e->places;
		outfile1<<endl;
		temp="猪的编号为：";
		outfile1<<temp;
		outfile1<<e->num;
		outfile1<<endl; 
		temp="该猪的价格为：";
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
		temp="卖出：";
		outfile2<<temp;
		outfile2<<endl;
		temp="猪的品种为：";
		outfile2<<temp;
		outfile2<<e->species;
		outfile2<<endl;
		temp="猪的体重为：";
		outfile2<<temp;
		outfile2<<e->weigh;
		outfile2<<endl;
		temp="猪的成长天数为：";
		outfile2<<temp;
		outfile2<<e->days;
		outfile2<<endl;
		temp="猪的猪圈号为：";
		outfile2<<temp;
		outfile2<<e->places;
		outfile2<<endl;
		temp="猪的编号为：";
		outfile2<<temp;
		outfile2<<e->num;
		outfile2<<endl; 
		temp="该猪的价格为：";
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
		cout<<"猪的品种："<<p->species<<endl;
		cout<<"猪的体重："<<p->weigh<<setprecision(3)<<endl; 
		cout<<"猪的成长天数："<<p->days<<endl;
		cout<<"猪的猪圈号："<<p->places<<endl;
		cout<<"猪的编号："<<p->num<<endl;
		cout<<endl;
		p = p->next;	
	}
	return ok;
}

int black_count(LinkList &L){//统计黑猪的数量 
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
	if(flag==0) cout<<"抱歉，该猪圈为空"<<endl;
	else{
			cout<<"猪的总数量为："<<count<<endl;
			cout<<"黑猪的数量为："<<num1<<endl;
			cout<<"小花猪的数量为："<<num2<<endl;
			cout<<"大花白猪的数量为："<<num3<<endl;
		}
		
	}

void search_pigs(LinkList &L,int place,int number){
	LNode *p;
	p=L->next;
	bool flag=0;
	while(p!=NULL){
		if(p->places==place&&p->num==number){
			flag=1;
			cout<<"该猪猪的体重为："<<p->weigh<<endl;
			cout<<"该猪猪的成长天数为："<<p->days<<endl;
			break; 
		}
		p=p->next;
	}
	if(flag==0) cout<<"抱歉，该猪不存在"<<endl;
}

void initial_assign(LinkList &L,int b,int all){//初始化猪的猪圈和编号和体重 
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

void grow(LinkList &L,int n){//表示每日增加体重,并且判断是否超重 
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

void sell(LinkList &L){//判断猪是否达到出售的标准，若达到则删除节点，出售猪。 
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
	int weigh[3];//以10为区间长度，将20-50分为三个区间
	int days[8];//以50为区间长度将1-365分成八个区间 
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
		cout<<"抱歉，无法查找到该品种的猪"<<endl;
		return;
	}
	cout<<"该品种的猪的数量为："<<count<<endl;
	cout<<"体重在[20,30)之间的猪有："<<weigh[0]<<endl; 
	cout<<"体重在[30,40)之间的猪有："<<weigh[1]<<endl;
	cout<<"体重在[40,50]之间的猪有："<<weigh[2]<<endl; 
	cout<<"成长日期在[1,50)的猪有："<<days[0]<<endl;
	cout<<"成长日期在[50,100)的猪有："<<days[1]<<endl;
	cout<<"成长日期在[100,150)的猪有："<<days[2]<<endl;
	cout<<"成长日期在[150,200)的猪有："<<days[3]<<endl;
	cout<<"成长日期在[200,250)的猪有："<<days[4]<<endl;
	cout<<"成长日期在[250,300)的猪有："<<days[5]<<endl;
	cout<<"成长日期在[300,350)的猪有："<<days[6]<<endl;
	cout<<"成长日期在[350,365]的猪有："<<days[7]<<endl;
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
		cout << endl << "##########欢迎来到皓仔的养猪场！##########"; 
		cout << endl << "-----黑猪编码：1";
		cout << endl << "-----小花猪编码：2";
		cout << endl << "-----大花白猪编码：3"; 
		cout << endl << "1----------------初始化猪猪";
		cout << endl << "2----------------查询某一猪圈里的猪";
		cout << endl << "3----------------查询某一头猪";
		cout << endl << "4----------------购入猪猪";
		cout << endl << "5----------------查询某一品种的猪猪";
		cout << endl << "6----------------显示所有猪猪";
		cout << endl << "7----------------猪猪成长大法";
		cout << endl << "0----------------狠心离开猪猪";
		cout << endl << "请选择:";
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
			cout<<"想要查询的猪圈的编号：";
			cin>>spn;
			search_place(p,spn);
			break;
		
		case 3:
			cout<<"想要查询的猪的猪圈号：";
			cin>>exp;
			cout<<"想要查询的猪的编号：";
			cin>>exn;
			search_pigs(p,exp,exn);
			break;
		
		
		
		case 4:
			buy(p,bnum,total);
			break;
			
		case 5:
			cout<<"查询的猪的种类：";
			cin>>findsp;
			search_species(p,findsp);
			break;
		
		case 6: 
			print(p);
			cout<<"黑猪的数量为："<<black_count(p); 
			break;
		
		case 7:
			cout<<"猪猪接下来成长的天数为：";
			cin>> groday;
			grow(p,groday);
			sell(p);
			cout<<"在这段期的收益为："<<money;
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
