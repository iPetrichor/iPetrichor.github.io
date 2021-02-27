#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct player{
	int number;
	int age; 
	char name[25];
	char place[25];
}Player; 
 
typedef struct user{
	char name[25];
	int code;
	struct user * next;
}User; 

typedef User* uList;
 
typedef struct node{
	Player item;
	struct node * next; 
}Node;

typedef Node* List;


//函数定义部分：
void regis(void);
int login(char * temp,int n);
void makeMenu(void);
void makeuMenu(void);
void menuKey(int n);
void menuOne(void);
void menuTwo(void);
void menuThree(void);
void menuFour(void);
void menuFive(void); 
void menuSix(void);
void menuZero(void);
void read(void);
void write(void);


List head;
uList uhead;

void main()
{
	int SeqN,n,a=1,b;
	char temp[20];
	head=(List)malloc(sizeof(Node));
	head->next=NULL; 
	uhead=(uList)malloc(sizeof(User));
	uhead->next=NULL;
	
	while(a)
	{
		makeuMenu();
		scanf("%d",&b);
		if(b==1)	
		{	
			printf("请输入用户名：");
			scanf("%s",temp);
			printf("\n请输入密码：");
			scanf("%d",&n);
			a=login(temp,n);
		}
		else if(b==2)
		{
			
			
			
		}
	}
	system("cls");
	
	makeMenu();
	read();
	while(scanf("%d",&SeqN)==1)
	{ 
		menuKey(SeqN); 
		makeMenu();
	}
	
	return;
}


void regis(void)
{
	uList p,q;
	p=uhead->next;
	FILE * fp;
	char buf[20];
	
	fp=fopen("user.txt","a+");
	while(p!=NULL)
	{
		fprintf(fp,"%s\t%d\n",p->name,p->code);
		p=p->next;
	}
	
	fclose(fp);
	return;
}


int login(char * temp,int n)
{
	uList p,q;
	p=uhead->next;
	FILE * fp;
	int a,b,c;
	char buf[20];
	char ch;
	
	fp=fopen("user.txt","r");
	c=fscanf(fp,"%s\t%d\n",buf,b);
	while(c!=EOF)
	{
		a=strncmp(buf,temp,20);
		if(a==0)
		{
			if(n==b)
			{
				printf("登陆成功！（回车确认）");
				ch=getchar();
				while(ch=getchar()!='\n')
					continue;
				system("cls");
				fclose(fp);
				return 0;	
			}
			else
				break;
		}
		fscanf(fp,"%s\t%d\n",buf,b);
	}
	printf("密码错误或不存在此用户。（回车确认）");
	ch=getchar();
	while(ch=getchar()!='\n')
		continue;
	system("cls");
	fclose(fp);
	return 1;	
}


void makeuMenu(void)
{
	printf("*************\n");
	printf("1.登录\n");
	printf("2.注册\n");
	printf("0.退出\n");
	printf("*************\n");
	printf("请输入0~2：");	
	return;
}


void makeMenu(void)
{
	printf("----------------------------------------------------\n");
	printf("\t1.显示全部球员信息\n"); 
	printf("\t2.球员排行榜\n");
	printf("\t3.查询球员信息\n");
	printf("\t4.修改球员信息\n");
	printf("\t5.删除球员信息\n");
	printf("\t6.增加新球员\n");
	printf("\t7.暂未推出！\n");
	printf("\t8.暂未推出！\n");
	printf("\t9.暂未推出！\n");
	printf("\t0.保存并退出系统");
	printf("\n----------------------------------------------------\n");
	printf("请输入0~9：");
	return;
}


void menuKey(int n)
{
	switch(n)
	{
		case 1:
			menuOne();
			return;
		case 2:
			menuTwo();
			return;
		case 3:
			menuThree();
			return;
		case 4:
			menuFour();
			return;
		case 5:
			menuFive();
			return;
		case 6:
			menuSix();
			while(getchar()!='\n')
				continue;
			return;
		case 0:
			menuZero();
			return;
		default:
			while(getchar()!='\n')
				continue;
			return;
	}
}


void menuOne(void)
{
	List current;
	current=head->next;
	char ch;
	
	char a[10];//确认与返回。 
	system("cls");
	printf("确定要显示全部球员信息吗？(Y/N)");
	scanf("%s",a);
	if(a[0]!='Y'&&a[0]!='y')
	{
		system("cls");
 		return;
	}
	if(a[0]=='Y'||a[0]=='y')
	{	
		if(current==NULL)//每个功能确认后显示的不一样。 
		{
			system("cls");
			printf("还未录入球员信息！（回车确认）");
			ch=getchar();
			while(ch=getchar()!='\n')
				continue;
			system("cls");
			return;
		}
		printf("--------------------------------------------------------------------------------\n");
		printf("姓名\t\t\t号码\t  年龄\t    位置\n");
		while(current!=NULL)
		{
			printf("%-25s%-10d%-10d%-10s\n",current->item.name,current->item.number,
			current->item.age,current->item.place);
			current=current->next;
		}
		printf("(按回车返回)");
		printf("\n--------------------------------------------------------------------------------");
		ch=getchar();
		while(ch=getchar()!='\n')
			continue;
		system("cls");
		return;
	} 		
}  


void menuTwo(void)//排序 
{
	List p,q;
	Node temp;
	int a,b,c;
	char ch;	
	char buf[25];
	
	system("cls");
	printf("*************\n");
	printf("1.按号码排行\n");
	printf("2.按年龄排行\n");
	printf("0.返回\n");
	printf("*************\n");
	printf("请输入0~2：");
	scanf("%d",&a);
	system("cls");
	if(a==1)
	{
		for(p=head->next;p!=NULL;p=p->next)
		{
			for(q=head->next;q->next!=NULL;q=q->next)
			{
				if((q->item.number) > (q->next->item.number))
				{
					temp.item=q->next->item;
					q->next->item=q->item;
					q->item=temp.item;
				}	
			}
		}
		printf("排序成功！(按回车返回)"); 
		ch=getchar();
		while(ch=getchar()!='\n')
			continue;
		system("cls");
		return;		
	}	
	else if(a==2)
	{
		for(p=head->next;p!=NULL;p=p->next)
		{
			for(q=head->next;q->next!=NULL;q=q->next)
			{
				if((q->item.age) > (q->next->item.age))
				{
					temp.item=q->next->item;
					q->next->item=q->item;
					q->item=temp.item;
				}	
			}
		}
		printf("排序成功！(按回车返回)"); 
		ch=getchar();
		while(ch=getchar()!='\n')
			continue;
		system("cls");
		return;	
	}
	else
	{
		system("cls");
		return;
	}
}



void menuThree(void)
{
	List current;
	current=head->next;
	int a,b,c;
	char ch;	
	char buf[25];
	
	system("cls");
	printf("*************\n");
	printf("1.按名字查询\n");
	printf("2.按号码查询\n");
	printf("0.返回\n");
	printf("*************\n");
	printf("请输入0~2：");
	scanf("%d",&a);
	system("cls");
	if(a==1)
	{
		printf("请输入要查询的球员名：");
		scanf("%s",buf);
		while(current!=NULL)
		{
			b=strncmp(buf,current->item.name,25);	
			if(b==0)
			{
				printf("--------------------------------------------------------------------------------\n");
				printf("姓名\t\t\t号码\t  年龄\t    位置\n");
				printf("%-25s%-10d%-10d%-10s\n",current->item.name,current->item.number,
				current->item.age,current->item.place);
				printf("(按回车返回)");
				printf("\n--------------------------------------------------------------------------------");
				ch=getchar();
				while(ch=getchar()!='\n')
					continue;
				system("cls");
				return;
			}
			current=current->next;
		}
		printf("查无此人！(按回车返回)"); 
		ch=getchar();
		while(ch=getchar()!='\n')
			continue;
		system("cls");
		return;
	}
	else if(a==2)
	{
		printf("请输入要查询的球员号：");
		scanf("%d",&c);
		while(current!=NULL)
		{
			b=current->item.number;
			if(b==c)
			{
				printf("--------------------------------------------------------------------------------\n");
				printf("姓名\t\t\t号码\t  年龄\t    位置\n");
				printf("%-25s%-10d%-10d%-10s\n",current->item.name,current->item.number,
				current->item.age,current->item.place);
				printf("(按回车返回)");
				printf("\n--------------------------------------------------------------------------------");
				ch=getchar();
				while(ch=getchar()!='\n')
					continue;
				system("cls");
				return;
			}
			current=current->next;
		}
		printf("查无此人！(按回车返回)"); 
		ch=getchar();
		while(ch=getchar()!='\n')
			continue;
		system("cls");
		return;
	}
	else
	{
		system("cls");
		return;
	}
	
}

void menuFour(void)//改 
{
	List current=head->next;
	int a,b,c ;
	char buf[25];
	char ch;
	 
	printf("请输入要修改信息的球员：");
	scanf("%s",buf);
	while(current!=NULL)
	{
		b=strncmp(buf,current->item.name,25);	
		if(b==0)
		{
			printf("*************\n");
			printf("1.修改号码\n");
			printf("2.修改年龄\n");
			printf("3.修改位置\n");
			printf("0.返回\n");
			printf("*************\n");
			printf("请输入0~3：");
			scanf("%d",&a);
			if(a==1)
			{
				printf("将其改为：");
				scanf("%d",&c);
				current->item.number=c;
				printf("修改成功！");
			}
			else if(a==2)
			{
				printf("将其改为：");
				scanf("%d",&c);
				current->item.age=c;
				printf("修改成功！");
			}
			else if(a==3)
			{
				printf("将其改为：");
				scanf("%s",buf);
				strcpy(current->item.place,buf);
				printf("修改成功！");
			}
			else
			{
				system("cls");
				return;
			}
			ch=getchar();
			while(ch=getchar()!='\n')
				continue;
			system("cls");
			return;
		}
		current=current->next;
	}
	printf("查无此人！(按回车返回)"); 
	ch=getchar();
	while(ch=getchar()!='\n')
		continue;
	system("cls");
	return;
}

void menuFive(void)//删 
{
	List current=head->next;
	List prev=head;
	int b;
	char buf[25];
	char ch;
	
	printf("请输入要删除的球员：");
		scanf("%s",buf);
		while(current!=NULL)
		{
			b=strncmp(buf,current->item.name,25);
			if(b==0)
			{
				prev->next=current->next;
				free(current);
				printf("删除成功！(按回车返回)");
				ch=getchar();
				while(ch=getchar()!='\n')
					continue;
				system("cls");
				return;
			}
			current=current->next;
			prev=prev->next;
		}
	printf("查无此人！(按回车返回)"); 
	ch=getchar();
	while(ch=getchar()!='\n')
		continue;
	system("cls");
	return;
}

void menuSix(void)
{
	List current,prev;
	current=head;
	FILE * fp;
	
	char a[10];//确认与返回。 
	system("cls");
	printf("确定要增加新球员吗？(Y/N)");
	scanf("%s",a);
	if(a[0]!='Y'&&a[0]!='y')
	{
		system("cls");
 		return;
	}
	if(a[0]=='Y'||a[0]=='y')
	{	
		while(current->next!=NULL)
			current=current->next;
		prev=current;
		current=(List)malloc(sizeof(Node));
		prev->next=current;
		current->next=NULL;
		printf("请输入新球员信息（姓名 号码 年龄 位置 ）:");
		scanf("%s%d%d%s",&current->item.name,&current->item.number,&current->item.age,
		current->item.place);
		system("cls");
		return;
	}	
}


void menuZero(void)
{
	char ch;
	
	char a[10];//确认与返回。 
	system("cls");
	printf("确定要退出吗？(Y/N)");
	scanf("%s",a);
	if(a[0]!='Y'&&a[0]!='y')
	{
		system("cls");
 		return;
	}
	if(a[0]=='Y'||a[0]=='y') 
	{
		write();
		exit(1);
	}
}


void read(void)
{
	FILE * fp;
	List current,prev;
	int a;
	prev=head;
	
	fp=fopen("data.txt","r");
	if(fp==NULL)
	{
		fp=fopen("data.txt","w");//如果文件不存在，则新建一个。 
	}
	current=(List)malloc(sizeof(Node));
	current->next=NULL;
	while(a=fscanf(fp,"%s\t%d\t%d\t%s\t",current->item.name,&current->item.number,&current->item.age,
		current->item.place)!=EOF)
	{
		prev->next=current;
		prev=current;
		current=(List)malloc(sizeof(Node));
		current->next=NULL;
	}
	free(current);
	fclose(fp);
	return;
}


void write(void)
{
	FILE * fp;
	List current=head->next;
	
	fp=fopen("data.txt","w");
	while(current!=NULL)
	{
		fprintf(fp,"%s\t%d\t%d\t%s\t",current->item.name,current->item.number,current->item.age,
		current->item.place);
		current=current->next;
	}
	fclose(fp);
	return;		
}
